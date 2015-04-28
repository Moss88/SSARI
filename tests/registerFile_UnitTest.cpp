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
#include <type_traits>

#include <RegisterFile.h>
#include "ssari.h"

using namespace SSARI;
using namespace std;

TEST(RegisterFile, TestRegFile) {
	RegisterFile rFile;

    CVar var("X");
    CFunc constZero(shared_ptr<CConstant>(new CConstant("0")));

    rFile.setVar(var, constZero);
    CFunc ret1 = rFile.getVar(var);
    EXPECT_NE(ret1.getCValue(), nullptr);

    CVar var2("Y");
    CFunc constOne(shared_ptr<CConstant>(new CConstant("1")));
    rFile.setVar(var2, constOne);
    CFunc ret2 = rFile.getVar(var2);
    EXPECT_NE(ret2.getCValue(), nullptr);


    CVar constraintVar("const_8465486");
    CFunc constFive(shared_ptr<CConstant>(new CConstant("5")));
    rFile.setVar(constraintVar, constFive);
    CFunc cRet = rFile.getVar(constraintVar);
    EXPECT_NE(cRet.getCValue(), nullptr);
    EXPECT_EQ(cRet.toString(), "5");

    CVar var3("X");
    rFile.setVar(var3, constOne);
    CFunc ret3 = rFile.getVar(var3);
    EXPECT_NE(ret3.getCValue(), nullptr);
    EXPECT_EQ(ret3.toString(), "1");
}



