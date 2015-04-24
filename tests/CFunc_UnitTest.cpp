
/*
 * registerFile_UnitTest.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: lpierce
 */




/*
 * IRFuncVisitor_UnitTest.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: lpierce
 */

#include "gtest/gtest.h"
#include <iostream>
#include "ssari.h"
#include "./Numeric/CFunc.h"
using namespace SSARI;
using std::cout;
using std::endl;


TEST(CFunc, Operations) {
    // Variables for Operation
    CFunc x("X");
    CFunc y("Y");
    CFunc z("Z");

    // Test Expressions
    CFunc expr1 = x + y;
    EXPECT_EQ(expr1.toString(), "(X_0+Y_0)");

    expr1 = x - y;
    EXPECT_EQ(expr1.toString(), "(X_0-Y_0)");

    expr1 = x * y;
    EXPECT_EQ(expr1.toString(), "(X_0*Y_0)");

    expr1 = x / y;
    EXPECT_EQ(expr1.toString(), "(X_0/Y_0)");

    expr1 = x + y * z;
    EXPECT_EQ(expr1.toString(), "(X_0+(Y_0*Z_0))");

}
