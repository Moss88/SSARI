#include <string>
#include <memory>

#include "Bool/BoolNot.h"
#include "Bool/BoolUnary.h"
#include "Bool/BoolFunc.h"
using std::to_string;
using std::dynamic_pointer_cast;
using std::runtime_error;

namespace SSARI {


BoolNot::BoolNot(shared_ptr<BoolValue> operand) : BoolUnary("~", operand) {    }

shared_ptr<BoolValue> BoolNot::toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt) {
    //this->operand()
    BoolFunc opA(this->operand->toTseitin(tseitin, cnt));
    BoolFunc tVar("T" + to_string(cnt++));
    BoolFunc cnf1 = (!opA | !tVar);
    BoolFunc cnf2 = (opA | tVar);
    tseitin->addOperand(cnf1.getBoolVar());
    tseitin->addOperand(cnf2.getBoolVar());
    return tVar.getBoolVar();
}

void BoolNot::toDimacs(PString& dimacBuff, int &refCnt) {
    dimacBuff.push_back("-");
    this->operand->toDimacs(dimacBuff, refCnt);
}

shared_ptr<BoolValue> BoolNot::getOperand(){
    return this->operand;
}


}


