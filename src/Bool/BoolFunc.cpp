#include "Bool/BoolFunc.h"
#include "Bool/BoolOr.h"
#include "Bool/BoolAnd.h"
#include "Bool/BoolNot.h"
#include "Bool/BoolVar.h"
#include <memory>

using std::dynamic_pointer_cast;
namespace SSARI {
// Constructors
BoolFunc::BoolFunc() : bVar(nullptr){ }

BoolFunc::BoolFunc(string name) {
    bVar = shared_ptr<BoolVar>(new BoolVar(name));
}

BoolFunc::BoolFunc(char const* name) : BoolFunc(std::string(name)) { }

BoolFunc::BoolFunc(shared_ptr<BoolValue> var) : bVar(var) { }

BoolFunc::BoolFunc(bool val) {
    this->bVar = shared_ptr<BoolConstant>(new BoolConstant(val));
}

BoolFunc::BoolFunc(const BoolFunc& rhs) {
    this->bVar = rhs.bVar;
}

// Assignment Overloads
BoolFunc BoolFunc::operator=(const BoolFunc& rhs) {
    this->bVar = rhs.bVar;
    return *this;
}

BoolFunc BoolFunc::operator=(bool val) {
    this->bVar = shared_ptr<BoolConstant>(new BoolConstant(val));
    return *this;
}


// Operator Overloads
BoolFunc BoolFunc::operator|(const BoolFunc& rhs) const{
    if(this->isOne() || rhs.isZero())
        return *this;
    else if(rhs.isOne() || this->isZero())
        return rhs;
    return BoolFunc(shared_ptr<BoolOr>(new BoolOr(this->bVar, rhs.bVar)));
}

BoolFunc BoolFunc::operator&(const BoolFunc& rhs) const {
    if(this->isZero() || rhs.isZero())
        return BoolFunc(false);
    else if(this->isOne())
        return rhs;
    else if(rhs.isOne())
        return *this;
    return BoolFunc(shared_ptr<BoolAnd>(new BoolAnd(this->bVar, rhs.bVar)));
}


BoolFunc BoolFunc::operator!() const{
    if(this->isOne())
        return BoolFunc(shared_ptr<BoolConstant>(new BoolConstant(false)));
    else if(this->isZero())
        return BoolFunc(shared_ptr<BoolConstant>(new BoolConstant(true)));

    if(shared_ptr<BoolNot> notVar = dynamic_pointer_cast<BoolNot>(this->bVar))
        return BoolFunc(notVar->getOperand());
    return BoolFunc(shared_ptr<BoolNot>(new BoolNot(this->bVar)));
}

// Static Operator Overloads
BoolFunc operator&(bool lhs, const BoolFunc& rhs) {
    if(lhs)
        return rhs;
    return BoolFunc(false);
}

BoolFunc operator&(const BoolFunc& lhs, bool rhs) {
    if(rhs)
        return lhs;
    return BoolFunc(false);
}

BoolFunc operator|(bool lhs, const BoolFunc& rhs) {
    if(lhs)
        return BoolFunc(true);
    return rhs;
}

BoolFunc operator|(const BoolFunc& lhs, bool rhs) {
    if(rhs)
        return BoolFunc(true);
    return lhs;
}

// General Members
bool BoolFunc::isSat() {
    // Check for Constants
    if(this->isOne())
        return true;
    else
        return false;

    if(bVar)
        return bVar->getTseitin()->isSat();
    return false;
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
    return "nullptr";
}

bool BoolFunc::isOne() const {
    return this->bVar->isOne();
}

bool BoolFunc::isZero() const {
    return this->bVar->isZero();
}

}

