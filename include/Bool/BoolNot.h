#ifndef BOOLNOT_H
#define BOOLNOT_H
#include <string>
#include <iostream>
#include "./BoolUnary.h"
using std::to_string;
namespace SSARI {

class BoolNot : public BoolUnary {
public:
    BoolNot(shared_ptr<BoolValue> operand) : BoolUnary("~", operand) {
        std::cout << "Constructor Called on " << operand->toString() << std::endl;
    }

    shared_ptr<BoolValue> toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt) {
        return nullptr;
    }

    // This is a problem if it is a complex operand
    string toDimacs(std::string dimacLine, int &refCnt) {
        string opBuff = this->operand->toDimacs("opBuff""", refCnt);
        return dimacLine += "-" + opBuff + " ";
    }
    shared_ptr<BoolValue> getOperand(){
        return this->operand;
    }
};

}

#endif // BOOLNOT_H

