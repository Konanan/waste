#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdio.h>
#include <assert.h>

namespace mix {

class file
{
public:
	static unsigned char* read(const char* path, const char* mode, unsigned long * len);
	static bool write(unsigned char* data,const char *path, const char* mode, unsigned long len);
};

}
