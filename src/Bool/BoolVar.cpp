#include "Bool/BoolVar.h"
#include "Bool/BoolTseitin.h"
#include "Bool/BoolOr.h"
#include <string>

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

void BoolVar::clearRef() {
    this->ref = -1;
}



shared_ptr<BoolValue> BoolVar::toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt) {
    return shared_from_this();
}

string tseitinVarName() {
    return "Tseitin";
}

string BoolVar::toDimacs(string dimacLine, int &refCnt) {
    if(this->ref == -1){
        this->ref = refCnt++;
    }
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
