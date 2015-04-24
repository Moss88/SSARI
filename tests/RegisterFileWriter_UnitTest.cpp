#include <RegisterFileWriter.h>
#include <./Numeric/CConstant.h>
#include <string>
#include <fstream>
#include "gtest/gtest.h"
using namespace std;
using namespace SSARI;
TEST(RegisterFileWriter, WriteXMLFile) {
    RegisterFileWriter rfWriter;
    RegisterFile r;

    CVar var1("x");
    Constraint c1(COperator("="));
    c1.addOperand(make_shared<CConstant>(CConstant("6")));
    r.setVar(var1, make_shared<Constraint>(c1));

    CVar var2("y");
    Constraint c2(COperator("="));
    c2.addOperand(make_shared<CConstant>(CConstant("4")));
    r.setVar(var2, make_shared<Constraint>(c2));


    CVar var3 = CVar("z");
    Constraint c3(COperator("+"));
    c3.addOperand(make_shared<CVar>(var1));
    c3.addOperand(make_shared<CVar>(var2));
    r.setVar(var3, make_shared<Constraint>(c3));

    rfWriter.writeFile("./test_src/xmlTest1.xml", r);

    ifstream goldF("./test_src/xmlTest.xml"), testF("./test_src/xmlTest1.xml");
    EXPECT_EQ(goldF.is_open(), true);
    EXPECT_EQ(testF.is_open(), true);
    while(goldF.good() && testF.good())
    {
        string gLine, tLine;
        getline(goldF, gLine);
        getline(testF, tLine);

        EXPECT_EQ(gLine, tLine);
        EXPECT_EQ(testF.good(), goldF.good());
    }

    goldF.close();
    testF.close();

}
