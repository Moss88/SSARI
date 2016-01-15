/*
 * CVar.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: lukepierc
 */

#include <./Numeric/CVar.h>
#include <sstream>
//#include <libxml++/document.h>
using namespace xmlpp;
using std::stringstream;

namespace SSARI {

CVar::CVar(string name, int idx): name(name), idx(idx) {}
CVar::CVar(const CVar& var): name(var.getName()), idx(var.getIndex()) {}


bool CVar::operator<(const CVar& rhs) const {
    if(this->name == rhs.name)
        return this->idx < rhs.idx;
    return this->name < rhs.name;
}

string CVar::getName() const {
	return this->name;
}

int CVar::getIndex() const {
	return this->idx;
}

bool CVar::isVar() const {
    return true;
}
/*
void CVar::writeXml(xmlpp::Node *parent, std::string indentation) const {
    Element *e = parent->add_child("CVar");
    e->set_attribute("name", this->name);
    e->set_attribute("idx", std::to_string(this->idx));
}
*/

string CVar::toString() const {
	stringstream ss;
    ss << this->name << "_" << this->idx;
	return ss.str();
}

bool CVar::operator==(const CVar& rhs) const {
    if((this->name == rhs.name) && (this->idx == rhs.idx))
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& os, const CVar& var) {
    os << var.name << "_" << var.idx;
    return os;
}

CVar::~CVar() { }

} /* namespace SSARI */
