//
//  waste_model.hpp
//  waste
//
//  Created by wangmeng on 2018/6/4.
//  Copyright © 2018年 cxin. All rights reserved.
//

#ifndef waste_model_hpp
#define waste_model_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

//类型
enum mix_ns_type{
    ns_void = 1,            //void
    ns_int = 2,             //int
    ns_float = 3,           //float
    ns_double = 4,          //double
    ns_char = 5,            //char
    ns_NSObject = 6,        //NSObject
    ns_NSString = 7,        //NSString*
    ns_NSSet = 8,           //NSSet
    ns_NSArray = 9,         //NSArray
    ns_NSDictionary = 10,   //NSDictionary
};
typedef mix_ns_type mix_ns_type;


//参数
struct mix_params
{
    mix_ns_type ret_type;
    std::string arg_name;
    std::string param_name;
};
typedef mix_params mix_params;


//函数
struct mix_method
{
    bool is_static;
    mix_ns_type ret_type;
    std::string name;
    int param_count;
    mix_params** params;
};
typedef mix_method mix_method;


//类
struct mix_class
{
    std::string name;
    mix_method** methods;
    int method_count;
};
typedef mix_class mix_class;


#endif /* waste_model_hpp */
