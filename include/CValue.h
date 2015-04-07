/*
 * CValue.h
 *
 *  Created on: Mar 4, 2015
 *      Author: lukepierc
 */

#ifndef SRC_BOOLLOGIC_CVALUE_H_
#define SRC_BOOLLOGIC_CVALUE_H_

#include <string>

namespace xmlpp {
	class Element;
	class Node;
}

using std::string;
namespace SSARI {

class CValue {
public:
	CValue();
	virtual string toString() const = 0;
    virtual void writeXml(xmlpp::Node *parent, string indentation = "") const = 0;
	virtual ~CValue();
};

} /* namespace SSARI */

#endif /* SRC_BOOLLOGIC_CVALUE_H_ */
