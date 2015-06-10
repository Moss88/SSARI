#include "gtest/gtest.h"
#include "ssari.h"
#include <Bool/PString.h>

using namespace SSARI;

TEST(PString, DefaultSize) {
    const int numPushes = 1000;
    PString defaultStr;
    int i;
    for(i = 0; i < numPushes; i++)
        defaultStr.push_back("ii");

    auto cstr = defaultStr.c_str();
    for(i = 0; i < numPushes * 2; i++)
        EXPECT_EQ(cstr[i], 'i');
    EXPECT_EQ(cstr[i], '\0');

}


TEST(PString, NonDefaultSize) {
    PString str(100);
    int i;
    for(i = 0; i < 1000; i++)
        str.push_back("aa");

    auto cstr = str.c_str();
    for(i = 0; i < 2000; i++)
        EXPECT_EQ(cstr[i], 'a');
    EXPECT_EQ(cstr[i], '\0');
}

TEST(PString, IntegerPush) {
    PString str;
    unsigned int num = 120;
    str.push_back(num);
    auto cstr = str.c_str();
    EXPECT_EQ(cstr[0], '1');
    EXPECT_EQ(cstr[1], '2');
    EXPECT_EQ(cstr[2], '0');
    EXPECT_EQ(cstr[3], '\0');
}
