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

#include <RegisterFile.h>
#include "ssari.h"

using namespace SSARI;
using std::cout;
using std::endl;


TEST(RegisterFile, TestRegFile) {
	RegisterFile rFile;

    CVar var("X");
    CFunc constZero(shared_ptr<CUnary>(new CUnary(COperator("="), shared_ptr<CConstant>(new CConstant("0")))));

    rFile.setVar(var, constZero);
    CFunc ret1 = rFile.getVar(var);
    EXPECT_NE(ret1.getCValue(), nullptr);

    CVar var2("Y");
    CFunc constOne(shared_ptr<CUnary>(new CUnary(COperator("="), shared_ptr<CConstant>(new CConstant("1")))));
    rFile.setVar(var2, constOne);
    CFunc ret2 = rFile.getVar(var2);
    EXPECT_NE(ret2.getCValue(), nullptr);
}
