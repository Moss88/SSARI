#include "./Numeric/CTernary.h"
//#include <libxml++/document.h>
/*
using xmlpp::Element;
using xmlpp::Node;
*/

namespace SSARI {


CTernary::CTernary() : CExpr(COperator("")) {

}

CTernary::CTernary(COperator op, shared_ptr<CValue> opA, shared_ptr<CValue> opB, shared_ptr<CValue> opC) : CExpr(op) {
    operands.push_back(opA);
    operands.push_back(opB);
    operands.push_back(opC);
}

string CTernary::toString() const {
    return op.toString() + "(" + operands[0]->toString() + "," + operands[1]->toString() + "," + operands[2]->toString() + ")";
}

/*
void CTernary::writeXml(xmlpp::Node *parent, string indentation) const {
    Element *e = parent->add_child("CBinary");
    e->add_child_text("\n" + indentation + "\t");
    this->op.writeXml(e);
    for(auto iter = this->operands.cbegin(); iter != this->operands.cend(); iter++)
    {
        e->add_child_text("\n" + indentation + "\t");
        (*iter)->writeXml(e, indentation + "\t");
    }
    e->add_child_text("\n" + indentation);
}
*/
CTernary::~CTernary() {}

}
