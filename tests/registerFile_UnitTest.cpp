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

#include "../include/IRNav/RegisterFile.h"
using namespace BFAST;
using std::cout;
using std::endl;

struct Func {
	string varName;
	int num;
	Func(string v, int n): varName(v), num(n) {}
};

TEST(RegisterFile, TestRegFile) {
	RegisterFile rFile;
	/*
	rFile.setVar(new Func("a", 0));
	rFile.setVar(new Func("b", 1));
	rFile.setVar(new Func("c", 2));
	EXPECT_EQ(rFile.getVar("a")->num, 0);
	EXPECT_EQ(rFile.getVar("b")->num, 1);
	EXPECT_EQ(rFile.getVar("c")->num, 2);*/
}
