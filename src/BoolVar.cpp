#include "BoolVar.h"
#include "BoolTseitin.h"
namespace SSARI {


BoolVar::BoolVar(string name) : name(name) {}
void BoolVar::setName(string name) {
    this->name = name;
}

string BoolVar::toString() const {
    return name;
}

void BoolVar::writeXml(xmlpp::Node *parent, string indentation) const {
}


shared_ptr<BoolTseitin> BoolVar::getTseitin() {
    int cnt = 0;
    shared_ptr<BoolTseitin> tseitin = shared_ptr<BoolTseitin>(new BoolTseitin());
    this->toTseitin(tseitin, cnt);
    return tseitin;
}

shared_ptr<BoolVar> BoolVar::toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt) {
    return make_shared<BoolVar>(*this);
}

string tseitinVarName() {
    return "Tseitin";
}

}


