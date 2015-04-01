#ifndef SYMBOLICVAR_H
#define SYMBOLICVAR_H
#include <string>
using std::string;

namespace SSARI {

class SymbolicVar {
public:
    virtual string toString() const = 0;
    virtual ~SymbolicVar(){}
};

}

#endif // SYMBOLICVAR_H

