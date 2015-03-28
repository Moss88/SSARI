/*
 * Constraint.h
 *
 *  Created on: Mar 4, 2015
 *      Author: lukepierc
 */

#ifndef SRC_BOOLLOGIC_CONSTRAINT_H_
#define SRC_BOOLLOGIC_CONSTRAINT_H_
#include <vector>
#include <memory>
#include <CValue.h>
#include <COperator.h>
#include <COperand.h>
using namespace std;

namespace BFAST {

class Constraint : public CValue {
public:
	Constraint(COperator op);
	void addOperand(shared_ptr<CValue> operand);
	COperator getOperator() const;
    void writeXml(xmlpp::Node *parent, string indentation = "") const;
	string toString() const;
	virtual ~Constraint();
private:
	const COperator op;
	vector<shared_ptr<CValue> > operands;
};

} /* namespace BFAST */

#endif /* SRC_BOOLLOGIC_CONSTRAINT_H_ */
