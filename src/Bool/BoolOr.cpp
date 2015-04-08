#include <string>
#include "Bool/BoolOr.h"
#include "Bool/BoolNot.h"
#include "Bool/BoolTseitin.h"
#include "Bool/BoolVar.h"
using namespace std;
namespace SSARI {

BoolOr::BoolOr(shared_ptr<BoolValue> opA, shared_ptr<BoolValue> opB) : BoolBinary("|", opA, opB) {}


shared_ptr<BoolValue> BoolOr::toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt) {

    shared_ptr<BoolValue> opA = this->operands[0]->toTseitin(tseitin, cnt);
    shared_ptr<BoolValue> opB = this->operands[1]->toTseitin(tseitin, cnt);

    // Tseitin Vars
    shared_ptr<BoolVar> tVar = shared_ptr<BoolVar>(new BoolVar(/*BoolVar::tseitinVarName()*/ "T" + to_string(cnt++)));
    shared_ptr<BoolNot> nTVar = shared_ptr<BoolNot>(new BoolNot(tVar));

    // x implies a | b | ~x
    shared_ptr<BoolOr> eq1 = shared_ptr<BoolOr>(new BoolOr(opA, opB));  // ~x | a
    shared_ptr<BoolOr> eq2 = shared_ptr<BoolOr>(new BoolOr(eq1, nTVar));  // ~x | b
    tseitin->addOperand(eq2);


    // a | b implies (~a | x ) & (~b | y)
    shared_ptr<BoolNot> nOpA = shared_ptr<BoolNot>(new BoolNot(opA));  // ~a
    shared_ptr<BoolNot> nOpB = shared_ptr<BoolNot>(new BoolNot(opB));  // ~b
    tseitin->addOperand(shared_ptr<BoolOr>(new BoolOr(nOpA, tVar)));
    tseitin->addOperand(shared_ptr<BoolOr>(new BoolOr(nOpB, tVar)));

    return tVar;
}

}
