/*
 * CConstant.h
 *
 *  Created on: Mar 10, 2015
 *      Author: lukepierc
 */

#ifndef INCLUDE_BOOLLOGIC_CCONSTANT_H_
#define INCLUDE_BOOLLOGIC_CCONSTANT_H_
#include <string>
#include "COperand.h"
using std::string;
namespace SSARI {

class CConstant : public COperand {
public:
	CConstant(string val);
//    void writeXml(xmlpp::Node *parent, string indentation = "") const;
	string toString() const;
    string getValue() const;
    bool isConstant() const;
	virtual ~CConstant();
private:
	string value;
};

} /* namespace SSARI */

#endif /* INCLUDE_BOOLLOGIC_CCONSTANT_H_ */
