/*
 * CVar.h
 *
 *  Created on: Mar 10, 2015
 *      Author: lukepierc
 */

#ifndef INCLUDE_BOOLLOGIC_CVAR_H_
#define INCLUDE_BOOLLOGIC_CVAR_H_
#include <BoolLogic/COperand.h>
namespace BFAST {

class CVar : public COperand {
public:
	CVar(string name, string funcName = "", int idx = 0);
	CVar(const CVar& var);
    void writeXml(xmlpp::Node *parent, string indentation = "") const;
	bool 	operator<(const CVar& rhs) const;
	string 	toString() const;
	string 	getName() const;
	string 	getFuncName() const;
	int 	getIndex() const;
	virtual ~CVar();
private:
	string name;
	string funcName;
	int idx;
};

} /* namespace BFAST */

#endif /* INCLUDE_BOOLLOGIC_CVAR_H_ */
