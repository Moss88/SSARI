/*
 * CVar.h
 *
 *  Created on: Mar 10, 2015
 *      Author: lukepierc
 */

#ifndef INCLUDE_BOOLLOGIC_CVAR_H_
#define INCLUDE_BOOLLOGIC_CVAR_H_
#include "COperand.h"
namespace SSARI {

class CVar : public COperand {
public:
    CVar(string name, int idx = 0);
    CVar(const CVar& var);
    void writeXml(xmlpp::Node *parent, string indentation = "") const;
	bool 	operator<(const CVar& rhs) const;
	string 	toString() const;
	string 	getName() const;
	int 	getIndex() const;
    bool operator==(const CVar& rhs) const;
	virtual ~CVar();
private:
    string name;
    int idx;
};

} /* namespace SSARI */

#endif /* INCLUDE_BOOLLOGIC_CVAR_H_ */
