#ifndef CUNARY_H
#define CUNARY_H

#include <memory>
#include "CExpr.h"
#include "COperator.h"
using std::shared_ptr;

namespace SSARI {
class COperator;

class CUnary : public CExpr {
public:
    CUnary(COperator op);
    CUnary(COperator op, shared_ptr<CValue> operand);
    void writeXml(xmlpp::Node *parent, string indentation = "") const;
    virtual shared_ptr<CValue> getOperand();
    virtual string toString() const;
    virtual ~CUnary();
};

}
#endif // CUNARY_H

