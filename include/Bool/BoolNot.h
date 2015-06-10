#ifndef BOOLNOT_H
#define BOOLNOT_H
#include <string>
#include <memory>

#include "./BoolUnary.h"

using std::to_string;
using std::dynamic_pointer_cast;
using std::runtime_error;

namespace SSARI {

class BoolNot : public BoolUnary {
public:
    BoolNot(shared_ptr<BoolValue> operand);
    shared_ptr<BoolValue> toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt);
    void toDimacs(PString& dimacBuff, int &refCnt);
    shared_ptr<BoolValue> getOperand();
};

}

#endif // BOOLNOT_H

