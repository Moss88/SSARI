#ifndef BOOLBINARY_H
#define BOOLBINARY_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "BoolVar.h"

using std::shared_ptr;
using std::string;
using std::vector;
using std::cout;
using std::endl;


namespace SSARI {

class BoolBinary : public BoolVar {
public:
    BoolBinary(string op, shared_ptr<BoolVar> opA, shared_ptr<BoolVar> opB) : op(op) {
        operands.push_back(opA);
        operands.push_back(opB);
    }

    string toString() const {
        return "(" + operands[0]->toString() + " " + op + " " + operands[1]->toString() + ")";
    }

    void writeXml(xmlpp::Node *parent, string indentation = "") const {}

    string toDimacs(string dimacLine, int &refCnt) {
        for(auto iter = this->operands.begin(); iter != this->operands.end(); iter++)
            dimacLine = (*iter)->toDimacs(dimacLine, refCnt);
        return dimacLine;
    }

protected:
    string op;
    vector< shared_ptr<BoolVar> > operands;
};

}

#endif // BOOLBINARY

