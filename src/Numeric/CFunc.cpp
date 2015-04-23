#include "./Numeric/CFunc.h"
#include "./Numeric/CValue.h"
#include "./Numeric/CBinary.h"
#include "./Numeric/CUnary.h"
#include "./Numeric/CVar.h"

using std::make_shared;

namespace SSARI {

CFunc::CFunc() {
    this->cVal = nullptr;
}

CFunc::CFunc(shared_ptr<CValue> expr){
    this->cVal = expr;
}

CFunc::CFunc(string var, string funcName, int idx) {
   this->cVal = shared_ptr<CVar>(new CVar(var, funcName, idx));
}


CFunc::CFunc(CVar var) {
   this->cVal = make_shared<CVar>(var);
}


shared_ptr<CValue> CFunc::getCValue() const {
    return this->cVal;
}


CFunc CFunc::operator+(const CFunc& rhs) const {
    return CFunc(shared_ptr<CBinary>(new CBinary(COperator("+"), this->cVal, rhs.cVal)));
}

CFunc CFunc::operator-(const CFunc& rhs) const {
    return CFunc(shared_ptr<CBinary>(new CBinary(COperator("-"), this->cVal, rhs.cVal)));
}

CFunc CFunc::operator*(const CFunc& rhs) const {
    return CFunc(shared_ptr<CBinary>(new CBinary(COperator("*"), this->cVal, rhs.cVal)));
}

CFunc CFunc::operator/(const CFunc& rhs) const {
    return CFunc(shared_ptr<CBinary>(new CBinary(COperator("/"), this->cVal, rhs.cVal)));
}

CFunc CFunc::operator-() const {
    return CFunc(shared_ptr<CUnary>(new CUnary(COperator("-"), this->cVal)));
}

string CFunc::toString() const {
   if(this->cVal == nullptr)
        return "CFunc Null";
   return this->cVal->toString();
}



}
