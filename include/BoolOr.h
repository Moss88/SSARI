#ifndef BOOLOR_H
#define BOOLOR_H

#include "BoolBinary.h"

namespace SSARI {

class BoolOr: public BoolBinary {
public:
    BoolOr(shared_ptr<BoolVar> opA, shared_ptr<BoolVar> opB);
    shared_ptr<BoolVar> toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt);

};

}

#endif // BOOLOR_H

