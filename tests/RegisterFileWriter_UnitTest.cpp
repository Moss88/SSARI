#include <IRNav/RegisterFileWriter.h>
#include <BoolLogic/CConstant.h>

#include "gtest/gtest.h"

using namespace BFAST;
TEST(RegisterFileWriter, WriteXMLFile) {

    RegisterFileWriter rfWriter;
    RegisterFile r;

    CVar var("x");
    Constraint c1(COperator("="));
    c1.addOperand(make_shared<CConstant>(CConstant("6")));
    r.setVar(var, make_shared<Constraint>(c1));

    CVar var2("y");
    Constraint c2(COperator("="));
    c2.addOperand(make_shared<CConstant>(CConstant("4")));
    r.setVar(var2, make_shared<Constraint>(c2));


    var = CVar("z");
    Constraint c3(COperator("+"));
    c3.addOperand(make_shared<CVar>(var));
    c3.addOperand(make_shared<CVar>(var2));
    r.setVar(var, make_shared<Constraint>(c3));

    rfWriter.writeFile("./test_src/xmlTest.xml", r);

}
