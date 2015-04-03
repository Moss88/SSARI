#ifndef BOOLVAR_H
#define BOOLVAR_H
#include <memory>
#include "CValue.h"
using std::make_shared;
using std::shared_ptr;
namespace SSARI {

class BoolVar : public CValue {
public:
    BoolVar(string name = "") : name(name) {}
    void setName(string name) {this->name = name;}
    virtual string toString() const { return name; }
    virtual void writeXml(xmlpp::Node *parent, string indentation = "") const {}
    virtual shared_ptr<BoolVar> toTseitin() {
        return make_shared<BoolVar>(*this);
    }

private:
    string name;

};

}
#endif // BOOLVAR_H

