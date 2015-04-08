#ifndef BOOLVAR_H
#define BOOLVAR_H
#include <memory>
#include "./BoolValue.h"

using std::make_shared;
using std::shared_ptr;
namespace SSARI {

class BoolTseitin;
class BoolVar : public BoolValue {
public:
    BoolVar(string name = "");
    void setName(string name);
    int getRef();
    string getName() const;
    void setRef(int num);

    virtual string toString() const;
    virtual void writeXml(xmlpp::Node *parent, string indentation = "") const;
    virtual string toDimacs(std::string dimacLine, int &refCnt);

protected:
    void clearRef();
    virtual shared_ptr<BoolValue> toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt);
    static string tseitinVarName();

private:
    int ref;
    string name;

};


}
#endif // BOOLVAR_H

