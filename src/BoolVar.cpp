#include "BoolVar.h"
#include "BoolTseitin.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using namespace std;
namespace SSARI {


BoolVar::BoolVar(string name) : ref(-1), name(name) {}
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

string BoolVar::toDimacs(string dimacLine, int &refCnt) {
    if(this->ref == -1)
        this->ref = refCnt++;
    return dimacLine + to_string(this->ref) + " ";
}


int BoolVar::getRef() {
    return this->ref;
}

void BoolVar::setRef(int num) {
    this->ref = num;
}

string BoolVar::getName() const {
    return this->name;
}

}
