#ifndef CUNARY_H
#define CUNARY_H

#include <memory>
#include "CValue.h"
#include "COperator.h"
using std::shared_ptr;

namespace SSARI {
class COperator;

class CUnary : public CValue {
public:
    CUnary(COperator op);
    CUnary(COperator op, shared_ptr<CValue> operand);
    void writeXml(xmlpp::Node *parent, string indentation = "") const;
    virtual shared_ptr<CValue> getOperand();
    virtual COperator getOperator() const;
    virtual string toString() const;
    virtual ~CUnary();
private:
    COperator op;
    shared_ptr<CValue> operand;
};

}
#endif // CUNARY_H

