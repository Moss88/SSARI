#ifndef CBINARY_H
#define CBINARY_H
#include <memory>
#include <vector>
#include "./CValue.h"
#include "./COperator.h"

using std::shared_ptr;
using std::vector;

namespace SSARI {

class CBinary : public CValue {
public:
    CBinary();
    CBinary(COperator op, shared_ptr<CValue> opA, shared_ptr<CValue> opB);
    void writeXml(xmlpp::Node *parent, string indentation = "") const;
    virtual string toString() const;
    virtual ~CBinary();
private:
    COperator op;
    vector<shared_ptr<CValue> > operands;
};

}
#endif // CBINARY_H

