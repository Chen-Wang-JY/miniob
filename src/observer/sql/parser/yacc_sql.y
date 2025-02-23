
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"

using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}

%}

%define api.pure full
%define parse.error verbose
/** 启用位置标识 **/
%locations
%lex-param { yyscan_t scanner }
/** 这些定义了在yyparse函数中的参数 **/
%parse-param { const char * sql_string }
%parse-param { ParsedSqlResult * sql_result }
%parse-param { void * scanner }

//标识tokens
%token  SEMICOLON
        CREATE
        DROP
        INNER
        TABLE
        TABLES
        UNIQUE
        INDEX
        CALC
        SELECT
        DESC
        ASC
        ORDER
        BY
        SHOW
        SYNC
        INSERT
        DELETE
        UPDATE
        LBRACE
        RBRACE
        COMMA
        TRX_BEGIN
        TRX_COMMIT
        TRX_ROLLBACK
        INT_T
        STRING_T
        FLOAT_T
        DATE_T
        HELP
        EXIT
        DOT //QUOTE
        INTO
        VALUES
        FROM
        WHERE
        AND
        SET
        MAX
        MIN
        COUNT
        AVG
        SUM
        ON
        LOAD
        DATA
        INFILE
        EXPLAIN
        EQ
        LT
        GT
        LE
        GE
        LKE
        NOT
        NE
        IS
        TNULL
        

/** union 中定义各种数据类型，真实生成的代码也是union类型，所以不能有非POD类型的数据 **/
%union {
  ParsedSqlNode *                   sql_node;
  ConditionSqlNode *                condition;
  JoinSqlNode *                     join_sql_node;
  Value *                           value;
  enum CompOp                       comp;
  enum OrderOp                      orderOp;
  enum AggrOp                       aggr;
  RelAttrSqlNode *                  rel_attr;
  std::vector<AttrInfoSqlNode> *    attr_infos;
  AttrInfoSqlNode *                 attr_info;
  Expression *                      expression;
  std::vector<Expression *> *       expression_list;
  std::vector<Value> *              value_list;
  std::vector<ConditionSqlNode> *   condition_list;
  std::vector<UpdateValueSqlNode> *      update_value_list;
  UpdateValueSqlNode*                    update_value;
  std::vector<RelAttrSqlNode> *     rel_attr_list;
  std::vector<std::pair<RelAttrSqlNode, OrderOp>>* order_by_list;
  std::vector<std::string> *        relation_list;
  char *                            string;
  int                               number;
  float                             floats;
  bool                              boolean;
}

%token <number> NUMBER
%token <floats> FLOAT
%token <string> ID
%token <string> DATE_STR
%token <string> SSS
%token <string> JOIN
//非终结符

/** type 定义了各种解析后的结果输出的是什么类型。类型对应了 union 中的定义的成员变量名称 **/
%type <boolean>             isnull
%type <number>              type
%type <condition>           condition
%type <value>               value
%type <number>              number
%type <comp>                comp_op
%type <aggr>                aggr_op
%type <orderOp>             order_op
%type <order_by_list>       order_by_list
%type <order_by_list>       order_by
%type <update_value_list>   update_value_list
%type <update_value>        update_value
%type <rel_attr>            rel_attr
%type <rel_attr>            aggr_attr
%type <rel_attr>            rel_aggr_attr
%type <rel_attr>            rel_attr_wildcard
%type <attr_infos>          attr_def_list
%type <attr_info>           attr_def
%type <value_list>          value_list
%type <condition_list>      where
%type <join_sql_node>       join_list
%type <condition_list>      condition_list
%type <rel_attr_list>       select_attr
%type <relation_list>       rel_list
%type <rel_attr_list>       rel_attr_wildcard_list
%type <rel_attr_list>       rel_aggr_attr_list
%type <expression>          expression
%type <expression_list>     expression_list
%type <sql_node>            calc_stmt
%type <sql_node>            select_stmt
%type <sql_node>            insert_stmt
%type <sql_node>            update_stmt
%type <sql_node>            delete_stmt
%type <sql_node>            create_table_stmt
%type <sql_node>            drop_table_stmt
%type <sql_node>            show_tables_stmt
%type <sql_node>            desc_table_stmt
%type <sql_node>            create_index_stmt
%type <sql_node>            drop_index_stmt
%type <sql_node>            sync_stmt
%type <sql_node>            begin_stmt
%type <sql_node>            commit_stmt
%type <sql_node>            rollback_stmt
%type <sql_node>            load_data_stmt
%type <sql_node>            explain_stmt
%type <sql_node>            set_variable_stmt
%type <sql_node>            help_stmt
%type <sql_node>            exit_stmt
%type <sql_node>            command_wrapper
// commands should be a list but I use a single command instead
%type <sql_node>            commands

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%%

commands: command_wrapper opt_semicolon  //commands or sqls. parser starts here.
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>($1);
    sql_result->add_sql_node(std::move(sql_node));
  }
  ;

command_wrapper:
    calc_stmt
  | select_stmt
  | insert_stmt
  | update_stmt
  | delete_stmt
  | create_table_stmt
  | drop_table_stmt
  | show_tables_stmt
  | desc_table_stmt
  | create_index_stmt
  | drop_index_stmt
  | sync_stmt
  | begin_stmt
  | commit_stmt
  | rollback_stmt
  | load_data_stmt
  | explain_stmt
  | set_variable_stmt
  | help_stmt
  | exit_stmt
    ;

exit_stmt:      
    EXIT {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      $$ = new ParsedSqlNode(SCF_EXIT);
    };

help_stmt:
    HELP {
      $$ = new ParsedSqlNode(SCF_HELP);
    };

sync_stmt:
    SYNC {
      $$ = new ParsedSqlNode(SCF_SYNC);
    }
    ;

begin_stmt:
    TRX_BEGIN  {
      $$ = new ParsedSqlNode(SCF_BEGIN);
    }
    ;

commit_stmt:
    TRX_COMMIT {
      $$ = new ParsedSqlNode(SCF_COMMIT);
    }
    ;

rollback_stmt:
    TRX_ROLLBACK  {
      $$ = new ParsedSqlNode(SCF_ROLLBACK);
    }
    ;

drop_table_stmt:    /*drop table 语句的语法解析树*/
    DROP TABLE ID {
      $$ = new ParsedSqlNode(SCF_DROP_TABLE);
      $$->drop_table.relation_name = $3;
      free($3);
    };

show_tables_stmt:
    SHOW TABLES {
      $$ = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
    ;

desc_table_stmt:
    DESC ID  {
      $$ = new ParsedSqlNode(SCF_DESC_TABLE);
      $$->desc_table.relation_name = $2;
      free($2);
    }
    ;

create_index_stmt:    /*create index 语句的语法解析树*/
    CREATE INDEX ID ON ID LBRACE ID rel_list RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = $$->create_index;
      create_index.index_name = $3;
      create_index.relation_name = $5;
      if ($8 != nullptr) {
        create_index.attribute_names.swap(*$8);
      }
      create_index.attribute_names.emplace_back($7);

      create_index.unique = false;
      free($3);
      free($5);
      free($7);
    }
    | CREATE UNIQUE INDEX ID ON ID LBRACE ID rel_list RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = $$->create_index;
      create_index.index_name = $4;
      create_index.relation_name = $6;
      // create_index.attribute_name = $8;
      if ($9 != nullptr){
        create_index.attribute_names.swap(*$9);
      }
      create_index.attribute_names.emplace_back($8);
      create_index.unique = true;
      free($4);
      free($6);
      free($8);
    }
    ;

drop_index_stmt:      /*drop index 语句的语法解析树*/
    DROP INDEX ID ON ID
    {
      $$ = new ParsedSqlNode(SCF_DROP_INDEX);
      $$->drop_index.index_name = $3;
      $$->drop_index.relation_name = $5;
      free($3);
      free($5);
    }
    ;

create_table_stmt:    /*create table 语句的语法解析树*/
    CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_TABLE);

      CreateTableSqlNode &create_table = $$->create_table;
      create_table.relation_name = $3;
      free($3);

      std::vector<AttrInfoSqlNode> *src_attrs = $6;

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*$5);
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete $5;

      /**
       * 在resolve阶段，ParsedSqlNode是const类型，无法在resolve阶段添加新的field。
       * 因此在Parse阶段添加bitmap field
       */
      AttrInfoSqlNode null_field;
      null_field.type = INTS;
      null_field.name = NULL_FIELD_NAME;
      null_field.length = 4;
      null_field.isnull = false;
      create_table.attr_infos.push_back(null_field);

    }
    ;

attr_def_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA attr_def attr_def_list
    {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<AttrInfoSqlNode>;
      }
      $$->emplace_back(*$2);
      delete $2;
    }
    ;

    
attr_def:
    ID type LBRACE number RBRACE isnull
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      $$->length = $4;
      $$->isnull = $6;
      free($1);
    }
    | ID type isnull
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      $$->isnull = $3;
      $$->length = 4;
      free($1);
    }
    ;
isnull:
    {
      /* empty */
      $$ = false;
    }
    | NOT TNULL
    {
      $$ = false;
    }
    | TNULL
    {
      $$ = true;
    }
    ;
number:
    NUMBER {$$ = $1;}
    ;
type:
    INT_T      { $$=INTS; }
    | STRING_T { $$=CHARS; }
    | FLOAT_T  { $$=FLOATS; }
    | DATE_T   { $$=DATES; }
    ;
insert_stmt:        /*insert   语句的语法解析树*/
    INSERT INTO ID VALUES LBRACE value value_list RBRACE 
    {
      $$ = new ParsedSqlNode(SCF_INSERT);
      $$->insertion.relation_name = $3;
      if ($7 != nullptr) {
        $$->insertion.values.swap(*$7);
      }
      $$->insertion.values.emplace_back(*$6);
      std::reverse($$->insertion.values.begin(), $$->insertion.values.end());
      delete $6;
      free($3);
    }
    ;

value_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA value value_list  { 
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<Value>;
      }
      $$->emplace_back(*$2);
      delete $2;
    }
    ;
    
value:
    NUMBER {
      $$ = new Value((int)$1);
      @$ = @1;
    }
    |FLOAT {
      $$ = new Value((float)$1);
      @$ = @1;
    }
    |TNULL {
      $$ = new Value(NULL_VALUE, 1);
    }
    |DATE_STR {
      char* tmp = common::substr($1, 1, strlen($1) - 2);
      $$ = new Value(tmp, strlen(tmp), 1);
      free(tmp);
    }
    |SSS {
      char *tmp = common::substr($1,1,strlen($1)-2);
      $$ = new Value(tmp);
      free(tmp);
    }
    ;
    
delete_stmt:    /*  delete 语句的语法解析树*/
    DELETE FROM ID where 
    {
      $$ = new ParsedSqlNode(SCF_DELETE);
      $$->deletion.relation_name = $3;
      if ($4 != nullptr) {
        $$->deletion.conditions.swap(*$4);
        delete $4;
      }
      free($3);
    }
    ;
update_stmt:      /*  update 语句的语法解析树*/
    UPDATE ID SET update_value_list where 
    {
      $$ = new ParsedSqlNode(SCF_UPDATE);
      $$->update.relation_name = $2;

      for (auto node: *$4) {
        $$->update.attribute_names.push_back(node.attribute_name);
        $$->update.values.push_back(node.value);
      }
      // for (int i = 0; i < $4->size(); i++)
      // {
      //   $$->update.attribute_names.push_back((($4)[i]).attribute_name);
      //   $$->update.values.push_back((($4)[i]).value);
      // }

      if ($5 != nullptr) {
        $$->update.conditions.swap(*$5);
        delete $5;
      }
      free($2);
      //free($4);
    }
    ;
  
update_value:
  ID EQ value
  {
    $$ = new UpdateValueSqlNode;
    $$->attribute_name = $1;
    $$->value = *$3;
  }
  ;

update_value_list:
  /* empty */
  {
    $$ = nullptr;
  }
  | update_value 
  {
      $$ = new std::vector<UpdateValueSqlNode>;
      $$->emplace_back(*$1);
      delete $1;
  }
  | update_value COMMA update_value_list 
  {
    $$ = $3;
    $$->emplace_back(*$1);
    delete $1;
  }
  ; 



select_stmt:        /*  select 语句的语法解析树*/
    SELECT select_attr FROM ID rel_list join_list where order_by
    {
      $$ = new ParsedSqlNode(SCF_SELECT);
      if ($2 != nullptr) {
        $$->selection.attributes.swap(*$2);
        delete $2;
      }
      if ($5 != nullptr) {
        $$->selection.relations.swap(*$5);
        delete $5;
      }
      $$->selection.relations.push_back($4);
      std::reverse($$->selection.relations.begin(), $$->selection.relations.end());

      if ($7 != nullptr) {
        $$->selection.conditions.swap(*$7);
        delete $7;
      }
      free($4);

      if ($6 != nullptr) {
        $$->selection.relations.insert($$->selection.relations.end(), $6->relations.begin(), $6->relations.end());
        $$->selection.conditions.insert($$->selection.conditions.end(), $6->conditions.begin(), $6->conditions.end());
        delete $6;
      }

      if ($8 != nullptr) {
        $$->selection.order_rules.swap(*$8);
        delete $8;
      }
    }
    ;

calc_stmt:
    CALC expression_list
    {
      $$ = new ParsedSqlNode(SCF_CALC);
      std::reverse($2->begin(), $2->end());
      $$->calc.expressions.swap(*$2);
      delete $2;
    }
    ;

expression_list:
    expression
    {
      $$ = new std::vector<Expression*>;
      $$->emplace_back($1);
    }
    | expression COMMA expression_list
    {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<Expression *>;
      }
      $$->emplace_back($1);
    }
    ;
expression:
    expression '+' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $3, sql_string, &@$);
    }
    | expression '-' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $3, sql_string, &@$);
    }
    | expression '*' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $3, sql_string, &@$);
    }
    | expression '/' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $3, sql_string, &@$);
    }
    | LBRACE expression RBRACE {
      $$ = $2;
      $$->set_name(token_name(sql_string, &@$));
    }
    | '-' expression %prec UMINUS {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, $2, nullptr, sql_string, &@$);
    }
    | value {
      $$ = new ValueExpr(*$1);
      $$->set_name(token_name(sql_string, &@$));
      delete $1;
    }
    ;

select_attr:
    '*' {
      $$ = new std::vector<RelAttrSqlNode>;
      RelAttrSqlNode attr;
      attr.relation_name  = "";
      attr.attribute_name = "*";
      $$->emplace_back(attr);
    }
    | rel_aggr_attr rel_aggr_attr_list {
      if ($2 != nullptr) {
        $$ = $2;
      } else {
        $$ = new std::vector<RelAttrSqlNode>;
      }
      $$->emplace_back(*$1);
      delete $1;
    }
    ;

aggr_attr:
    aggr_op LBRACE rel_attr_wildcard rel_attr_wildcard_list RBRACE {
      $$ = $3;
      $$->aggregation = $1;
      // redundant columns
      if ($4 != nullptr) {
        $$->valid = false;
        delete $4;
      }
    }
    | aggr_op LBRACE RBRACE {
      $$ = new RelAttrSqlNode;
      $$->relation_name = "";
      $$->attribute_name = "";
      $$->aggregation = $1;
      // empty columns
      $$->valid = false;
    }
    ;

aggr_op:
      MAX { $$ = AGGR_MAX; }
    | MIN { $$ = AGGR_MIN; }
    | COUNT { $$ = AGGR_COUNT; }
    | AVG { $$ = AGGR_AVG; }
    | SUM { $$ = AGGR_SUM; }
    ;

rel_aggr_attr:
    rel_attr
    | aggr_attr
    ;

rel_aggr_attr_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA rel_aggr_attr rel_aggr_attr_list {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<RelAttrSqlNode>;
      }

      $$->emplace_back(*$2);
      delete $2;
    }
    ;

rel_attr_wildcard:
    '*' {
      $$ = new RelAttrSqlNode;
      $$->relation_name = "";
      $$->attribute_name = "*";
    }
    | rel_attr
    ;

rel_attr_wildcard_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA rel_attr_wildcard rel_attr_wildcard_list {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<RelAttrSqlNode>;
      }

      $$->emplace_back(*$2);
      delete $2;
    }
    ;

rel_attr:
    ID {
      $$ = new RelAttrSqlNode;
      $$->attribute_name = $1;
      free($1);
    }
    | ID DOT ID {
      $$ = new RelAttrSqlNode;
      $$->relation_name  = $1;
      $$->attribute_name = $3;
      free($1);
      free($3);
    }
    ;

rel_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA ID rel_list {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<std::string>;
      }

      $$->push_back($2);
      free($2);
    }
    ;

join_list:
    {
      $$ = nullptr;
    }
    | INNER join_list 
    {
      $$ = $2;
    }
    | JOIN ID ON condition_list join_list 
    {
      $$ = new JoinSqlNode();

      if ($4 != nullptr) {
        $$->conditions.swap(*$4);
        delete $4;
      }

      $$->relations.push_back($2);
      // $$->conditions.push_back(*$4);
      free($2);

      if ($5 != nullptr) {
        $$->relations.insert($$->relations.end(), $5->relations.begin(), $5->relations.end());
        $$->conditions.insert($$->conditions.end(), $5->conditions.begin(), $5->conditions.end());
        delete $5;
      }
    }
where:
    /* empty */
    {
      $$ = nullptr;
    }
    | WHERE condition_list {
      $$ = $2;  
    }
    ;
condition_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | condition {
      $$ = new std::vector<ConditionSqlNode>;
      $$->emplace_back(*$1);
      delete $1;
    }
    | condition AND condition_list {
      $$ = $3;
      $$->emplace_back(*$1);
      delete $1;
    }
    ;
condition:
    rel_attr comp_op value
    {
      $$ = new ConditionSqlNode;
      $$->left_is_attr = 1;
      $$->left_attr = *$1;
      $$->right_is_attr = 0;
      $$->right_value = *$3;
      $$->comp = $2;

      delete $1;
      delete $3;
    }
    | value comp_op value 
    {
      $$ = new ConditionSqlNode;
      $$->left_is_attr = 0;
      $$->left_value = *$1;
      $$->right_is_attr = 0;
      $$->right_value = *$3;
      $$->comp = $2;

      delete $1;
      delete $3;
    }
    | rel_attr comp_op rel_attr
    {
      $$ = new ConditionSqlNode;
      $$->left_is_attr = 1;
      $$->left_attr = *$1;
      $$->right_is_attr = 1;
      $$->right_attr = *$3;
      $$->comp = $2;

      delete $1;
      delete $3;
    }
    | value comp_op rel_attr
    {
      $$ = new ConditionSqlNode;
      $$->left_is_attr = 0;
      $$->left_value = *$1;
      $$->right_is_attr = 1;
      $$->right_attr = *$3;
      $$->comp = $2;

      delete $1;
      delete $3;
    }
    ;

order_by:
  {
    $$ = nullptr;
  }
  | ORDER BY rel_attr order_op order_by_list
  {
    $$ = new std::vector<std::pair<RelAttrSqlNode, OrderOp>>;
    $$->emplace_back(std::make_pair(*$3, $4));
    delete $3;
    if ($5 != nullptr) {
      $$->insert($$->end(), $5->begin(), $5->end());
    }
  }
  ;

order_by_list:
  {
    $$ = nullptr;
  }
  | COMMA rel_attr order_op order_by_list
  {
    $$ = new std::vector<std::pair<RelAttrSqlNode, OrderOp>>;
    $$->emplace_back(std::make_pair(*$2, $3));
    delete $2;

    if ($4 != nullptr) {
      $$->insert($$->end(), $4->begin(), $4->end());
    }
  }
  ;

comp_op:
      EQ { $$ = EQUAL_TO; }
    | LT { $$ = LESS_THAN; }
    | GT { $$ = GREAT_THAN; }
    | LE { $$ = LESS_EQUAL; }
    | GE { $$ = GREAT_EQUAL; }
    | NE { $$ = NOT_EQUAL; }
    | NOT LKE { $$ = NOT_LIKE; }
    | LKE { $$ = LIKE; }
    | IS { $$ = OP_ISNULL; }
    | IS NOT { $$ = OP_ISNOTNULL; }
    ;

order_op:
    DESC { $$ = ORDER_DESC; }
  | ASC  { $$ = ORDER_ASC;  }
  |      { $$ = ORDER_DEFAULT; }
  ;

load_data_stmt:
    LOAD DATA INFILE SSS INTO TABLE ID 
    {
      char *tmp_file_name = common::substr($4, 1, strlen($4) - 2);
      
      $$ = new ParsedSqlNode(SCF_LOAD_DATA);
      $$->load_data.relation_name = $7;
      $$->load_data.file_name = tmp_file_name;
      free($7);
      free(tmp_file_name);
    }
    ;

explain_stmt:
    EXPLAIN command_wrapper
    {
      $$ = new ParsedSqlNode(SCF_EXPLAIN);
      $$->explain.sql_node = std::unique_ptr<ParsedSqlNode>($2);
    }
    ;

set_variable_stmt:
    SET ID EQ value
    {
      $$ = new ParsedSqlNode(SCF_SET_VARIABLE);
      $$->set_variable.name  = $2;
      $$->set_variable.value = *$4;
      free($2);
      delete $4;
    }
    ;

opt_semicolon: /*empty*/
    | SEMICOLON
    ;
%%
//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
