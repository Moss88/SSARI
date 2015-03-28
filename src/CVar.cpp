/*
 * CVar.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: lukepierc
 */

#include <CVar.h>
#include <sstream>
using std::stringstream;
namespace BFAST {

CVar::CVar(string name, string funcName, int idx): name(name), funcName(funcName), idx(idx) {}
CVar::CVar(const CVar& var): name(var.getName()), funcName(var.getFuncName()), idx(var.getIndex()) {}

bool CVar::operator<(const CVar& rhs) const {
	if(this->funcName == rhs.funcName)
	{
		if(this->name == rhs.name)
			return this->idx < rhs.idx;
		return this->name < rhs.name;
	}
	return this->funcName < rhs.name;
}

string CVar::getName() const {
	return this->name;
}

string CVar::getFuncName() const {
	return this->funcName;
}

int CVar::getIndex() const {
	return this->idx;
}

void CVar::writeXml(xmlpp::Node *parent, std::string indentation) const {
    Element *e = parent->add_child("CVar");
    e->set_attribute("name", this->name);
    e->set_attribute("funcName", this->funcName);
    e->set_attribute("idx", std::to_string(this->idx));
}


string CVar::toString() const {
	stringstream ss;
	ss << this->name << "_" << this->idx;
	return ss.str();
}

CVar::~CVar() {
	// TODO Auto-generated destructor stub
}

} /* namespace BFAST */
