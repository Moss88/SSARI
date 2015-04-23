/*
 * COperand.h
 *
 *  Created on: Mar 4, 2015
 *      Author: lukepierc
 */

#ifndef SRC_BOOLLOGIC_COPERAND_H_
#define SRC_BOOLLOGIC_COPERAND_H_
#include <string>
#include "CValue.h"

using std::string;
namespace SSARI {
// Immutable Class
class COperand : public CValue {
public:
	COperand();
	virtual string toString() const = 0;
    virtual void writeXml(xmlpp::Node *parent, string indentation = "") const = 0;

	virtual ~COperand();
};

} /* namespace SSARI */

#endif /* SRC_BOOLLOGIC_COPERAND_H_ */
