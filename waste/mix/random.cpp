//
//  waste_rand.cpp
//  waste
//
//  Created by wangmeng on 2018/6/4.
//  Copyright © 2018年 cxin. All rights reserved.
//

#include "random.h"

namespace mix {

random::random() {
    init_srand();
}

random::~random(){
    
}

//根据nstype获取描述
string random::get_ns_type(mix_ns_type nstype) {
    
    switch (nstype) {
        case ns_void:
            return "void";
        case ns_char:
            return "char";
        case ns_int:
            return "int";
        case ns_float:
            return "float";
        case ns_double:
            return "double";
        case ns_NSObject:
            return "NSObject*";
        case ns_NSSet:
            return "NSSet*";
        case ns_NSArray:
            return "NSArray*";
        case ns_NSString:
            return "NSString*";
        case ns_NSDictionary:
            return "NSDictionary*";
        default:
            return "void";
    }
    return "void";
}

//获取随机的类型名
mix_ns_type random::rand_ns_type(int startpos){
    return (mix_ns_type)rand_num(startpos, NS_TYPE_COUNT);
}

//获取随机字符串 A-Z 65-90 a-z 97-122
string random::rand_string(int min, int max) {
    string rand_str;
    char ch;
    for (int i=0; i<rand_num(min, max); i++) {
        ch = rand_num_range(26) + (rand_bool() ? 64 : 96);
        if((i>5) & rand_bool() && rand_bool()){
            ch = rand_num_range(10) + 47;
        }
        rand_str.append(&ch);
    }
    return rand_str;
}

//随机数字
int random::rand_num_range(int range) {
    return rand()%range+1;
}

int random::rand_num(int min,int max) {
    int r = rand();
    while (r < min || r > max) {
        r = r%max + min;
    }
    return r;
}

bool random::rand_bool() {
    return 2 == rand_num_range(2);
}

void random::init_srand() {
    srand((unsigned)time(NULL));
}
    
}

