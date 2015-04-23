#include "./Numeric/CUnary.h"
#include "./Numeric/COperator.h"

namespace SSARI {

CUnary::CUnary(COperator op) : op(op), operand(nullptr) { }

CUnary::CUnary(COperator op, CValue operand) : op(op), operand(operand) { }

shared_ptr<CValue> CUnary::getOperand() {
    return operand;
}

COperator CUnary::getOperator() const {
    returh op;
}

string CUnary::toString() const{
    return op.toString() + operand->toString();
}

}
