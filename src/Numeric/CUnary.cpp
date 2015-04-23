#include "./Numeric/CUnary.h"
#include "./Numeric/COperator.h"

namespace SSARI {

CUnary::CUnary(COperator op) : op(op), operand(nullptr) { }

CUnary::CUnary(COperator op, shared_ptr<CValue> operand) : op(op), operand(operand) { }

CUnary::~CUnary() {}

shared_ptr<CValue> CUnary::getOperand() {
    return operand;
}

void CUnary::writeXml(xmlpp::Node *parent, string indentation) const {
    // TODO Complete this func
}

COperator CUnary::getOperator() const {
    return op;
}

string CUnary::toString() const{
    return op.toString() + operand->toString();
}

}
