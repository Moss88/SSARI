#include "./Bool/BoolConstant.h"
using std::runtime_error;

namespace SSARI {

BoolConstant::BoolConstant(bool val) : val(val) {}

string BoolConstant::toString() const
{
    if(val)
        return "T";
    return "F";
}

void BoolConstant::writeXml(xmlpp::Node *parent, string indentation) const  {
    throw runtime_error("BoolConstant: not support for writing xml");
}


void BoolConstant::toDimacs(PString& dimacBuffer, int &refCnt) {
    throw runtime_error("BoolConstant: should not be present for dimac conversion");
}

shared_ptr<BoolValue> BoolConstant::toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt) {
    throw runtime_error("BoolConstant: should not be present fro toTseitin transform");
}

bool BoolConstant::isOne() const {
    if(val)
        return true;
    return false;
}

bool BoolConstant::isZero() const {
    return !(this->isOne());
}

void BoolConstant::clearRef() {}

}
