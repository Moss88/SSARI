/*
 * Constraint.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: lukepierc
 */

#include <./Numeric/Constraint.h>

#include <libxml++/document.h>
using namespace xmlpp;

namespace SSARI {

Constraint::Constraint(COperator op) : op(op) {
}

void Constraint::addOperand(shared_ptr<CValue> operand) {
	this->operands.push_back(operand);
}

void Constraint::writeXml(xmlpp::Node *parent, string indentation) const {
    Element *e = parent->add_child("Constraint");
    e->add_child_text("\n" + indentation + "\t");
    this->op.writeXml(e);
    for(auto iter = this->operands.cbegin(); iter != this->operands.cend(); iter++)
    {
        e->add_child_text("\n" + indentation + "\t");
        (*iter)->writeXml(e, indentation + "\t");
    }
    e->add_child_text("\n" + indentation);
}


string Constraint::toString() const{
	string buffer = "(";
	for(auto iter = this->operands.begin(); iter != this->operands.end(); iter++)
	{
		if(iter != this->operands.begin())
			buffer += this->op.toString();
		buffer += (*iter)->toString();
	}
	buffer += ")";
	return buffer;
}

COperator Constraint::getOperator() const {
	return this->op;
}

const vector<shared_ptr<CValue> >::const_iterator Constraint::cbegin() const {
    return operands.cbegin();
}

const vector<shared_ptr<CValue> >::const_iterator Constraint::cend() const {
    return operands.cend();
}


Constraint::~Constraint() {
	// TODO Auto-generated destructor stub
}

} /* namespace SSARI */
