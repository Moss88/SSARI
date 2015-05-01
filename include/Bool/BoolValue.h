#ifndef BOOLVALUE_H
#define BOOLVALUE_H

#include <memory>
#include <string>
#include "./BoolTseitin.h"
using std::string;
using std::shared_ptr;


namespace xmlpp {
class Element;
class Node;
}

namespace SSARI {


class BoolValue : public std::enable_shared_from_this<BoolValue> {
friend class BoolBinary;
friend class BoolUnary;
friend class BoolAnd;
friend class BoolOr;
friend class BoolNot;
friend class BoolTseitin;
public:
    virtual string toString() const = 0;
    virtual void writeXml(xmlpp::Node *parent, string indentation = "") const = 0;

    virtual shared_ptr<BoolTseitin> getTseitin() {
        int cnt = 0;
        shared_ptr<BoolTseitin> tseitin = shared_ptr<BoolTseitin>(new BoolTseitin());
        shared_ptr<BoolValue> finalVar = this->toTseitin(tseitin, cnt);
        tseitin->addOperand(finalVar);
        return tseitin;
    }
    virtual bool isOne() const = 0;
    virtual bool isZero() const = 0;
    virtual string toDimacs(std::string dimacLine, int &refCnt) = 0;
    virtual ~BoolValue(){}

protected:
    virtual void clearRef() = 0;
    virtual shared_ptr<BoolValue> toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt) = 0;
    //static string tseitinVarName();

};
}
#endif // BOOLVALUE_H

