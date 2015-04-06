#ifndef BOOLUNARY_H
#define BOOLUNARY_H

#include <memory>
#include <string>
#include "BoolVar.h"

using std::shared_ptr;
using std::string;

namespace SSARI {

class BoolUnary : public BoolVar {
public:
    BoolUnary(string op, shared_ptr<BoolVar> operand) : op(op), operand(operand) {}
    string toString() const { return op + operand->toString();}
    void writeXml(xmlpp::Node *parent, string indentation = "") const {}

protected:
    string op;
    shared_ptr<BoolVar> operand;
};

}
#endif // BOOLUNARY_H

