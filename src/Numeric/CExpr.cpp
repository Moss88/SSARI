#include "./Numeric/CExpr.h"


namespace SSARI {

CExpr::CExpr(COperator op) : op(op) {}

vector<shared_ptr<CValue> >::const_iterator CExpr::cbegin() const {
    return this->operands.cbegin();
}
vector<shared_ptr<CValue> >::const_iterator CExpr::cend() const {
    return this->operands.cend();
}
vector<shared_ptr<CValue> >::iterator CExpr::begin() {
    return this->operands.begin();
}

vector<shared_ptr<CValue> >::iterator CExpr::end() {
    return this->operands.end();
}

COperator CExpr::getOperator() const {
    return this->op;
}


}


