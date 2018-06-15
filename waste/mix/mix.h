//
//  waste.hpp
//  waste
//
//  Created by wangmeng on 2018/5/31.
//  Copyright © 2018年 cxin. All rights reserved.
//

#ifndef waste_hpp
#define waste_hpp

#include <stdio.h>
#include <iostream>
#include "random.h"
#include "model.h"

using namespace std;

namespace mix {
    
class waste
{
    
private:
    mix::random* wrand;
    
    string get_default_value(mix_ns_type nstype);
    void free(mix_class* mc);

public:
    string root_dir;
    int file_count;
    
    waste();
    ~waste();    
    
    void product();
    
    mix_method* create_method();
    
    mix_params* create_params(int index);
    
    mix_class* create_class();
    
    string tostring(bool is_header,mix_class* mc);

    void create_file();
};
    
}

#endif /* waste_hpp */
