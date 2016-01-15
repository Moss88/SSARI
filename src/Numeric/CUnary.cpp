#include "./Numeric/CUnary.h"
#include "./Numeric/COperator.h"
using std::runtime_error;
namespace SSARI {

CUnary::CUnary(COperator op) : CExpr(op)  { }

CUnary::CUnary(COperator op, shared_ptr<CValue> operand) : CExpr(op) {
    this->operands.push_back(operand);
}

CUnary::~CUnary() {}

shared_ptr<CValue> CUnary::getOperand() {
    if(operands.size() > 0)
        return operands[0];
    return nullptr;
}
/*
void CUnary::writeXml(xmlpp::Node *parent, string indentation) const {
    // TODO Complete this func
    throw runtime_error("IMPLEMENT CUnary writeXML");
}
*/


string CUnary::toString() const {
    return op.toString() + operands[0]->toString();
}

}
