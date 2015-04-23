#include "CFunc.h"
namespace SSARI {

CFunc::CFunc() {
    this->cVal = nullptr;
}

CFunc::CFunc(shared_ptr<CValue> expr){
    this->cVal = expr->cVal;
}

CFunc CFunc::operator+(const CFunc& rhs) const {
    return CFunc(shared_ptr())
}

CFunc CFunc::operator-(const CFunc& rhs) const {

}
CFunc CFunc::operator*(const CFunc& rhs) const {

}
CFunc CFunc::operator/(const CFunc& rhs) const {

}



}
