//
//  waste.cpp
//  waste
//
//  Created by wangmeng on 2018/5/31.
//  Copyright © 2018年 cxin. All rights reserved.
//

#include "mix.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include "file.h"

namespace mix {

    waste::waste()
    :root_dir("")
    ,wrand(NULL)
    ,file_count(10)
    {
        wrand = new mix::random();
    }
    
    waste::~waste(){
        if(NULL != wrand){
            delete wrand;
        }
    }
    
    void waste::product() {
        for (int i=0; i<file_count; i++) {
            create_file();
        }
    }
    
    void waste::free(mix_class* mc)
    {
        for (int i=0; i<mc->method_count; i++) {
            mix_method* method = mc->methods[i];
            if(method->params != NULL){
                delete [] method->params;
            }
        }
        delete [] mc->methods;
        delete mc;
    }

void waste::create_file() {
    
    mix_class* mc = create_class();
    string hfile = tostring(true,mc);
    string mfile = tostring(false,mc);
    
    //添加文件分隔符
    if(root_dir[root_dir.length()-1] != '/'){
        root_dir.append("/");
    }
    
    file::write((unsigned char*)hfile.c_str(), (root_dir + mc->name+".h").c_str(), "w", hfile.length());
    file::write((unsigned char*)mfile.c_str(), (root_dir + mc->name + ".m").c_str(), "w", mfile.length());
    
    free(mc);
}

mix_class* waste::create_class() {
    mix_class* mc = new mix_class();
    mc->name = wrand->rand_string(10, 20);
    mc->method_count = wrand->rand_num(20, 50);
    mc->methods = new mix_method*[mc->method_count];
    for (int i=0; i<mc->method_count; i++) {
        mc->methods[i] = create_method();
    }
    return mc;
}

mix_method* waste::create_method() {
    
    mix_method* method = new mix_method();
    method->name = wrand->rand_string(5, 25);
    method->is_static = wrand->rand_bool() && wrand->rand_bool() && wrand->rand_bool();
    method->ret_type = wrand->rand_ns_type();
    method->param_count = wrand->rand_num(0,6);
    method->params = new mix_params*[method->param_count];
    for (int i=0; i<method->param_count; i++) {
        method->params[i] = create_params(i);
    }
    return method;
}

//创建参数列表
mix_params* waste::create_params(int index) {
    mix_params* param = new mix_params();
    ostringstream s1(param->arg_name);
    ostringstream s2(param->param_name);
    s1<<"arg"<<index;
    s2<<"param"<<index;
    param->arg_name = s1.str();
    param->param_name = s2.str();
    param->ret_type = wrand->rand_ns_type(2);
    return param;
}

string waste::tostring(bool is_header,mix_class* mc)
{
    ostringstream oss;
    oss<<"//\n";
    oss<<"//  "<<mc->name<<".h\n";
    oss<<"//  MyProject\n";
    oss<<"//\n";
    oss<<"//  Created by Jackson on 2018/5/4.\n";
    oss<<"//  Copyright © 2018年 Xcode. All rights reserved.\n";
    oss<<"//\n";
    oss<<"\n";
    if (is_header) {
        oss<<"#import <UIKit/UIKit.h>\n";
    }else{
        oss<<"#import "<<"\""<<mc->name<<".h\""<<"\n";
    }
    oss<<"\n";
    if(is_header){
        oss<<"@interface "<<mc->name<<" : "<<"NSObject\n";
    }else{
        oss<<"@implementation "<<mc->name<<" : "<<"NSObject\n";
    }
    oss<<"\n";
    oss<<"\n";
    oss<<"\n";
    
    for (int m=0; m<mc->method_count; m++) {
        mix_method* mm = mc->methods[m];
        
        //是否static函数
        if(mm->is_static){
            oss<<"+";
        }else{
            oss<<"-";
        }
        
        //函数体
        oss<<"("<<wrand->get_ns_type(mm->ret_type)<<")"<<mm->name;
        if(mm->param_count > 0){
            oss<<":";
        }
        
        //参数列表
        for(int i=0; i<mm->param_count; i++){
            //第一个参数不加名字
            if(i > 0){
                oss<<mm->params[i]->arg_name<<":";
            }
            oss<<"("<<wrand->get_ns_type(mm->params[i]->ret_type)<<")"<<mm->params[i]->param_name;
            //最后一个参数不留空格
            if(i < mm->param_count-1){
                oss<<" ";
            }
        }
        //函数结尾
        if(is_header){
            oss<<";\n\n";
        }else{
            oss<<"\n{\n";
            oss<<"    for (int i=0; i<100; i++) {"<<"\n";
            oss<<"          i++;\n";
            oss<<"    }\n";

            if(mm->ret_type != ns_void){
                oss<<"    "<<wrand->get_ns_type(mm->ret_type)<<" "<<"xxxx "<<get_default_value(mm->ret_type)<<"\n";
                oss<<"    return xxxx;\n";
            }
            oss<<"}\n\n";
        }
    }
    oss<<"\n\n\n@end\n";
    return oss.str();
}

string waste::get_default_value(mix_ns_type nstype)
{
    switch (nstype) {
        case ns_int:
            return "= 100;";
        case ns_float:
            return "= 101.11;";
        case ns_double:
            return "= 100.0011;";
        case ns_char:
            return "= 'A';";
        case ns_NSObject:
            return "= [NSObject alloc];";
        case ns_NSSet:
            return "= [NSSet alloc];";
        case ns_NSArray:
            return "= [NSArray alloc];";
        case ns_NSString:
            return "= [NSString alloc];";
        case ns_NSDictionary:
            return "= [NSDictionary alloc];";
        case ns_void:
            default:
            return ";";
    }
    return ";";
}
    
}
