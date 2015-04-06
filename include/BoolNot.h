#ifndef BOOLNOT_H
#define BOOLNOT_H


#include "BoolUnary.h"

namespace SSARI {

class BoolNot : public BoolUnary {
public:
    BoolNot(shared_ptr<BoolVar> operand) : BoolUnary("~", operand) {}

};

}

#endif // BOOLNOT_H

