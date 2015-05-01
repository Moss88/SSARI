#ifndef BOOLCONSTANT_H
#define BOOLCONSTANT_H
#include "BoolValue.h"

namespace SSARI {
class BoolConstant : public BoolValue {
public:
    BoolConstant(bool val = true);
    string toString() const;
    void writeXml(xmlpp::Node *parent, string indentation = "") const;
    string toDimacs(std::string dimacLine, int &refCnt);
    bool isOne() const;
    bool isZero() const;

protected:
    void clearRef();
    shared_ptr<BoolValue> toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt);


private:
    bool val;
};

}
#endif // BOOLCONSTANT_H

