#ifndef CTERNARY_H
#define CTERNARY_H

#include "CExpr.h"

namespace SSARI {

class CTernary : public CExpr {
public:
    CTernary();
    CTernary(COperator op, shared_ptr<CValue> opA, shared_ptr<CValue> opB, shared_ptr<CValue> opC);
    void writeXml(xmlpp::Node *parent, string indentation = "") const;
    virtual string toString() const;
    virtual ~CTernary();
};
}
#endif // CTERNARY_H

