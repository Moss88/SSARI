#ifndef CBINARY_H
#define CBINARY_H
#include <memory>
#include <vector>
#include "CExpr.h"

using std::shared_ptr;
using std::vector;

namespace SSARI {

class CBinary : public CExpr {
public:
    CBinary();
    CBinary(COperator op, shared_ptr<CValue> opA, shared_ptr<CValue> opB);
    shared_ptr<CValue> getLeftOperand();
    shared_ptr<const CValue> getLeftOperand() const;
    shared_ptr<CValue> getRightOperand();
    shared_ptr<const CValue> getRightOperand() const;
    void writeXml(xmlpp::Node *parent, string indentation = "") const;
    virtual string toString() const;
    virtual ~CBinary();
};

}
#endif // CBINARY_H

