#ifndef BOOLVALUE_H
#define BOOLVALUE_H

#include <string>

using std::make_shared;
using std::shared_ptr;


namespace xmlpp {
class Element;
class Node;
}

namespace SSARI {
class BoolTseitin;


class BoolValue {

public:
    virtual string toString() const = 0;
    virtual void writeXml(xmlpp::Node *parent, string indentation = "") const = 0;
    virtual shared_ptr<BoolTseitin> getTseitin() const = 0;
    virtual string toDimacs(std::string dimacLine, int &refCnt) = 0;

protected:
    virtual shared_ptr<BoolValue> toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt) = 0;
    static string tseitinVarName();

};

#endif // BOOLVALUE_H

