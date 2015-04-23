#ifndef CUNARY_H
#define CUNARY_H

#include <memory>
#include "CValue.h"

using std::shared_ptr;

namespace SSARI {
class COperator;

class CUnary : public CValue {
public:
    CUnary(COperator op);
    CUnary(COperator op, CValue operand);
    virtual shared_ptr<CValue> getOperand();
    virtual COperator getOperator() const;
    virtual string toString() const;
private:
    COperator op;
    shared_ptr<CValue> operand;
};

}
#endif // CUNARY_H

