#include "BoolTseitin.h"
#include "BoolVar.h"
namespace SSARI {

BoolTseitin::BoolTseitin() {}


void BoolTseitin::addOperand(shared_ptr<BoolVar> op) {
        operands.push_back(op);
}



string BoolTseitin::toString() const {
    string equation = "";
    for(auto iter = this->operands.begin(); iter != this->operands.end(); iter++)
        equation += (*iter)->toString();
    return equation;
}

void BoolTseitin::writeXml(xmlpp::Node *parent, string indentation) const {}

}

