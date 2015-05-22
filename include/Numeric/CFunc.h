#ifndef CFUNC_H
#define CFUNC_H
#include <memory>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::shared_ptr;

namespace SSARI {
class CValue;
class CVar;
class CExpr;
class CConstant;
class COperator;
class CFunc {
public:
    CFunc();
    CFunc(shared_ptr<CValue> expr);
    CFunc(string var, string funcName ="", int idx = 0);
    CFunc(COperator op, CFunc opA, CFunc opB);
    CFunc(CVar var);
    CFunc operator+(const CFunc& rhs) const;
    CFunc operator-(const CFunc& rhs) const;
    CFunc operator-() const;
    CFunc operator*(const CFunc& rhs) const;
    CFunc operator/(const CFunc& rhs) const;
    CFunc operator|(const CFunc& rhs) const;
    CFunc operator&(const CFunc& rhs) const;
    CFunc operator!() const;
    // Relational Operators, overloads not used due
    // conflicts with std library
    CFunc eq(const CFunc& rhs) const;
    CFunc neq(const CFunc& rhs) const;
    CFunc lt(const CFunc& rhs) const;
    CFunc lte(const CFunc& rhs) const;
    CFunc gt(const CFunc& rhs) const;
    CFunc gte(const CFunc& rhs) const;

    // Friend Methods
    friend CFunc ite(const CFunc& c, const CFunc &t, const CFunc &e);

    string toString() const;
    shared_ptr<CValue> getCValue() const;
    bool isValid() const;
    bool isExpr() const;
    bool isVar() const;
    bool isConst() const;

    vector<shared_ptr<const CVar>> getDependentVars() const;
    shared_ptr<CVar> toCVar() const;
    shared_ptr<CConstant> toConstant() const;
    shared_ptr<CExpr> toExpr() const;

private:
    shared_ptr<CValue> cVal;

    void rGetVars(vector<shared_ptr<const CVar>> &vars, shared_ptr<CValue> val) const;

};




}


#endif // CFUNC_H

