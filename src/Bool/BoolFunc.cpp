#include "Bool/BoolFunc.h"
#include "Bool/BoolOr.h"
#include "Bool/BoolAnd.h"
#include "Bool/BoolNot.h"
#include "Bool/BoolVar.h"
#include <memory>
using std::dynamic_pointer_cast;
namespace SSARI {

BoolFunc::BoolFunc() : bVar(nullptr){}

BoolFunc::BoolFunc(string name) {
    bVar = shared_ptr<BoolVar>(new BoolVar(name));
}

BoolFunc::BoolFunc(shared_ptr<BoolValue> var) : bVar(var) {}


BoolFunc BoolFunc::operator|(const BoolFunc& rhs) const{
    return BoolFunc(shared_ptr<BoolOr>(new BoolOr(this->bVar, rhs.bVar)));
}

BoolFunc BoolFunc::operator&(const BoolFunc& rhs) const {
    return BoolFunc(shared_ptr<BoolAnd>(new BoolAnd(this->bVar, rhs.bVar)));
}

BoolFunc BoolFunc::operator!() const{
    if(shared_ptr<BoolNot> notVar = dynamic_pointer_cast<BoolNot>(this->bVar))
        return BoolFunc(notVar->getOperand());
    return BoolFunc(shared_ptr<BoolNot>(new BoolNot(this->bVar)));
}

shared_ptr<BoolTseitin> BoolFunc::getTseitin() {
    if(bVar)
        return bVar->getTseitin();
    return nullptr;
}

shared_ptr<BoolValue> BoolFunc::getBoolVar() {
    return this->bVar;
}

bool BoolFunc::isValid() const {
    if(bVar)
        return true;
    return false;
}

string BoolFunc::toString() const {
    if(bVar)
        return bVar->toString();
    return "";
}



}

