/*
 * COperator.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: lukepierc
 */

#include <COperator.h>
#include <libxml++/document.h>
using xmlpp::Element;
namespace SSARI {

COperator::COperator(string op) : op(op){
}

string COperator::getOperator() const {
	return this->op;
}


string COperator::toString() const {
	return op;
}

void COperator::writeXml(xmlpp::Node *parent, string indentation) const {
    Element *e = parent->add_child("COperator");
    e->set_attribute("operator", this->op);
}

COperator::~COperator() {
}

} /* namespace SSARI */
