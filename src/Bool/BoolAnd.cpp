#include <string>
#include "Bool/BoolBinary.h"
#include "Bool/BoolTseitin.h"
#include "Bool/BoolAnd.h"
#include "Bool/BoolNot.h"
#include "Bool/BoolOr.h"
#include "Bool/BoolFunc.h"

using namespace std;

namespace SSARI {

BoolAnd::BoolAnd(shared_ptr<BoolVar> opA, shared_ptr<BoolVar> opB) : BoolBinary("&", opA, opB)  {    }

shared_ptr<BoolVar> BoolAnd::toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt) {
    cout << "Executed this:" << this->toString() << endl;
    cout << "Op2: " << this->operands[1]->toString() << endl;
    BoolFunc opA(this->operands[0]->toTseitin(tseitin, cnt));
    BoolFunc opB(this->operands[1]->toTseitin(tseitin, cnt));
    cout << "OpB: " <<  opB.toString() << endl;

    // Tseitin Vars
    BoolFunc tVar("T" + to_string(cnt++));
    BoolFunc nTVar = !tVar;

    // x implies a & b
    BoolFunc eq1 = nTVar | opA;
    BoolFunc eq2 = nTVar | opB;
    tseitin->addOperand(eq1.getBoolVar());  // ~x | a
    tseitin->addOperand(eq2.getBoolVar());  // ~x | b
    cout << "EQ1: " << eq1.toString() << endl;
    cout << "EQ2: " << eq1.toString() << endl;

    // a & b implies x
    BoolFunc nOpA = !opA;  // ~a
    BoolFunc nOpB = !opB;  // ~b
    BoolFunc eq3 = nOpA | nOpB;  // (~a | ~b)
    tseitin->addOperand(shared_ptr<BoolOr>(new BoolOr(eq3.getBoolVar(), tVar.getBoolVar())));  // (~a | ~b | x )

    return tVar.getBoolVar();
}

}


