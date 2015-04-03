#ifndef BOOLAND_H
#define BOOLAND_H

#include "BoolBinary.h"

namespace SSARI {

class BoolAnd: public BoolBinary {
public:
    BoolAnd(shared_ptr<BoolVar> opA, shared_ptr<BoolVar> opB) : BoolBinary("&", opA, opB)  {    }



};

}


#endif // BOOLAND_H

