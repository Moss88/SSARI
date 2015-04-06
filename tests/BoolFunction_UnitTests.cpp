#include "ssari.h"
#include "BoolTseitin.h"
#include "gtest/gtest.h"
#include <memory>
using namespace SSARI;
using namespace std;


TEST(BoolFunction, ToString) {
    // Impelement (A & B) | ((C | D) & E)
    shared_ptr<BoolVar> a = shared_ptr<BoolVar>(new BoolVar("a"));
    shared_ptr<BoolVar> b = shared_ptr<BoolVar>(new BoolVar("b"));
    shared_ptr<BoolVar> c = shared_ptr<BoolVar>(new BoolVar("c"));
    shared_ptr<BoolVar> d = shared_ptr<BoolVar>(new BoolVar("d"));
    shared_ptr<BoolVar> e = shared_ptr<BoolVar>(new BoolVar("e"));


    // (A & B)
    shared_ptr<BoolAnd> eq1 = shared_ptr<BoolAnd>(new BoolAnd(a, b));

    // (C | D)
    shared_ptr<BoolOr> eq2 = shared_ptr<BoolOr>(new BoolOr(c, d));

    // EQ2 & E
    shared_ptr<BoolAnd> eq3 = shared_ptr<BoolAnd>(new BoolAnd(eq2, e));

    // EQ1 | EQ3
    shared_ptr<BoolOr> finalEq = shared_ptr<BoolOr>(new BoolOr(eq1, eq3));
    EXPECT_EQ(finalEq->toString(), "((a & b) | ((c | d) & e))");


    // With Demorgan and Unary Operator
    shared_ptr<BoolUnary> demorg = shared_ptr<BoolUnary>(new BoolUnary("~", finalEq));
    EXPECT_EQ(demorg->toString(), "~((a & b) | ((c | d) & e))");

    // Convert to Tseitin
    shared_ptr<BoolTseitin> ts = finalEq->getTseitin();
    ts->writeToDimacs("./test_src/outDimacs.cnf");



}






