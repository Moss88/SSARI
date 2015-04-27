#include <RegisterFileWriter.h>
#include <ssari.h>
#include <string>
#include <fstream>
#include "gtest/gtest.h"
using namespace std;
using namespace SSARI;

TEST(RegisterFileWriter, WriteXMLFile) {
    RegisterFileWriter rfWriter;
    RegisterFile r;

    CVar var1("x");
    CFunc c1(shared_ptr<CConstant>(new CConstant("6")));
    r.setVar(var1, c1);

    CVar var2("y");
    CFunc c2(shared_ptr<CConstant>(new CConstant("4")));
    r.setVar(var2, c2);


    CVar var3 = CVar("z");
    CFunc c3 = CFunc(var1) + CFunc(var2);
    r.setVar(var3, c3);

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
