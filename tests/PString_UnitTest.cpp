#include "gtest/gtest.h"
#include "ssari.h"
#include <Bool/PString.h>

using namespace SSARI;

TEST(PString, DefaultSize) {
    PString defaultStr;
    int i;
    for(i = 0; i < 1000; i++)
        defaultStr.push_back("ii");

    auto cstr = defaultStr.c_str();
    for(i = 0; i < 2000; i++)
        EXPECT_EQ(cstr[i], 'i');
    EXPECT_EQ(cstr[i], '\0');

}


TEST(PString, NonDefaultSize) {
    PString str(100);
    for(int i = 0; i < 1000; i++)
        str.push_back("aa");

    auto cstr = str.c_str();
    for(int i = 0; i < 2000; i++)
        EXPECT_EQ(cstr[i], 'a');
    EXPECT_EQ(cstr[2000], '\0');
}
