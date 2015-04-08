#ifndef BOOLOR_H
#define BOOLOR_H

#include "./BoolBinary.h"

namespace SSARI {

class BoolOr: public BoolBinary {
public:
    BoolOr(shared_ptr<BoolValue> opA, shared_ptr<BoolValue> opB);
protected:
    shared_ptr<BoolValue> toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt);

};

}

#endif // BOOLOR_H

