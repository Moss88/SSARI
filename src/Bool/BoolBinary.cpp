
#include "Bool/BoolBinary.h"
#include "Bool/BoolVar.h"

namespace SSARI {
BoolBinary::BoolBinary(string op, shared_ptr<BoolValue> opA, shared_ptr<BoolValue> opB) : op(op) {
    operands.push_back(opA);
    operands.push_back(opB);
}


string BoolBinary::toString() const {
    return "(" + operands[0]->toString() + " " + op + " " + operands[1]->toString() + ")";
}

void BoolBinary::writeXml(xmlpp::Node *parent, string indentation) const {}

void BoolBinary::clearRef(){
    this->operands[0]->clearRef();
    this->operands[1]->clearRef();
}

bool BoolBinary::isOne() const {
    return false;
}

bool BoolBinary::isZero() const {
    return false;
}

void BoolBinary::toDimacs(PString &dimacBuffer, int &refCnt) {
    for(auto iter = this->operands.begin(); iter != this->operands.end(); iter++)
        (*iter)->toDimacs(dimacBuffer, refCnt);
}

BoolBinary::~BoolBinary() {

}

}
