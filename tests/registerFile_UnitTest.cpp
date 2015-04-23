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
#include "CConstant.h"
#include "ConstraintProcessor.h"

using namespace SSARI;
using std::cout;
using std::endl;


TEST(RegisterFile, TestRegFile) {
	RegisterFile rFile;

    CVar var("X");
    shared_ptr<Constraint> c = shared_ptr<Constraint>(new Constraint(COperator("=")));
    c->addOperand(shared_ptr<CConstant>(new CConstant("0")));
    rFile.setVar(var, c);
    shared_ptr<Constraint> ret1 = rFile.getVar(var);
    EXPECT_NE(ret1, nullptr);

    CVar var2("Y");
    shared_ptr<Constraint> c2 = shared_ptr<Constraint>(new Constraint(COperator("=")));
    c2->addOperand(shared_ptr<CConstant>(new CConstant("1")));
    rFile.setVar(var2, c2);
    shared_ptr<Constraint> ret2 = rFile.getVar(var2);
    EXPECT_NE(ret2, nullptr);
}
