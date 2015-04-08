#include "ssari.h"
#include "gtest/gtest.h"
#include <memory>
using namespace SSARI;
using namespace std;



TEST(BoolFunction, TestOperators) {
    // Impelement (A & B) | ((C | D) & E)
   BoolFunc a("a");
   BoolFunc b("b");
   BoolFunc c("c");
   BoolFunc eq1 = a | b;
   EXPECT_EQ(eq1.toString(), "(a | b)");

   BoolFunc eq2 = eq1 & c;
   EXPECT_EQ(eq2.toString(), "((a | b) & c)");


   BoolFunc eq3 = !eq2;
   EXPECT_EQ(eq3.toString(), "~((a | b) & c)");

}


TEST(BoolFunction, TestDoubleNegation) {
    // Impelement (A & B) | ((C | D) & E)
   BoolFunc a("a");
   BoolFunc nA = !a;
   BoolFunc nnA = !nA;

   EXPECT_EQ(nnA.toString(), "a");

   BoolFunc b("b");
   BoolFunc eq1 = a & b;
   BoolFunc nEq1 = !eq1;
   BoolFunc nnEq1 = !nEq1;

   EXPECT_EQ(nnEq1.toString(), "(a & b)");
}

TEST(BoolFunction, Tseitin) {
    // Impelement (A & B) | ((C | D) & E)
   BoolFunc a("a");
   BoolFunc b("b");
   BoolFunc c("c");

   BoolFunc unSat1 = a & !a;
   cout << "Beginning Tseitin" << endl;
   shared_ptr<BoolTseitin> ts = unSat1.getTseitin();
   cout << unSat1.toString() << endl;
   cout << ts->toString() << endl;
   EXPECT_EQ(ts->isSat(), false);
}

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
/*
    // Convert to Tseitin
    shared_ptr<BoolTseitin> ts = finalEq->getTseitin();
    ts->writeToDimacs("./test_src/outDimacs.cnf");
*/


}






