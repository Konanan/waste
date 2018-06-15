#include "file.h"

namespace mix {

unsigned char* file::read(const char* path, const char* mode, unsigned long * len)
{
    unsigned char * pBuffer = NULL;
    *len = 0;
    do
    {
        // read the file from hardware
        FILE *fp = fopen(path, mode);
		if(!fp){
			break;
		}
        
        fseek(fp,0,SEEK_END);
        *len = ftell(fp);
        fseek(fp,0,SEEK_SET);
        pBuffer = new unsigned char[*len];
        *len = fread(pBuffer,sizeof(unsigned char), *len,fp);
        fclose(fp);
    } while (0);
    
    if (! pBuffer)
    {
        std::string msg = "Get data from file(";
        msg.append(path).append(") failed!");
		printf("%s", msg.c_str());
    }
    return pBuffer;
}

bool file::write(unsigned char* data,const char *path, const char* mode, unsigned long len)
{
	do{
        std::string fullPath = path;
        FILE *fp = fopen(fullPath.c_str(), mode);
		if(!fp){
			return false;
		}

		fwrite(data,sizeof(unsigned char),len,fp);
		fclose(fp);
	}while (0);
	return true;
}
    
}
