#ifndef BOOLNOT_H
#define BOOLNOT_H
#include <string>

#include "BoolUnary.h"
using std::to_string;
namespace SSARI {

class BoolNot : public BoolUnary {
public:
    BoolNot(shared_ptr<BoolVar> operand) : BoolUnary("~", operand) {}
    string toDimacs(std::string dimacLine, int &refCnt) {
        if(this->operand->getRef() == -1)
            this->operand->setRef(refCnt++);
        return dimacLine += "-" + to_string(this->operand->getRef()) + " ";
    }
};

}

#endif // BOOLNOT_H

