#ifndef CVARMATH_H
#define CVARMATH_H
#include "SymbolicVar.h"
#include <memory>
using std::shared_ptr;
namespace SSARI {
class CVarMath {
public:
    // Set Operation
    virtual shared_ptr<SymbolicVar> set(shared_ptr<SymbolicVar> var) = 0;

    // Get Operation
    virtual shared_ptr<const SymbolicVar> get(shared_ptr<const CConstant> c) = 0;

    // Boolean Operations
    virtual shared_ptr<SymbolicVar>  gt( shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) = 0;
    virtual shared_ptr<SymbolicVar>  gte(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) = 0;
    virtual shared_ptr<SymbolicVar>  lt( shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) = 0;
    virtual shared_ptr<SymbolicVar>  lte(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) = 0;
    virtual shared_ptr<SymbolicVar>  eq( shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) = 0;
    virtual shared_ptr<SymbolicVar>  neq(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) = 0;

    // Arithmetic Operations
    virtual shared_ptr<SymbolicVar>  add(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) = 0;
    virtual shared_ptr<SymbolicVar>  sub(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) = 0;
    virtual shared_ptr<SymbolicVar>  mul(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) = 0;
    virtual shared_ptr<SymbolicVar>  div(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) = 0;

    // Logical Operations
    virtual shared_ptr<SymbolicVar>  logOr(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) = 0;
    virtual shared_ptr<SymbolicVar>  logAnd(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) = 0;
    virtual shared_ptr<SymbolicVar>  logNot(shared_ptr<const SymbolicVar> op) = 0;

    // Boolean Operatiosn
    virtual shared_ptr<SymbolicVar>  boolOr(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) = 0;
    virtual shared_ptr<SymbolicVar>  boolAnd(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) = 0;
    virtual shared_ptr<SymbolicVar>  boolNot(shared_ptr<const SymbolicVar> op) = 0;

    // Is Satisfiable
    virtual bool isSat(shared_ptr<SymbolicVar> expr) = 0;

    // Clears Any History
    virtual void clear() = 0;
};

}
#endif // CVARMATH_H

