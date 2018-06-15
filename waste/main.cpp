//
//  main.cpp
//  waste
//
//  Created by wangmeng on 2018/5/31.
//  Copyright © 2018年 cxin. All rights reserved.
//

#include <iostream>
#include "mix.h"
int main(int argc, const char * argv[]) {
    
    if(argc < 3){
        printf("params count should bigger than 2.\n 1.root dir path.\n 2.output file count .\n\n");
        return 0;
    }
    
    mix::waste w;
    w.root_dir = argv[1];
    w.file_count = atoi(argv[2]);
    w.product();
    return 0;
}
