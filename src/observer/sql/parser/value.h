/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai 2023/6/27
//

#pragma once

#include <string>
// #include "observer/common/rc.h"

/**
 * @brief 属性的类型
 * 
 */
enum AttrType
{
  UNDEFINED,
  CHARS,          ///< 字符串类型
  INTS,           ///< 整数类型(4字节)
  FLOATS,         ///< 浮点数类型(4字节)
  NULLS,          
  DATES,          
  BOOLEANS,       ///< boolean类型，当前不是由parser解析出来的，是程序内部使用的
};

const char *attr_type_to_string(AttrType type);
AttrType attr_type_from_string(const char *s);

/**
 * @brief 属性的值
 * 
 */
class Value 
{
public:
  Value() = default;

  Value(AttrType attr_type, char *data, int length = 4) : attr_type_(attr_type)
  {
    this->set_data(data, length);
  }

  explicit Value(int val);
  explicit Value(int val, int flag);                    // 加入flag也是为了和int区分
  explicit Value(float val);
  explicit Value(bool val);
  explicit Value(const char *date, int len, int flag);  //加入flag参数是为了和string类型的构造函数区分
  explicit Value(const char *s, int len = 0);

  Value(const Value &other) = default;
  Value &operator=(const Value &other) = default;

  void set_type(AttrType type)
  {
    this->attr_type_ = type;
  }
  void set_data(char *data, int length);
  void set_data(const char *data, int length)
  {
    this->set_data(const_cast<char *>(data), length);
  }
  void set_int(int val);
  void set_float(float val);
  void set_boolean(bool val);
  void set_string(const char *s, int len = 0);
  void set_date(int val);
  void set_null(int val);
  // void set_date(const char* date, int len);
  void set_value(const Value &value);

  std::string to_string() const;

  int compare(const Value &other) const;

  const char *data() const;
  int length() const
  {
    return length_;
  }

  AttrType attr_type() const
  {
    return attr_type_;
  }

public:
  /**
   * 获取对应的值
   * 如果当前的类型与期望获取的类型不符，就会执行转换操作
   */
  int get_int() const;
  float get_float() const;
  std::string get_string() const;
  bool get_boolean() const;
  int get_date() const;
  int get_null() const;

private:
  AttrType attr_type_ = UNDEFINED;
  int length_ = 0;

  union {
    int int_value_;
    float float_value_;
    bool bool_value_;
    int date_value_;    //采用int存储date类型
    int null_value_;
  } num_value_;
  std::string str_value_;
};



// 下面是一些date串相关的检查与转换方法


bool is_leap_year(int year);
void strDate_to_intDate_(const char* strDate, int& intDate);
void intDate_to_strDate_(const int intDate, std::string& strDate);
std::string floatString_to_String(std::string floatString);
std::string removeFloatStringEndZero(std::string str);
