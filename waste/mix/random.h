//
//  waste_rand.hpp
//  waste
//
//  Created by wangmeng on 2018/6/4.
//  Copyright © 2018年 cxin. All rights reserved.
//

#ifndef waste_rand_hpp
#define waste_rand_hpp

#include <stdio.h>
#include "model.h"

namespace mix {
    
class random
{
private:
    const static int NS_TYPE_COUNT = 10;
    
private:
    void
    init_srand();
    
public:
    random();
    ~random();

    string get_ns_type(mix_ns_type nstype);
    
    mix_ns_type rand_ns_type(int startpos=1);
    
    string rand_string(int mix, int max);
    
    int rand_num_range(int range);
    
    int rand_num(int min,int max);
    
    bool rand_bool();
};

}
#endif /* waste_rand_hpp */
