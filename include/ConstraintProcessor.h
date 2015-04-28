#ifndef CONSTRAINTPROCESSOR_H
#define CONSTRAINTPROCESSOR_H

#include "ssari.h"
#include "CVarMath.h"
using SSARI::CVar;
using SSARI::Constraint;
using SSARI::RegisterFile;
namespace SSARI {

class ConstraintProcessor
{
public:
    ConstraintProcessor(CVarMath *math);
    bool satisfyConstaint(CFunc constraint, RegisterFile &rf);
    shared_ptr<SymbolicVar> genConstraint(CFunc constraint, RegisterFile &rf);
    ~ConstraintProcessor();

private:
    // Data
    //map<CVar, shared_ptr<SymbolicVar> > funcFile;

    // Methods
    shared_ptr<SymbolicVar> processConstraint(CFunc var, RegisterFile &rf);

    CVarMath *mathProc;
};

}
#endif // CONSTRAINTPROCESSOR_H
