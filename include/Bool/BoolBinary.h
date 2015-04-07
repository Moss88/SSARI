#ifndef BOOLBINARY_H
#define BOOLBINARY_H
#include <memory>
#include <string>
#include <vector>
#include <libxml++/document.h>
#include "./BoolVar.h"

using std::shared_ptr;
using std::string;
using std::vector;



namespace SSARI {
class BoolBinary : public BoolVar {
public:
    BoolBinary(string op, shared_ptr<BoolVar> opA, shared_ptr<BoolVar> opB);
    string toString() const;
    void writeXml(xmlpp::Node *parent, string indentation = "") const;
    string toDimacs(string dimacLine, int &refCnt);
    ~BoolBinary();
protected:
    string op;
    vector< shared_ptr<BoolVar> > operands;
};

}

#endif // BOOLBINARY

