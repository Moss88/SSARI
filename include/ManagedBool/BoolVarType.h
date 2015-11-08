#ifndef BOOLVARTYPE_H
#define BOOLVARTYPE_H

#include<string>
class BoolVarType {
public:
    virtual unsigned int size() = 0;
    virtual std::string str() = 0;
};

#endif // BOOLVARTYPE_H

