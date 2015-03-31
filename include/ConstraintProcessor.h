#ifndef CONSTRAINTPROCESSOR_H
#define CONSTRAINTPROCESSOR_H

#include <SSARI/ssari.h>
#include "CVarMath.h"
using SSARI::CVar;
using SSARI::Constraint;
using SSARI::RegisterFile;
namespace SSARI {

class ConstraintProcessor
{
public:
    ConstraintProcessor(CVarMath *math);
    bool satisfyConstaint(const shared_ptr<Constraint> constraint, RegisterFile &rf);
    ~ConstraintProcessor();

private:
    // Data
    map<CVar, shared_ptr<SymbolicVar> > funcFile;

    // Methods
    shared_ptr<SymbolicVar> processConstraint(CVar var, RegisterFile &rf);

    CVarMath *mathProc;
};

}
#endif // CONSTRAINTPROCESSOR_H
