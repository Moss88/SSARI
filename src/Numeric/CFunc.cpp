#include "./Numeric/CFunc.h"
#include "./Numeric/CValue.h"
#include "./Numeric/CBinary.h"
#include "./Numeric/CUnary.h"
#include "./Numeric/CVar.h"
#include "./Numeric/CConstant.h"
#include "./Numeric/CITE.h"
#include <memory>
using std::dynamic_pointer_cast;
using std::make_shared;

namespace SSARI {

CFunc::CFunc() {
    this->cVal = nullptr;
}

CFunc::CFunc(shared_ptr<CValue> expr){
    this->cVal = expr;
}

CFunc::CFunc(string var, int idx) {
   this->cVal = shared_ptr<CVar>(new CVar(var, idx));
}


CFunc::CFunc(CVar var) {
   this->cVal = make_shared<CVar>(var);
}

CFunc::CFunc(COperator op, CFunc opA, CFunc opB) {
    this->cVal = shared_ptr<CBinary>(new CBinary(op, opA.getCValue(), opB.getCValue()));
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

CFunc CFunc::operator|(const CFunc& rhs) const {
    return CFunc(shared_ptr<CBinary>(new CBinary(COperator("||"), this->cVal, rhs.cVal)));
}

CFunc CFunc::operator&(const CFunc& rhs) const {
    return CFunc(shared_ptr<CBinary>(new CBinary(COperator("&&"), this->cVal, rhs.cVal)));
}

CFunc CFunc::operator!() const {
    return CFunc(shared_ptr<CUnary>(new CUnary(COperator("!"), this->cVal)));
}

CFunc ite(const CFunc& c, const CFunc &t, const CFunc &e) {
    if(!c.isValid() || !t.isValid() || !e.isValid())
        throw std::runtime_error("CFunc.ite: Invalid input parameter");
    return CFunc(shared_ptr<CITE>(new CITE(c.getCValue(), t.getCValue(), e.getCValue())));
}


CFunc CFunc::eq(const CFunc& rhs) const {
    return CFunc(shared_ptr<CBinary>(new CBinary(COperator("=="), this->cVal, rhs.cVal)));
}

CFunc CFunc::neq(const CFunc& rhs) const {
    return CFunc(shared_ptr<CBinary>(new CBinary(COperator("!="), this->cVal, rhs.cVal)));
}

CFunc CFunc::lt(const CFunc& rhs) const {
    return CFunc(shared_ptr<CBinary>(new CBinary(COperator("<"), this->cVal, rhs.cVal)));
}

CFunc CFunc::lte(const CFunc& rhs) const {
    return CFunc(shared_ptr<CBinary>(new CBinary(COperator("<="), this->cVal, rhs.cVal)));
}

CFunc CFunc::gt(const CFunc& rhs) const {
    return CFunc(shared_ptr<CBinary>(new CBinary(COperator(">"), this->cVal, rhs.cVal)));
}

CFunc CFunc::gte(const CFunc& rhs) const {
    return CFunc(shared_ptr<CBinary>(new CBinary(COperator(">="), this->cVal, rhs.cVal)));
}

bool CFunc::isExpr() const {
    if(dynamic_pointer_cast<CExpr>(this->cVal) == nullptr)
        return false;
    return true;
}

bool CFunc::isVar() const {
    if(dynamic_pointer_cast<CVar>(this->cVal) == nullptr)
        return false;
    return true;
}

bool CFunc::isConst() const {
    if(dynamic_pointer_cast<CConstant>(this->cVal) == nullptr)
        return false;
    return true;
}

bool CFunc::isValid() const {
    if(!this->cVal)
        return false;
    return true;
}

vector<shared_ptr<const CVar>> CFunc::getDependentVars() const {
    vector<shared_ptr<const CVar>> dVars;
    // Ensure it is an expression
    if(!this->isValid())
        return dVars;

    // Setup Perform Recursion
    rGetVars(dVars, this->cVal);
    return dVars;
}

void CFunc::rGetVars(vector<shared_ptr<const CVar>> &vars, shared_ptr<CValue> val) const
{
    if(shared_ptr<const CVar> var = dynamic_pointer_cast<const CVar>(val))
        vars.push_back(var);
    else if(shared_ptr<CExpr> expr = dynamic_pointer_cast<CExpr>(val))
    {
        for(auto iter = expr->begin(); iter != expr->end(); iter++)
            rGetVars(vars, *iter);
    }
}


shared_ptr<CVar> CFunc::toCVar() const {
    if(shared_ptr<CVar> var = dynamic_pointer_cast<CVar>(this->cVal))
        return var;
    return nullptr;
}


shared_ptr<CConstant> CFunc::toConstant() const {
    if(shared_ptr<CConstant> cVar = dynamic_pointer_cast<CConstant>(this->cVal))
        return cVar;
    return nullptr;
}

shared_ptr<CExpr> CFunc::toExpr() const {
    if(shared_ptr<CExpr> expr = dynamic_pointer_cast<CExpr>(this->cVal))
        return expr;
    return nullptr;
}

string CFunc::toString() const {
   if(this->cVal == nullptr)
        return "CFunc Null";
   return this->cVal->toString();
}



}
