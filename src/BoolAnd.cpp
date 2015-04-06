#include <string>

#include "BoolTseitin.h"
#include "BoolAnd.h"
#include "BoolNot.h"
#include "BoolOr.h"

using namespace std;

namespace SSARI {

BoolAnd::BoolAnd(shared_ptr<BoolVar> opA, shared_ptr<BoolVar> opB) : BoolBinary("&", opA, opB)  {    }

shared_ptr<BoolVar> BoolAnd::toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt) {

    shared_ptr<BoolVar> opA = this->operands[0]->toTseitin(tseitin, cnt);
    shared_ptr<BoolVar> opB = this->operands[1]->toTseitin(tseitin, cnt);

    // Tseitin Vars
    shared_ptr<BoolVar> tVar = shared_ptr<BoolVar>(new BoolVar(/*BoolVar::tseitinVarName()*/ "T" + to_string(cnt++)));
    shared_ptr<BoolNot> nTVar = shared_ptr<BoolNot>(new BoolNot(tVar));

    // x implies a & b
    tseitin->addOperand(shared_ptr<BoolOr>(new BoolOr(nTVar, opA)));  // ~x | a
    tseitin->addOperand(shared_ptr<BoolOr>(new BoolOr(nTVar, opB)));  // ~x | b


    // a & b implies x
    shared_ptr<BoolNot> nOpA = shared_ptr<BoolNot>(new BoolNot(opA));  // ~a
    shared_ptr<BoolNot> nOpB = shared_ptr<BoolNot>(new BoolNot(opB));  // ~b
    shared_ptr<BoolOr> eq3 = shared_ptr<BoolOr>(new BoolOr(nOpA, nOpB));  // (~a | ~b)
    tseitin->addOperand(shared_ptr<BoolOr>(new BoolOr(eq3, tVar)));  // (~a | ~b | x )

    return tVar;
}

}


