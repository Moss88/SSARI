/*
 * CConstant.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: lukepierc
 */

#include <CConstant.h>
#include <libxml++/document.h>
using xmlpp::Element;
namespace SSARI {

CConstant::CConstant(string val) {
	this->value = val;
}

void CConstant::writeXml(xmlpp::Node *parent, std::string indentation) const {
    Element *e = parent->add_child("CConstant");
    e->set_attribute("value", this->value);
}


string CConstant::toString() const{
	return this->value;
}

CConstant::~CConstant() {
	// TODO Auto-generated destructor stub
}

} /* namespace SSARI */
