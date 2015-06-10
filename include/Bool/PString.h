#ifndef PSTRING
#define PSTRING
#include <iostream>
using namespace std;
namespace SSARI {

class PString {
public:
    PString(int size = 512) {
        if(size > 0)
        {
            buffer = (char*)malloc(size);
            buffSize = size;
            termChar = buffer;
            endBuffer = buffer + buffSize;
            *buffer = '\0';
        }
        else
            buffSize = 0;
    }

    ~PString() {
        if(buffer)
            free(buffer);
    }

    inline const char * c_str() const {
        return buffer;
    }

    inline void push_back(const char *str) {
        if(termChar == endBuffer)
            this->resize();

        while(*str != '\0')
        {
            *termChar++ = *str++;
            if(termChar == endBuffer)
                this->resize();
        }
        *termChar = '\0';
    }

private:
    char *buffer = 0;
    char *termChar = 0;
    char *endBuffer = 0;
    int buffSize;

    void resize() {
        if(buffer)
        {
            buffSize += buffSize;
            buffer = (char*)realloc(buffer, buffSize);
            endBuffer = buffer + buffSize;
        }
        else
        {
            buffSize = 512;
            buffer = (char*)malloc(buffSize);
            termChar = buffer;
            endBuffer = buffer + buffSize;
            *buffer = '\0';
        }
    }
};

}
#endif // PSTRING
