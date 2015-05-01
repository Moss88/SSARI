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

TEST(BoolFunction, TestConstants)
{
    BoolFunc a("a");
    BoolFunc t(true);
    BoolFunc f(false);

    // Basic Constant Testing
    EXPECT_EQ(t.toString(), "T");
    EXPECT_EQ(f.toString(), "F");
    EXPECT_EQ(t.isOne(), true);
    EXPECT_EQ(t.isZero(), false);
    EXPECT_EQ(f.isOne(), false);
    EXPECT_EQ(f.isZero(), true);
    EXPECT_EQ(a.isOne(), false);
    EXPECT_EQ(a.isZero(), false);

    // Expression Testing
    BoolFunc expr = a & t;
    EXPECT_EQ(expr.toString(), "a");
    expr = t & a;
    EXPECT_EQ(expr.toString(), "a");

    expr = a & f;
    EXPECT_EQ(expr.toString(), "F");
    expr = f & a;
    EXPECT_EQ(expr.toString(), "F");

    expr = a | t;
    EXPECT_EQ(expr.toString(), "T");
    expr = t | a;
    EXPECT_EQ(expr.toString(), "T");


    expr = a | f;
    EXPECT_EQ(expr.toString(), "a");
    expr = f | a;
    EXPECT_EQ(expr.toString(), "a");

    expr = !t;
    EXPECT_EQ(expr.toString(), "F");
    expr = !f;
    EXPECT_EQ(expr.toString(), "T");

    // Test Static Overloads
    expr = a | true;
    EXPECT_EQ(expr.toString(), "T");
    expr = true | a;
    EXPECT_EQ(expr.toString(), "T");
    expr = a | false;
    EXPECT_EQ(expr.toString(), "a");
    expr = false | a;
    EXPECT_EQ(expr.toString(), "a");

    expr = a & true;
    EXPECT_EQ(expr.toString(), "a");
    expr = true & a;
    EXPECT_EQ(expr.toString(), "a");
    expr = a & false;
    EXPECT_EQ(expr.toString(), "F");
    expr = false & a;
    EXPECT_EQ(expr.toString(), "F");

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
   BoolFunc a("a");
   BoolFunc b("b");
   BoolFunc c("c");

   BoolFunc unSat1 = a & !a;
   shared_ptr<BoolTseitin> ts = unSat1.getTseitin();
   EXPECT_EQ(ts->isSat(), false);

   BoolFunc unSat2 = (!(a | b)) & a;
   ts = unSat2.getTseitin();
   EXPECT_EQ(ts->isSat(), false);

   BoolFunc sat1 = a & b;
   ts = sat1.getTseitin();
   EXPECT_EQ(ts->isSat(), true);

   BoolFunc sat2 = (!(a & b)) & a;
   ts = sat2.getTseitin();
   EXPECT_EQ(ts->isSat(), true);

   BoolFunc sat3 = (a & b) & (a & !c);
   ts = sat3.getTseitin();
   EXPECT_EQ(ts->isSat(), true);
}




