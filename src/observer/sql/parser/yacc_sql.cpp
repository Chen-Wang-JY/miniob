/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


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


#line 115 "yacc_sql.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 4,                     /* CREATE  */
  YYSYMBOL_DROP = 5,                       /* DROP  */
  YYSYMBOL_INNER = 6,                      /* INNER  */
  YYSYMBOL_TABLE = 7,                      /* TABLE  */
  YYSYMBOL_TABLES = 8,                     /* TABLES  */
  YYSYMBOL_UNIQUE = 9,                     /* UNIQUE  */
  YYSYMBOL_INDEX = 10,                     /* INDEX  */
  YYSYMBOL_CALC = 11,                      /* CALC  */
  YYSYMBOL_SELECT = 12,                    /* SELECT  */
  YYSYMBOL_DESC = 13,                      /* DESC  */
  YYSYMBOL_ASC = 14,                       /* ASC  */
  YYSYMBOL_ORDER = 15,                     /* ORDER  */
  YYSYMBOL_BY = 16,                        /* BY  */
  YYSYMBOL_SHOW = 17,                      /* SHOW  */
  YYSYMBOL_SYNC = 18,                      /* SYNC  */
  YYSYMBOL_INSERT = 19,                    /* INSERT  */
  YYSYMBOL_DELETE = 20,                    /* DELETE  */
  YYSYMBOL_UPDATE = 21,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 22,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 23,                    /* RBRACE  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 25,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 26,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 27,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 28,                     /* INT_T  */
  YYSYMBOL_STRING_T = 29,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 30,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 31,                    /* DATE_T  */
  YYSYMBOL_HELP = 32,                      /* HELP  */
  YYSYMBOL_EXIT = 33,                      /* EXIT  */
  YYSYMBOL_DOT = 34,                       /* DOT  */
  YYSYMBOL_INTO = 35,                      /* INTO  */
  YYSYMBOL_VALUES = 36,                    /* VALUES  */
  YYSYMBOL_FROM = 37,                      /* FROM  */
  YYSYMBOL_WHERE = 38,                     /* WHERE  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_SET = 40,                       /* SET  */
  YYSYMBOL_MAX = 41,                       /* MAX  */
  YYSYMBOL_MIN = 42,                       /* MIN  */
  YYSYMBOL_COUNT = 43,                     /* COUNT  */
  YYSYMBOL_AVG = 44,                       /* AVG  */
  YYSYMBOL_SUM = 45,                       /* SUM  */
  YYSYMBOL_ON = 46,                        /* ON  */
  YYSYMBOL_LOAD = 47,                      /* LOAD  */
  YYSYMBOL_DATA = 48,                      /* DATA  */
  YYSYMBOL_INFILE = 49,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 50,                   /* EXPLAIN  */
  YYSYMBOL_EQ = 51,                        /* EQ  */
  YYSYMBOL_LT = 52,                        /* LT  */
  YYSYMBOL_GT = 53,                        /* GT  */
  YYSYMBOL_LE = 54,                        /* LE  */
  YYSYMBOL_GE = 55,                        /* GE  */
  YYSYMBOL_LKE = 56,                       /* LKE  */
  YYSYMBOL_NOT = 57,                       /* NOT  */
  YYSYMBOL_NE = 58,                        /* NE  */
  YYSYMBOL_IS = 59,                        /* IS  */
  YYSYMBOL_TNULL = 60,                     /* TNULL  */
  YYSYMBOL_NUMBER = 61,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 62,                     /* FLOAT  */
  YYSYMBOL_ID = 63,                        /* ID  */
  YYSYMBOL_DATE_STR = 64,                  /* DATE_STR  */
  YYSYMBOL_SSS = 65,                       /* SSS  */
  YYSYMBOL_JOIN = 66,                      /* JOIN  */
  YYSYMBOL_67_ = 67,                       /* '+'  */
  YYSYMBOL_68_ = 68,                       /* '-'  */
  YYSYMBOL_69_ = 69,                       /* '*'  */
  YYSYMBOL_70_ = 70,                       /* '/'  */
  YYSYMBOL_UMINUS = 71,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 72,                  /* $accept  */
  YYSYMBOL_commands = 73,                  /* commands  */
  YYSYMBOL_command_wrapper = 74,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 75,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 76,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 77,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 78,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 79,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 80,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 81,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 82,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 83,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 84,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 85,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 86,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 87,             /* attr_def_list  */
  YYSYMBOL_attr_def = 88,                  /* attr_def  */
  YYSYMBOL_isnull = 89,                    /* isnull  */
  YYSYMBOL_number = 90,                    /* number  */
  YYSYMBOL_type = 91,                      /* type  */
  YYSYMBOL_insert_stmt = 92,               /* insert_stmt  */
  YYSYMBOL_value_list = 93,                /* value_list  */
  YYSYMBOL_value = 94,                     /* value  */
  YYSYMBOL_delete_stmt = 95,               /* delete_stmt  */
  YYSYMBOL_update_stmt = 96,               /* update_stmt  */
  YYSYMBOL_update_value = 97,              /* update_value  */
  YYSYMBOL_update_value_list = 98,         /* update_value_list  */
  YYSYMBOL_select_stmt = 99,               /* select_stmt  */
  YYSYMBOL_calc_stmt = 100,                /* calc_stmt  */
  YYSYMBOL_expression_list = 101,          /* expression_list  */
  YYSYMBOL_expression = 102,               /* expression  */
  YYSYMBOL_select_attr = 103,              /* select_attr  */
  YYSYMBOL_aggr_attr = 104,                /* aggr_attr  */
  YYSYMBOL_aggr_op = 105,                  /* aggr_op  */
  YYSYMBOL_rel_aggr_attr = 106,            /* rel_aggr_attr  */
  YYSYMBOL_rel_aggr_attr_list = 107,       /* rel_aggr_attr_list  */
  YYSYMBOL_rel_attr_wildcard = 108,        /* rel_attr_wildcard  */
  YYSYMBOL_rel_attr_wildcard_list = 109,   /* rel_attr_wildcard_list  */
  YYSYMBOL_rel_attr = 110,                 /* rel_attr  */
  YYSYMBOL_rel_list = 111,                 /* rel_list  */
  YYSYMBOL_join_list = 112,                /* join_list  */
  YYSYMBOL_where = 113,                    /* where  */
  YYSYMBOL_condition_list = 114,           /* condition_list  */
  YYSYMBOL_condition = 115,                /* condition  */
  YYSYMBOL_order_by = 116,                 /* order_by  */
  YYSYMBOL_order_by_list = 117,            /* order_by_list  */
  YYSYMBOL_comp_op = 118,                  /* comp_op  */
  YYSYMBOL_order_op = 119,                 /* order_op  */
  YYSYMBOL_load_data_stmt = 120,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 121,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 122,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 123             /* opt_semicolon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   322


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    69,    67,     2,    68,     2,    70,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    71
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   210,   210,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   241,   247,   252,   258,   264,   270,   276,
     283,   289,   297,   313,   332,   343,   376,   379,   393,   402,
     413,   417,   421,   427,   430,   431,   432,   433,   436,   452,
     455,   467,   471,   475,   478,   483,   491,   503,   528,   538,
     541,   547,   558,   592,   602,   607,   618,   621,   624,   627,
     630,   634,   637,   645,   652,   664,   673,   684,   685,   686,
     687,   688,   692,   693,   698,   701,   714,   719,   724,   727,
     740,   745,   756,   759,   772,   775,   779,   800,   803,   809,
     812,   817,   824,   836,   848,   860,   875,   878,   890,   893,
     906,   907,   908,   909,   910,   911,   912,   913,   914,   915,
     919,   920,   921,   925,   938,   946,   956,   957
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "INNER", "TABLE", "TABLES", "UNIQUE", "INDEX", "CALC", "SELECT",
  "DESC", "ASC", "ORDER", "BY", "SHOW", "SYNC", "INSERT", "DELETE",
  "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN", "TRX_COMMIT",
  "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T", "HELP", "EXIT",
  "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "SET", "MAX", "MIN",
  "COUNT", "AVG", "SUM", "ON", "LOAD", "DATA", "INFILE", "EXPLAIN", "EQ",
  "LT", "GT", "LE", "GE", "LKE", "NOT", "NE", "IS", "TNULL", "NUMBER",
  "FLOAT", "ID", "DATE_STR", "SSS", "JOIN", "'+'", "'-'", "'*'", "'/'",
  "UMINUS", "$accept", "commands", "command_wrapper", "exit_stmt",
  "help_stmt", "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "show_tables_stmt", "desc_table_stmt",
  "create_index_stmt", "drop_index_stmt", "create_table_stmt",
  "attr_def_list", "attr_def", "isnull", "number", "type", "insert_stmt",
  "value_list", "value", "delete_stmt", "update_stmt", "update_value",
  "update_value_list", "select_stmt", "calc_stmt", "expression_list",
  "expression", "select_attr", "aggr_attr", "aggr_op", "rel_aggr_attr",
  "rel_aggr_attr_list", "rel_attr_wildcard", "rel_attr_wildcard_list",
  "rel_attr", "rel_list", "join_list", "where", "condition_list",
  "condition", "order_by", "order_by_list", "comp_op", "order_op",
  "load_data_stmt", "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      83,   104,     4,    -6,    76,   -48,    15,  -161,   -10,     2,
     -32,  -161,  -161,  -161,  -161,  -161,   -17,    -1,    83,    57,
      58,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,     6,    61,    22,    29,    30,    -6,  -161,  -161,  -161,
    -161,  -161,    -6,  -161,  -161,    -2,  -161,  -161,  -161,  -161,
    -161,    52,  -161,    60,  -161,    77,    74,  -161,  -161,  -161,
      42,    43,    72,    71,    75,  -161,  -161,  -161,  -161,   103,
      63,    81,  -161,    82,   -18,  -161,    -6,    -6,    -6,    -6,
      -6,    68,    69,     1,   -15,  -161,    98,    97,    73,    96,
      78,    79,    91,    92,    99,  -161,  -161,   -60,   -60,  -161,
    -161,  -161,   114,  -161,  -161,   116,  -161,    74,   119,    19,
    -161,    93,   135,    97,  -161,   128,   -11,   140,   102,   146,
    -161,   106,    -3,   -56,   147,  -161,    96,    95,    95,  -161,
     132,    96,    73,  -161,   165,  -161,  -161,  -161,  -161,   -16,
      79,   150,   152,   112,   114,    -3,   113,    97,   116,  -161,
     153,  -161,  -161,  -161,  -161,  -161,  -161,   122,  -161,   123,
      19,    19,    19,  -161,  -161,   118,   121,   124,  -161,  -161,
     140,  -161,   120,   114,  -161,  -161,   133,   170,  -161,    96,
     163,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
     164,  -161,  -161,   114,   166,    19,   172,  -161,   153,  -161,
     -25,   167,  -161,    -3,   129,  -161,  -161,  -161,  -161,    23,
    -161,  -161,   169,   129,  -161,    23,   169,  -161
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,    24,    23,     0,     0,     0,     0,
     126,    22,    21,    14,    15,    16,    17,     9,    10,    11,
      12,    13,     8,     5,     7,     6,     4,     3,    18,    19,
      20,     0,     0,     0,     0,     0,     0,    53,    51,    52,
      54,    55,     0,    72,    63,    64,    77,    78,    79,    80,
      81,    90,    73,     0,    83,     0,    84,    82,    31,    30,
       0,     0,     0,     0,     0,   124,     1,   127,     2,     0,
       0,     0,    29,     0,     0,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,    97,    59,     0,
       0,     0,     0,     0,     0,    70,    65,    66,    67,    68,
      69,    91,    92,    76,    86,    88,    87,    84,     0,    99,
      56,     0,    60,    97,   125,     0,     0,    36,     0,     0,
      34,     0,    94,     0,     0,    85,     0,     0,     0,    98,
     100,     0,    59,    57,     0,    44,    45,    46,    47,    40,
       0,     0,     0,     0,    92,    94,     0,    97,    88,    75,
      49,   110,   111,   112,   113,   114,   117,     0,   115,   118,
       0,     0,    99,    58,    61,     0,     0,     0,    42,    39,
      36,    35,     0,    92,    93,    95,     0,   106,    89,     0,
       0,   116,   119,   103,   105,   102,   104,   101,   123,    43,
       0,    41,    37,    92,     0,    99,     0,    62,    49,    48,
      40,     0,    32,    94,     0,    50,    38,    33,    96,   122,
     120,   121,   108,     0,   107,   122,   108,   109
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,   173,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,    14,    45,   -14,  -161,  -161,
    -161,    -9,   -98,  -161,  -161,  -161,    55,  -161,  -161,   115,
     -12,  -161,  -161,  -161,   108,    86,    65,    46,    -4,  -150,
    -153,  -115,  -160,  -161,  -161,   -26,    67,   -19,  -161,  -161,
    -161,  -161
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   151,   127,   179,   200,   149,
      33,   190,    53,    34,    35,   122,   123,    36,    37,    54,
      55,    63,    64,    65,    66,    95,   115,   134,   138,   132,
     157,   120,   139,   140,   207,   224,   170,   222,    38,    39,
      40,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      67,   124,   185,   155,   184,   105,   176,    61,   143,    89,
      90,    44,   197,   114,    45,    68,    46,   145,   146,   147,
     148,   137,    86,    69,   113,    70,    56,    57,    58,    59,
      60,    72,   177,   204,    84,   178,   220,   221,   160,    71,
      85,   177,   187,   173,   178,   213,    73,    74,    61,    87,
      88,    89,    90,   211,    47,    48,    49,    76,    50,    51,
     218,    77,    52,   156,    61,    87,    88,    89,    90,    79,
     114,    80,   193,   195,   137,   107,   108,   109,   110,    47,
      48,    49,    61,    50,    51,    81,    91,     1,     2,   116,
      67,   208,    82,    83,     3,     4,     5,    92,    94,    93,
       6,     7,     8,     9,    10,    96,    97,   137,    11,    12,
      13,    41,    98,    42,    43,    14,    15,    56,    57,    58,
      59,    60,    99,    16,   100,   101,   102,   103,   104,   116,
      17,   111,   112,    18,   118,   119,   121,   128,   131,    61,
     133,   136,   126,   125,   141,    62,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   129,    47,    48,    49,   142,
      50,    51,   130,   144,   150,   152,   194,   196,   153,   154,
     159,   172,   175,   181,   182,   183,   186,   189,   191,   205,
     192,   198,   199,   203,   201,   206,   209,   210,   214,   212,
     217,    75,    61,   223,   202,   180,   216,   174,   158,   215,
     227,   106,   117,   135,   188,   171,   226,     0,     0,     0,
     219,     0,     0,     0,     0,     0,     0,     0,     0,   225
};

static const yytype_int16 yycheck[] =
{
       4,    99,   155,     6,   154,    23,    22,    63,   123,    69,
      70,     7,   172,    69,    10,    63,    22,    28,    29,    30,
      31,   119,    24,     8,    23,    35,    41,    42,    43,    44,
      45,    63,    57,   183,    46,    60,    13,    14,   136,    37,
      52,    57,   157,   141,    60,   205,    63,    48,    63,    67,
      68,    69,    70,   203,    60,    61,    62,     0,    64,    65,
     213,     3,    68,    66,    63,    67,    68,    69,    70,    63,
      69,    10,   170,   171,   172,    87,    88,    89,    90,    60,
      61,    62,    63,    64,    65,    63,    34,     4,     5,    93,
      94,   189,    63,    63,    11,    12,    13,    37,    24,    22,
      17,    18,    19,    20,    21,    63,    63,   205,    25,    26,
      27,     7,    40,     9,    10,    32,    33,    41,    42,    43,
      44,    45,    51,    40,    49,    22,    63,    46,    46,   133,
      47,    63,    63,    50,    36,    38,    63,    46,    24,    63,
      24,    22,    63,    65,    51,    69,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    63,    60,    61,    62,    24,
      64,    65,    63,    35,    24,    63,   170,   171,    22,    63,
      23,    39,     7,    23,    22,    63,    63,    24,    56,    46,
      57,    63,    61,    63,    60,    15,    23,    23,    16,    23,
      23,    18,    63,    24,   180,   150,   210,   142,   133,   208,
     226,    86,    94,   117,   158,   138,   225,    -1,    -1,    -1,
     214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    11,    12,    13,    17,    18,    19,    20,
      21,    25,    26,    27,    32,    33,    40,    47,    50,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    92,    95,    96,    99,   100,   120,   121,
     122,     7,     9,    10,     7,    10,    22,    60,    61,    62,
      64,    65,    68,    94,   101,   102,    41,    42,    43,    44,
      45,    63,    69,   103,   104,   105,   106,   110,    63,     8,
      35,    37,    63,    63,    48,    74,     0,     3,   123,    63,
      10,    63,    63,    63,   102,   102,    24,    67,    68,    69,
      70,    34,    37,    22,    24,   107,    63,    63,    40,    51,
      49,    22,    63,    46,    46,    23,   101,   102,   102,   102,
     102,    63,    63,    23,    69,   108,   110,   106,    36,    38,
     113,    63,    97,    98,    94,    65,    63,    88,    46,    63,
      63,    24,   111,    24,   109,   107,    22,    94,   110,   114,
     115,    51,    24,   113,    35,    28,    29,    30,    31,    91,
      24,    87,    63,    22,    63,     6,    66,   112,   108,    23,
      94,    51,    52,    53,    54,    55,    56,    57,    58,    59,
     118,   118,    39,    94,    98,     7,    22,    57,    60,    89,
      88,    23,    22,    63,   111,   112,    63,   113,   109,    24,
      93,    56,    57,    94,   110,    94,   110,   114,    63,    61,
      90,    60,    87,    63,   111,    46,    15,   116,    94,    23,
      23,   111,    23,   114,    16,    93,    89,    23,   112,   110,
      13,    14,   119,    24,   117,   110,   119,   117
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    72,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    84,    85,    86,    87,    87,    88,    88,
      89,    89,    89,    90,    91,    91,    91,    91,    92,    93,
      93,    94,    94,    94,    94,    94,    95,    96,    97,    98,
      98,    98,    99,   100,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   103,   103,   104,   104,   105,   105,   105,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   113,   113,   114,
     114,   114,   115,   115,   115,   115,   116,   116,   117,   117,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     119,   119,   119,   120,   121,   122,   123,   123
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     9,    10,     5,     7,     0,     3,     6,     3,
       0,     2,     1,     1,     1,     1,     1,     1,     8,     0,
       3,     1,     1,     1,     1,     1,     4,     5,     3,     0,
       1,     3,     8,     2,     1,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     2,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     1,     1,     0,     3,
       1,     3,     0,     3,     0,     2,     5,     0,     2,     0,
       1,     3,     3,     3,     3,     3,     0,     5,     0,     4,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     2,
       1,     1,     0,     7,     2,     4,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 211 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1795 "yacc_sql.cpp"
    break;

  case 23: /* exit_stmt: EXIT  */
#line 241 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1804 "yacc_sql.cpp"
    break;

  case 24: /* help_stmt: HELP  */
#line 247 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1812 "yacc_sql.cpp"
    break;

  case 25: /* sync_stmt: SYNC  */
#line 252 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1820 "yacc_sql.cpp"
    break;

  case 26: /* begin_stmt: TRX_BEGIN  */
#line 258 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1828 "yacc_sql.cpp"
    break;

  case 27: /* commit_stmt: TRX_COMMIT  */
#line 264 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1836 "yacc_sql.cpp"
    break;

  case 28: /* rollback_stmt: TRX_ROLLBACK  */
#line 270 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1844 "yacc_sql.cpp"
    break;

  case 29: /* drop_table_stmt: DROP TABLE ID  */
#line 276 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1854 "yacc_sql.cpp"
    break;

  case 30: /* show_tables_stmt: SHOW TABLES  */
#line 283 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1862 "yacc_sql.cpp"
    break;

  case 31: /* desc_table_stmt: DESC ID  */
#line 289 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1872 "yacc_sql.cpp"
    break;

  case 32: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID rel_list RBRACE  */
#line 298 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-6].string);
      create_index.relation_name = (yyvsp[-4].string);
      if ((yyvsp[-1].relation_list) != nullptr) {
        create_index.attribute_names.swap(*(yyvsp[-1].relation_list));
      }
      create_index.attribute_names.emplace_back((yyvsp[-2].string));

      create_index.unique = false;
      free((yyvsp[-6].string));
      free((yyvsp[-4].string));
      free((yyvsp[-2].string));
    }
#line 1892 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID rel_list RBRACE  */
#line 314 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-6].string);
      create_index.relation_name = (yyvsp[-4].string);
      // create_index.attribute_name = $8;
      if ((yyvsp[-1].relation_list) != nullptr){
        create_index.attribute_names.swap(*(yyvsp[-1].relation_list));
      }
      create_index.attribute_names.emplace_back((yyvsp[-2].string));
      create_index.unique = true;
      free((yyvsp[-6].string));
      free((yyvsp[-4].string));
      free((yyvsp[-2].string));
    }
#line 1912 "yacc_sql.cpp"
    break;

  case 34: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 333 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 1924 "yacc_sql.cpp"
    break;

  case 35: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 344 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);

      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-4].string);
      free((yyvsp[-4].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-1].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-2].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-2].attr_info);

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
#line 1957 "yacc_sql.cpp"
    break;

  case 36: /* attr_def_list: %empty  */
#line 376 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 1965 "yacc_sql.cpp"
    break;

  case 37: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 380 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 1979 "yacc_sql.cpp"
    break;

  case 38: /* attr_def: ID type LBRACE number RBRACE isnull  */
#line 394 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->isnull = (yyvsp[0].boolean);
      free((yyvsp[-5].string));
    }
#line 1992 "yacc_sql.cpp"
    break;

  case 39: /* attr_def: ID type isnull  */
#line 403 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->isnull = (yyvsp[0].boolean);
      (yyval.attr_info)->length = 4;
      free((yyvsp[-2].string));
    }
#line 2005 "yacc_sql.cpp"
    break;

  case 40: /* isnull: %empty  */
#line 413 "yacc_sql.y"
    {
      /* empty */
      (yyval.boolean) = false;
    }
#line 2014 "yacc_sql.cpp"
    break;

  case 41: /* isnull: NOT TNULL  */
#line 418 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2022 "yacc_sql.cpp"
    break;

  case 42: /* isnull: TNULL  */
#line 422 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2030 "yacc_sql.cpp"
    break;

  case 43: /* number: NUMBER  */
#line 427 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2036 "yacc_sql.cpp"
    break;

  case 44: /* type: INT_T  */
#line 430 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2042 "yacc_sql.cpp"
    break;

  case 45: /* type: STRING_T  */
#line 431 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2048 "yacc_sql.cpp"
    break;

  case 46: /* type: FLOAT_T  */
#line 432 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2054 "yacc_sql.cpp"
    break;

  case 47: /* type: DATE_T  */
#line 433 "yacc_sql.y"
               { (yyval.number)=DATES; }
#line 2060 "yacc_sql.cpp"
    break;

  case 48: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 437 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-5].string);
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.sql_node)->insertion.values.swap(*(yyvsp[-1].value_list));
      }
      (yyval.sql_node)->insertion.values.emplace_back(*(yyvsp[-2].value));
      std::reverse((yyval.sql_node)->insertion.values.begin(), (yyval.sql_node)->insertion.values.end());
      delete (yyvsp[-2].value);
      free((yyvsp[-5].string));
    }
#line 2076 "yacc_sql.cpp"
    break;

  case 49: /* value_list: %empty  */
#line 452 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2084 "yacc_sql.cpp"
    break;

  case 50: /* value_list: COMMA value value_list  */
#line 455 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2098 "yacc_sql.cpp"
    break;

  case 51: /* value: NUMBER  */
#line 467 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2107 "yacc_sql.cpp"
    break;

  case 52: /* value: FLOAT  */
#line 471 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2116 "yacc_sql.cpp"
    break;

  case 53: /* value: TNULL  */
#line 475 "yacc_sql.y"
           {
      (yyval.value) = new Value(NULL_VALUE, 1);
    }
#line 2124 "yacc_sql.cpp"
    break;

  case 54: /* value: DATE_STR  */
#line 478 "yacc_sql.y"
              {
      char* tmp = common::substr((yyvsp[0].string), 1, strlen((yyvsp[0].string)) - 2);
      (yyval.value) = new Value(tmp, strlen(tmp), 1);
      free(tmp);
    }
#line 2134 "yacc_sql.cpp"
    break;

  case 55: /* value: SSS  */
#line 483 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
    }
#line 2144 "yacc_sql.cpp"
    break;

  case 56: /* delete_stmt: DELETE FROM ID where  */
#line 492 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2158 "yacc_sql.cpp"
    break;

  case 57: /* update_stmt: UPDATE ID SET update_value_list where  */
#line 504 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-3].string);

      for (auto node: *(yyvsp[-1].update_value_list)) {
        (yyval.sql_node)->update.attribute_names.push_back(node.attribute_name);
        (yyval.sql_node)->update.values.push_back(node.value);
      }
      // for (int i = 0; i < $4->size(); i++)
      // {
      //   $$->update.attribute_names.push_back((($4)[i]).attribute_name);
      //   $$->update.values.push_back((($4)[i]).value);
      // }

      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->update.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-3].string));
      //free($4);
    }
#line 2184 "yacc_sql.cpp"
    break;

  case 58: /* update_value: ID EQ value  */
#line 529 "yacc_sql.y"
  {
    (yyval.update_value) = new UpdateValueSqlNode;
    (yyval.update_value)->attribute_name = (yyvsp[-2].string);
    (yyval.update_value)->value = *(yyvsp[0].value);
  }
#line 2194 "yacc_sql.cpp"
    break;

  case 59: /* update_value_list: %empty  */
#line 538 "yacc_sql.y"
  {
    (yyval.update_value_list) = nullptr;
  }
#line 2202 "yacc_sql.cpp"
    break;

  case 60: /* update_value_list: update_value  */
#line 542 "yacc_sql.y"
  {
      (yyval.update_value_list) = new std::vector<UpdateValueSqlNode>;
      (yyval.update_value_list)->emplace_back(*(yyvsp[0].update_value));
      delete (yyvsp[0].update_value);
  }
#line 2212 "yacc_sql.cpp"
    break;

  case 61: /* update_value_list: update_value COMMA update_value_list  */
#line 548 "yacc_sql.y"
  {
    (yyval.update_value_list) = (yyvsp[0].update_value_list);
    (yyval.update_value_list)->emplace_back(*(yyvsp[-2].update_value));
    delete (yyvsp[-2].update_value);
  }
#line 2222 "yacc_sql.cpp"
    break;

  case 62: /* select_stmt: SELECT select_attr FROM ID rel_list join_list where order_by  */
#line 559 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-6].rel_attr_list) != nullptr) {
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[-6].rel_attr_list));
        delete (yyvsp[-6].rel_attr_list);
      }
      if ((yyvsp[-3].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-3].relation_list));
        delete (yyvsp[-3].relation_list);
      }
      (yyval.sql_node)->selection.relations.push_back((yyvsp[-4].string));
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      if ((yyvsp[-1].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }
      free((yyvsp[-4].string));

      if ((yyvsp[-2].join_sql_node) != nullptr) {
        (yyval.sql_node)->selection.relations.insert((yyval.sql_node)->selection.relations.end(), (yyvsp[-2].join_sql_node)->relations.begin(), (yyvsp[-2].join_sql_node)->relations.end());
        (yyval.sql_node)->selection.conditions.insert((yyval.sql_node)->selection.conditions.end(), (yyvsp[-2].join_sql_node)->conditions.begin(), (yyvsp[-2].join_sql_node)->conditions.end());
        delete (yyvsp[-2].join_sql_node);
      }

      if ((yyvsp[0].order_by_list) != nullptr) {
        (yyval.sql_node)->selection.order_rules.swap(*(yyvsp[0].order_by_list));
        delete (yyvsp[0].order_by_list);
      }
    }
#line 2257 "yacc_sql.cpp"
    break;

  case 63: /* calc_stmt: CALC expression_list  */
#line 593 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2268 "yacc_sql.cpp"
    break;

  case 64: /* expression_list: expression  */
#line 603 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2277 "yacc_sql.cpp"
    break;

  case 65: /* expression_list: expression COMMA expression_list  */
#line 608 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2290 "yacc_sql.cpp"
    break;

  case 66: /* expression: expression '+' expression  */
#line 618 "yacc_sql.y"
                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2298 "yacc_sql.cpp"
    break;

  case 67: /* expression: expression '-' expression  */
#line 621 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2306 "yacc_sql.cpp"
    break;

  case 68: /* expression: expression '*' expression  */
#line 624 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2314 "yacc_sql.cpp"
    break;

  case 69: /* expression: expression '/' expression  */
#line 627 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2322 "yacc_sql.cpp"
    break;

  case 70: /* expression: LBRACE expression RBRACE  */
#line 630 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2331 "yacc_sql.cpp"
    break;

  case 71: /* expression: '-' expression  */
#line 634 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2339 "yacc_sql.cpp"
    break;

  case 72: /* expression: value  */
#line 637 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2349 "yacc_sql.cpp"
    break;

  case 73: /* select_attr: '*'  */
#line 645 "yacc_sql.y"
        {
      (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      RelAttrSqlNode attr;
      attr.relation_name  = "";
      attr.attribute_name = "*";
      (yyval.rel_attr_list)->emplace_back(attr);
    }
#line 2361 "yacc_sql.cpp"
    break;

  case 74: /* select_attr: rel_aggr_attr rel_aggr_attr_list  */
#line 652 "yacc_sql.y"
                                       {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }
      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2375 "yacc_sql.cpp"
    break;

  case 75: /* aggr_attr: aggr_op LBRACE rel_attr_wildcard rel_attr_wildcard_list RBRACE  */
#line 664 "yacc_sql.y"
                                                                   {
      (yyval.rel_attr) = (yyvsp[-2].rel_attr);
      (yyval.rel_attr)->aggregation = (yyvsp[-4].aggr);
      // redundant columns
      if ((yyvsp[-1].rel_attr_list) != nullptr) {
        (yyval.rel_attr)->valid = false;
        delete (yyvsp[-1].rel_attr_list);
      }
    }
#line 2389 "yacc_sql.cpp"
    break;

  case 76: /* aggr_attr: aggr_op LBRACE RBRACE  */
#line 673 "yacc_sql.y"
                            {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name = "";
      (yyval.rel_attr)->attribute_name = "";
      (yyval.rel_attr)->aggregation = (yyvsp[-2].aggr);
      // empty columns
      (yyval.rel_attr)->valid = false;
    }
#line 2402 "yacc_sql.cpp"
    break;

  case 77: /* aggr_op: MAX  */
#line 684 "yacc_sql.y"
          { (yyval.aggr) = AGGR_MAX; }
#line 2408 "yacc_sql.cpp"
    break;

  case 78: /* aggr_op: MIN  */
#line 685 "yacc_sql.y"
          { (yyval.aggr) = AGGR_MIN; }
#line 2414 "yacc_sql.cpp"
    break;

  case 79: /* aggr_op: COUNT  */
#line 686 "yacc_sql.y"
            { (yyval.aggr) = AGGR_COUNT; }
#line 2420 "yacc_sql.cpp"
    break;

  case 80: /* aggr_op: AVG  */
#line 687 "yacc_sql.y"
          { (yyval.aggr) = AGGR_AVG; }
#line 2426 "yacc_sql.cpp"
    break;

  case 81: /* aggr_op: SUM  */
#line 688 "yacc_sql.y"
          { (yyval.aggr) = AGGR_SUM; }
#line 2432 "yacc_sql.cpp"
    break;

  case 84: /* rel_aggr_attr_list: %empty  */
#line 698 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 2440 "yacc_sql.cpp"
    break;

  case 85: /* rel_aggr_attr_list: COMMA rel_aggr_attr rel_aggr_attr_list  */
#line 701 "yacc_sql.y"
                                             {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }

      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2455 "yacc_sql.cpp"
    break;

  case 86: /* rel_attr_wildcard: '*'  */
#line 714 "yacc_sql.y"
        {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name = "";
      (yyval.rel_attr)->attribute_name = "*";
    }
#line 2465 "yacc_sql.cpp"
    break;

  case 88: /* rel_attr_wildcard_list: %empty  */
#line 724 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 2473 "yacc_sql.cpp"
    break;

  case 89: /* rel_attr_wildcard_list: COMMA rel_attr_wildcard rel_attr_wildcard_list  */
#line 727 "yacc_sql.y"
                                                     {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }

      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2488 "yacc_sql.cpp"
    break;

  case 90: /* rel_attr: ID  */
#line 740 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2498 "yacc_sql.cpp"
    break;

  case 91: /* rel_attr: ID DOT ID  */
#line 745 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2510 "yacc_sql.cpp"
    break;

  case 92: /* rel_list: %empty  */
#line 756 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 2518 "yacc_sql.cpp"
    break;

  case 93: /* rel_list: COMMA ID rel_list  */
#line 759 "yacc_sql.y"
                        {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::string>;
      }

      (yyval.relation_list)->push_back((yyvsp[-1].string));
      free((yyvsp[-1].string));
    }
#line 2533 "yacc_sql.cpp"
    break;

  case 94: /* join_list: %empty  */
#line 772 "yacc_sql.y"
    {
      (yyval.join_sql_node) = nullptr;
    }
#line 2541 "yacc_sql.cpp"
    break;

  case 95: /* join_list: INNER join_list  */
#line 776 "yacc_sql.y"
    {
      (yyval.join_sql_node) = (yyvsp[0].join_sql_node);
    }
#line 2549 "yacc_sql.cpp"
    break;

  case 96: /* join_list: JOIN ID ON condition_list join_list  */
#line 780 "yacc_sql.y"
    {
      (yyval.join_sql_node) = new JoinSqlNode();

      if ((yyvsp[-1].condition_list) != nullptr) {
        (yyval.join_sql_node)->conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }

      (yyval.join_sql_node)->relations.push_back((yyvsp[-3].string));
      // $$->conditions.push_back(*$4);
      free((yyvsp[-3].string));

      if ((yyvsp[0].join_sql_node) != nullptr) {
        (yyval.join_sql_node)->relations.insert((yyval.join_sql_node)->relations.end(), (yyvsp[0].join_sql_node)->relations.begin(), (yyvsp[0].join_sql_node)->relations.end());
        (yyval.join_sql_node)->conditions.insert((yyval.join_sql_node)->conditions.end(), (yyvsp[0].join_sql_node)->conditions.begin(), (yyvsp[0].join_sql_node)->conditions.end());
        delete (yyvsp[0].join_sql_node);
      }
    }
#line 2572 "yacc_sql.cpp"
    break;

  case 97: /* where: %empty  */
#line 800 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2580 "yacc_sql.cpp"
    break;

  case 98: /* where: WHERE condition_list  */
#line 803 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 2588 "yacc_sql.cpp"
    break;

  case 99: /* condition_list: %empty  */
#line 809 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2596 "yacc_sql.cpp"
    break;

  case 100: /* condition_list: condition  */
#line 812 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 2606 "yacc_sql.cpp"
    break;

  case 101: /* condition_list: condition AND condition_list  */
#line 817 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 2616 "yacc_sql.cpp"
    break;

  case 102: /* condition: rel_attr comp_op value  */
#line 825 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[0].value);
    }
#line 2632 "yacc_sql.cpp"
    break;

  case 103: /* condition: value comp_op value  */
#line 837 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-2].value);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].value);
      delete (yyvsp[0].value);
    }
#line 2648 "yacc_sql.cpp"
    break;

  case 104: /* condition: rel_attr comp_op rel_attr  */
#line 849 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[0].rel_attr);
    }
#line 2664 "yacc_sql.cpp"
    break;

  case 105: /* condition: value comp_op rel_attr  */
#line 861 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-2].value);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].value);
      delete (yyvsp[0].rel_attr);
    }
#line 2680 "yacc_sql.cpp"
    break;

  case 106: /* order_by: %empty  */
#line 875 "yacc_sql.y"
  {
    (yyval.order_by_list) = nullptr;
  }
#line 2688 "yacc_sql.cpp"
    break;

  case 107: /* order_by: ORDER BY rel_attr order_op order_by_list  */
#line 879 "yacc_sql.y"
  {
    (yyval.order_by_list) = new std::vector<std::pair<RelAttrSqlNode, OrderOp>>;
    (yyval.order_by_list)->emplace_back(std::make_pair(*(yyvsp[-2].rel_attr), (yyvsp[-1].orderOp)));
    delete (yyvsp[-2].rel_attr);
    if ((yyvsp[0].order_by_list) != nullptr) {
      (yyval.order_by_list)->insert((yyval.order_by_list)->end(), (yyvsp[0].order_by_list)->begin(), (yyvsp[0].order_by_list)->end());
    }
  }
#line 2701 "yacc_sql.cpp"
    break;

  case 108: /* order_by_list: %empty  */
#line 890 "yacc_sql.y"
  {
    (yyval.order_by_list) = nullptr;
  }
#line 2709 "yacc_sql.cpp"
    break;

  case 109: /* order_by_list: COMMA rel_attr order_op order_by_list  */
#line 894 "yacc_sql.y"
  {
    (yyval.order_by_list) = new std::vector<std::pair<RelAttrSqlNode, OrderOp>>;
    (yyval.order_by_list)->emplace_back(std::make_pair(*(yyvsp[-2].rel_attr), (yyvsp[-1].orderOp)));
    delete (yyvsp[-2].rel_attr);

    if ((yyvsp[0].order_by_list) != nullptr) {
      (yyval.order_by_list)->insert((yyval.order_by_list)->end(), (yyvsp[0].order_by_list)->begin(), (yyvsp[0].order_by_list)->end());
    }
  }
#line 2723 "yacc_sql.cpp"
    break;

  case 110: /* comp_op: EQ  */
#line 906 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 2729 "yacc_sql.cpp"
    break;

  case 111: /* comp_op: LT  */
#line 907 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 2735 "yacc_sql.cpp"
    break;

  case 112: /* comp_op: GT  */
#line 908 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 2741 "yacc_sql.cpp"
    break;

  case 113: /* comp_op: LE  */
#line 909 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 2747 "yacc_sql.cpp"
    break;

  case 114: /* comp_op: GE  */
#line 910 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 2753 "yacc_sql.cpp"
    break;

  case 115: /* comp_op: NE  */
#line 911 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 2759 "yacc_sql.cpp"
    break;

  case 116: /* comp_op: NOT LKE  */
#line 912 "yacc_sql.y"
              { (yyval.comp) = NOT_LIKE; }
#line 2765 "yacc_sql.cpp"
    break;

  case 117: /* comp_op: LKE  */
#line 913 "yacc_sql.y"
          { (yyval.comp) = LIKE; }
#line 2771 "yacc_sql.cpp"
    break;

  case 118: /* comp_op: IS  */
#line 914 "yacc_sql.y"
         { (yyval.comp) = OP_ISNULL; }
#line 2777 "yacc_sql.cpp"
    break;

  case 119: /* comp_op: IS NOT  */
#line 915 "yacc_sql.y"
             { (yyval.comp) = OP_ISNOTNULL; }
#line 2783 "yacc_sql.cpp"
    break;

  case 120: /* order_op: DESC  */
#line 919 "yacc_sql.y"
         { (yyval.orderOp) = ORDER_DESC; }
#line 2789 "yacc_sql.cpp"
    break;

  case 121: /* order_op: ASC  */
#line 920 "yacc_sql.y"
         { (yyval.orderOp) = ORDER_ASC;  }
#line 2795 "yacc_sql.cpp"
    break;

  case 122: /* order_op: %empty  */
#line 921 "yacc_sql.y"
         { (yyval.orderOp) = ORDER_DEFAULT; }
#line 2801 "yacc_sql.cpp"
    break;

  case 123: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 926 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 2815 "yacc_sql.cpp"
    break;

  case 124: /* explain_stmt: EXPLAIN command_wrapper  */
#line 939 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 2824 "yacc_sql.cpp"
    break;

  case 125: /* set_variable_stmt: SET ID EQ value  */
#line 947 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 2836 "yacc_sql.cpp"
    break;


#line 2840 "yacc_sql.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 959 "yacc_sql.y"

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
