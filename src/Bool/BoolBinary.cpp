
#include "Bool/BoolBinary.h"
#include "Bool/BoolVar.h"

namespace SSARI {
BoolBinary::BoolBinary(string op, shared_ptr<BoolVar> opA, shared_ptr<BoolVar> opB) : op(op) {
    operands.push_back(opA);
    operands.push_back(opB);
}


string BoolBinary::toString() const {
    return "(" + operands[0]->toString() + " " + op + " " + operands[1]->toString() + ")";
}

void BoolBinary::writeXml(xmlpp::Node *parent, string indentation) const {}

string BoolBinary::toDimacs(string dimacLine, int &refCnt) {
    for(auto iter = this->operands.begin(); iter != this->operands.end(); iter++)
        dimacLine = (*iter)->toDimacs(dimacLine, refCnt);
    return dimacLine;
}

BoolBinary::~BoolBinary() {

}

}
