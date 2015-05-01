#ifndef BOOLUNARY_H
#define BOOLUNARY_H

#include <memory>
#include <string>
#include "./BoolValue.h"

using std::shared_ptr;
using std::string;

namespace SSARI {

class BoolUnary : public BoolValue {
public:
    BoolUnary(string op, shared_ptr<BoolValue> operand) : op(op), operand(operand) {}
    string toString() const { return op + operand->toString();}
    void writeXml(xmlpp::Node *parent, string indentation = "") const {}
    bool isOne() const {return false;}
    bool isZero() const {return false;}

protected:
    void clearRef() {operand->clearRef();}
    string op;
    shared_ptr<BoolValue> operand;
};

}
#endif // BOOLUNARY_H

