#include <RegisterFileReader.h>
#include "gtest/gtest.h"
using namespace SSARI;
TEST(RegisterFileReader, ReadXMLFile) {
    RegisterFile rf;
    RegisterFileReader rfReader;
    rfReader.readFile("./test_src/xmlTest.xml", rf);
    if(rfReader.fail())
        cout << rfReader.getError() << endl;
    EXPECT_EQ(rfReader.fail(), false);
}
