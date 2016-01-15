/*
 * Constraint.h
 *
 *  Created on: Mar 4, 2015
 *      Author: lukepierc
 */

#ifndef SRC_BOOLLOGIC_CONSTRAINT_H_
#define SRC_BOOLLOGIC_CONSTRAINT_H_
#define DEPRECATED
#include <vector>
#include <memory>
#include "CValue.h"
#include "COperator.h"
#include "COperand.h"
using namespace std;

namespace SSARI {

class Constraint : public CValue {
public:
	Constraint(COperator op);
	void addOperand(shared_ptr<CValue> operand);
	COperator getOperator() const;
//    void writeXml(xmlpp::Node *parent, string indentation = "") const;
	string toString() const;
    const vector<shared_ptr<CValue> >::const_iterator cbegin() const;
    const vector<shared_ptr<CValue> >::const_iterator cend() const;
	virtual ~Constraint();
private:
	const COperator op;
	vector<shared_ptr<CValue> > operands;
} __attribute__((deprecated));

} /* namespace SSARI */

#endif /* SRC_BOOLLOGIC_CONSTRAINT_H_ */
