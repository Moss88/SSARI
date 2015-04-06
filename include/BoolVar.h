#ifndef BOOLVAR_H
#define BOOLVAR_H
#include <memory>
#include "CValue.h"
//#include "BoolTseitin.h"
using std::make_shared;
using std::shared_ptr;
namespace SSARI {

class BoolTseitin;
class BoolVar : public CValue {
public:
    BoolVar(string name = "");
    void setName(string name);
    virtual string toString() const;
    virtual void writeXml(xmlpp::Node *parent, string indentation = "") const;
    shared_ptr<BoolTseitin> getTseitin();
    virtual shared_ptr<BoolVar> toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt);

protected:

    static string tseitinVarName();

private:
    string name;

};


}
#endif // BOOLVAR_H

