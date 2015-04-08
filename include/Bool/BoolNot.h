#ifndef BOOLNOT_H
#define BOOLNOT_H
#include <string>
#include <iostream>
#include "./BoolUnary.h"
using std::to_string;
namespace SSARI {

class BoolNot : public BoolUnary {
public:
    BoolNot(shared_ptr<BoolVar> operand) : BoolUnary("~", operand) {
        std::cout << "Constructor Called on " << operand->getName() << std::endl;
    }

    shared_ptr<BoolVar> toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt) {

    }

    string toDimacs(std::string dimacLine, int &refCnt) {
        if(this->operand->getRef() == -1)
        {
            std::cout << "Set Ref Count: " << this->operand->getName() << std::endl;
            this->operand->setRef(refCnt++);
        }
        return dimacLine += "-" + to_string(this->operand->getRef()) + " ";
    }
    shared_ptr<BoolVar> getOperand(){
        return this->operand;
    }
};

}

#endif // BOOLNOT_H

