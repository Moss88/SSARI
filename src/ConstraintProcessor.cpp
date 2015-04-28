#include "ConstraintProcessor.h"
#include "./Numeric/CExpr.h"
#include <list>
#include <memory>
using std::list;
namespace SSARI {
ConstraintProcessor::ConstraintProcessor(CVarMath *math) : mathProc(math)
{

}


bool ConstraintProcessor::satisfyConstaint(CFunc constraint, RegisterFile &rf) {

    shared_ptr<SymbolicVar> sVar = this->genConstraint(constraint, rf);
    if(!sVar)
        throw runtime_error("Satifying Equation was NULL");

    // Determine Satisfiablity
    return this->mathProc->isSat(sVar);

}

shared_ptr<SymbolicVar> ConstraintProcessor::genConstraint(CFunc constraint, RegisterFile &rf) {
    // Temp add to register file
    if(!constraint.isValid())
        throw runtime_error("ConstraintProcessor: Null Input Constraint");


    CVar constraintVar("const_8465486");
    rf.setVar(constraintVar, constraint);
    rf.getVar(constraintVar);
    shared_ptr<SymbolicVar> sVar = this->processConstraint(constraintVar, rf);

    return sVar;
}


shared_ptr<SymbolicVar> ConstraintProcessor::processConstraint(CFunc var, RegisterFile &rf) {
    CFunc expr;
    if(var.isVar())
        expr = rf.getVar(*(var.toCVar()));
    else
        expr = var;

    if(expr.isConst())
        return this->mathProc->set(*(var.toCVar()), this->mathProc->get(expr.toConstant()));
    else if(expr.isVar())
        return this->mathProc->set(*(var.toCVar()), this->processConstraint(expr, rf));
    else
    {
        // Assuming it is an expression
        shared_ptr<CExpr> cExpr = expr.toExpr();

        // Get Operands
        vector<shared_ptr<SymbolicVar> > operands;
        for(auto iter = cExpr->begin(); iter != cExpr->end(); iter++)
            operands.push_back(this->processConstraint(CFunc(*iter), rf));

        // Process Operands
        if(operands.size() == 0)
            throw runtime_error("ConstraintProcessor: Expression with no operands");
        else if(operands.size() == 1)
        {
            string op = cExpr->getOperator().getOperator();
            if (op == "!")
                return this->mathProc->logNot(operands.front());
            else if(op == "~")
               return this->mathProc->boolNot(operands.front());
            else
                throw runtime_error("ConstraintProcessor: Unknown operator or too few operands: " + op + " with 1 operand");
        }
        else
        {
            string op = cExpr->getOperator().getOperator();

            // Assume at least two operands
            auto iter = operands.begin();
            shared_ptr<SymbolicVar> opA = *iter;
            iter++;
            shared_ptr<SymbolicVar> opB = *iter;
            iter++;

            while(true)
            {
                if(op == "+")
                    opA = this->mathProc->add(opA, opB);
                else if(op == "-")
                    opA = this->mathProc->sub(opA, opB);
                else if(op == "/")
                    opA = this->mathProc->div(opA, opB);
                else if(op == "*")
                    opA = this->mathProc->mul(opA, opB);
                else if(op == "<")
                    opA = this->mathProc->lt(opA, opB);
                else if(op == "<=")
                    opA = this->mathProc->lte(opA, opB);
                else if(op == ">")
                    opA = this->mathProc->gt(opA, opB);
                else if(op == ">=")
                    opA = this->mathProc->gte(opA, opB);
                else if(op == "==")
                    opA = this->mathProc->eq(opA, opB);
                else if(op == "!=")
                    opA = this->mathProc->neq(opA, opB);
                else if(op == "||")
                    opA = this->mathProc->logOr(opA, opB);
                else if(op == "&&")
                    opA = this->mathProc->logAnd(opA, opB);
                else if(op == "|")
                    opA = this->mathProc->boolOr(opA, opB);
                else if(op == "&")
                    opA = this->mathProc->boolAnd(opA, opB);
                else
                    throw runtime_error("ConstraintProcessor: Invalid Operator " + op + " for " + to_string(operands.size()) + " operands.");

                // Setup  for Next Iteration
                if(iter != operands.end())
                    opB = *(iter++);
                else
                    break;

            }
            return opA;
        }
    }
    return nullptr;
}


ConstraintProcessor::~ConstraintProcessor()
{

}

}
