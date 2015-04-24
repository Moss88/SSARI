#ifndef CFUNC_H
#define CFUNC_H
#include <memory>
#include <string>
using std::string;
using std::shared_ptr;

namespace SSARI {
class CValue;
class CVar;
class CExpr;
class CConstant;
class CFunc {
public:
    CFunc();
    CFunc(shared_ptr<CValue> expr);
    CFunc(string var, string funcName ="", int idx = 0);
    CFunc(CVar var);
    CFunc operator+(const CFunc& rhs) const;
    CFunc operator-(const CFunc& rhs) const;
    CFunc operator-() const;
    CFunc operator*(const CFunc& rhs) const;
    CFunc operator/(const CFunc& rhs) const;
    CFunc eq(const CFunc& rhs) const;

    string toString() const;
    shared_ptr<CValue> getCValue() const;
    bool isValid() const;
    bool isExpr() const;
    bool isVar() const;
    bool isConst() const;

    shared_ptr<CVar> toCVar() const;
    shared_ptr<CConstant> toConstant() const;
    shared_ptr<CExpr> toExpr() const;

private:
    shared_ptr<CValue> cVal;

};
}

#endif // CFUNC_H

