/*
 * COperator.h
 *
 *  Created on: Mar 4, 2015
 *      Author: lukepierc
 */

#ifndef SRC_BOOLLOGIC_COPERATOR_H_
#define SRC_BOOLLOGIC_COPERATOR_H_
#include <CValue.h>
namespace BFAST {

class COperator : public CValue {
public:
	COperator(string op);
	string getOperator() const;
	string toString() const;
    void writeXml(xmlpp::Node *parent, string indentation = "") const;

	virtual ~COperator();
private:
	string op;
};

} /* namespace BFAST */

#endif /* SRC_BOOLLOGIC_COPERATOR_H_ */
