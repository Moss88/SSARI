#include "./Numeric/CBinary.h"
#include <libxml++/document.h>

using xmlpp::Element;
using xmlpp::Node;


namespace SSARI {


CBinary::CBinary() : op(COperator("")) {

}

CBinary::CBinary(COperator op, shared_ptr<CValue> opA, shared_ptr<CValue> opB) : op(op) {
    operands.push_back(opA);
    operands.push_back(opB);
}

string CBinary::toString() const {
    return "(" + operands[0]->toString() + op.toString() + operands[1]->toString() + ")";
}


void CBinary::writeXml(xmlpp::Node *parent, string indentation) const {
    Element *e = parent->add_child("Constraint");
    e->add_child_text("\n" + indentation + "\t");
    this->op.writeXml(e);
    for(auto iter = this->operands.cbegin(); iter != this->operands.cend(); iter++)
    {
        e->add_child_text("\n" + indentation + "\t");
        (*iter)->writeXml(e, indentation + "\t");
    }
    e->add_child_text("\n" + indentation);
}

CBinary::~CBinary() {}

}
