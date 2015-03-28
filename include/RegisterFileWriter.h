#ifndef REGISTERFILEWRITER
#define REGISTERFILEWRITER

#include <RegisterFile.h>
namespace BFAST {

class RegisterFileWriter {
public:
    RegisterFileWriter();
    bool writeFile(string path, RegisterFile &rf);
    ~RegisterFileWriter();

};

}


#endif // REGISTERFILEWRITER

