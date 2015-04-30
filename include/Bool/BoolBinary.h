#ifndef BOOLBINARY_H
#define BOOLBINARY_H
#include <memory>
#include <string>
#include <vector>
#include "./BoolValue.h"

using std::shared_ptr;
using std::string;
using std::vector;

namespace xmlpp {
    class Node;
}


namespace SSARI {
class BoolBinary : public BoolValue {
public:
    BoolBinary(string op, shared_ptr<BoolValue> opA, shared_ptr<BoolValue> opB);
    string toString() const;
    void writeXml(xmlpp::Node *parent, string indentation = "") const;
    string toDimacs(string dimacLine, int &refCnt);
    bool isOne() const;
    bool isZero() const;
    ~BoolBinary();
protected:
    void clearRef();
    string op;
    vector< shared_ptr<BoolValue> > operands;
};

}

#endif // BOOLBINARY

