#include "ssari.h"
#include "gtest/gtest.h"

using namespace SSARI;
using namespace std;

class SimpleSymVar : public SymbolicVar {
public:
    SimpleSymVar(string varName) : varName(varName) { }
    string toString() const {return this->varName; }
    string getName() const { return this->varName; }

private:
    string varName;
};

class SimpleMath : public CVarMath {
public:
    // Set Operation
    shared_ptr<SymbolicVar> set(CVar var, shared_ptr<SymbolicVar> expr){ return expr;}

    // Get Operation
    shared_ptr<SymbolicVar> get(shared_ptr<const CConstant> c) {

        return shared_ptr<SimpleSymVar>(new SimpleSymVar(c->toString()));
    }

    // Boolean Operations
    shared_ptr<SymbolicVar>  gt( shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(opA);
        shared_ptr<const SimpleSymVar> b = dynamic_pointer_cast<const SimpleSymVar>(opB);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar(a->getName() + " > " + b->getName()));
    }

    shared_ptr<SymbolicVar>  gte(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(opA);
        shared_ptr<const SimpleSymVar> b = dynamic_pointer_cast<const SimpleSymVar>(opB);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar(a->getName() + " >= " + b->getName()));
    }
    shared_ptr<SymbolicVar>  lt( shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(opA);
        shared_ptr<const SimpleSymVar> b = dynamic_pointer_cast<const SimpleSymVar>(opB);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar(a->getName() + " < " + b->getName()));
    }
    shared_ptr<SymbolicVar>  lte(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(opA);
        shared_ptr<const SimpleSymVar> b = dynamic_pointer_cast<const SimpleSymVar>(opB);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar(a->getName() + " <= " + b->getName()));
    }
    shared_ptr<SymbolicVar>  eq( shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(opA);
        shared_ptr<const SimpleSymVar> b = dynamic_pointer_cast<const SimpleSymVar>(opB);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar(a->getName() + " == " + b->getName()));
    }
    shared_ptr<SymbolicVar>  neq(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(opA);
        shared_ptr<const SimpleSymVar> b = dynamic_pointer_cast<const SimpleSymVar>(opB);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar(a->getName() + " != " + b->getName()));
    }

    // Arithmetic Operations
    shared_ptr<SymbolicVar>  add(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(opA);
        shared_ptr<const SimpleSymVar> b = dynamic_pointer_cast<const SimpleSymVar>(opB);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar(a->getName() + " + " + b->getName()));
    }
    shared_ptr<SymbolicVar>  sub(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(opA);
        shared_ptr<const SimpleSymVar> b = dynamic_pointer_cast<const SimpleSymVar>(opB);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar(a->getName() + " - " + b->getName()));
    }
    shared_ptr<SymbolicVar>  mul(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(opA);
        shared_ptr<const SimpleSymVar> b = dynamic_pointer_cast<const SimpleSymVar>(opB);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar(a->getName() + " * " + b->getName()));
    }
    shared_ptr<SymbolicVar>  div(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(opA);
        shared_ptr<const SimpleSymVar> b = dynamic_pointer_cast<const SimpleSymVar>(opB);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar(a->getName() + " / " + b->getName()));
    }

    // Logical Operations
    shared_ptr<SymbolicVar>  logOr(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(opA);
        shared_ptr<const SimpleSymVar> b = dynamic_pointer_cast<const SimpleSymVar>(opB);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar(a->getName() + " || " + b->getName()));
    }
    shared_ptr<SymbolicVar>  logAnd(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(opA);
        shared_ptr<const SimpleSymVar> b = dynamic_pointer_cast<const SimpleSymVar>(opB);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar(a->getName() + " && " + b->getName()));
    }
    shared_ptr<SymbolicVar>  logNot(shared_ptr<const SymbolicVar> op) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(op);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar("!" + a->getName()));
    }

    // Boolean Operatiosn
    shared_ptr<SymbolicVar>  boolOr(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(opA);
        shared_ptr<const SimpleSymVar> b = dynamic_pointer_cast<const SimpleSymVar>(opB);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar(a->getName() + " | " + b->getName()));
    }
    shared_ptr<SymbolicVar>  boolAnd(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(opA);
        shared_ptr<const SimpleSymVar> b = dynamic_pointer_cast<const SimpleSymVar>(opB);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar(a->getName() + " & " + b->getName()));
    }
    shared_ptr<SymbolicVar>  boolNot(shared_ptr<const SymbolicVar> op) {
        shared_ptr<const SimpleSymVar> a = dynamic_pointer_cast<const SimpleSymVar>(op);
        return shared_ptr<SimpleSymVar>(new SimpleSymVar("~" + a->getName()));
    }

    // Is Satisfiable
    bool isSat(shared_ptr<SymbolicVar> expr) {
        return true;
    }

    // Clears Any History
    void clear() {}
};

TEST(ConstraintProcessor, GenerateSimpleConstaint) {
    RegisterFile rf;
    RegisterFileReader rfReader;
    rfReader.readFile("./test_src/xmlTest.xml", rf);
    if(rfReader.fail())
        cout << rfReader.getError() << endl;
    ASSERT_EQ(rfReader.fail(), false);

    // Invoke Derived Math Class
    SimpleMath sMath;
    ConstraintProcessor cProcessor(&sMath);

    // Create Constraint x == z
    shared_ptr<Constraint> c = shared_ptr<Constraint>(new Constraint(COperator("==")));
    c->addOperand(shared_ptr<CVar>(new CVar("x", "", 0)));
    c->addOperand(shared_ptr<CVar>(new CVar("z", "", 0)));

    // Generate Constraint
    shared_ptr<SymbolicVar> symVar = cProcessor.genConstraint(c, rf);
    shared_ptr<SimpleSymVar> simpleVar = dynamic_pointer_cast<SimpleSymVar>(symVar);
    // Test Output
    EXPECT_EQ(simpleVar->getName(), "6 == 6 + 4");


}





