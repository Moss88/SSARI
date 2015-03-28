/*
 * CConstant.h
 *
 *  Created on: Mar 10, 2015
 *      Author: lukepierc
 */

#ifndef INCLUDE_BOOLLOGIC_CCONSTANT_H_
#define INCLUDE_BOOLLOGIC_CCONSTANT_H_
#include <string>
#include <BoolLogic/COperand.h>
using std::string;
namespace BFAST {

class CConstant : public COperand {
public:
	CConstant(string val);
    void writeXml(xmlpp::Node *parent, string indentation = "") const;
	string toString() const;
	virtual ~CConstant();
private:
	string value;
};

} /* namespace BFAST */

#endif /* INCLUDE_BOOLLOGIC_CCONSTANT_H_ */
