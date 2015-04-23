#ifndef CFUNC_H
#define CFUNC_H
#include <memory>
#include <string>
using std::string;
using std::shared_ptr;
namespace SSARI {
class CValue;
class CFunc {
public:
    CFunc();
    CFunc(shared_ptr<CValue> expr);
    CFunc operator+(const CFunc& rhs) const;
    CFunc operator-(const CFunc& rhs) const;
    CFunc operator*(const CFunc& rhs) const;
    CFunc operator/(const CFunc& rhs) const;
    string toString() const;
    shared_ptr<getCValue> getCValue();
    bool isValid() const;


private:
    shared_ptr<CValue> cVal;

};
}

#endif // CFUNC_H

