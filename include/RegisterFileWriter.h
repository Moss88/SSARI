#ifndef REGISTERFILEWRITER
#define REGISTERFILEWRITER

#include <IRNav/RegisterFile.h>
namespace BFAST {

class RegisterFileWriter {
public:
    RegisterFileWriter();
    bool writeFile(string path, RegisterFile &rf);
    ~RegisterFileWriter();

};

}


#endif // REGISTERFILEWRITER

