#ifndef VALUE_H
#define VALUE_H
/*
 * CValue.h
 *
 *  Created on: Mar 4, 2015
 *      Author: lukepierc
 */


#include <string>
using std::string;

namespace SSARI {

class Value {
public:
    Value();
    virtual string toString() const = 0;
    virtual ~Value();
};

} /* namespace SSARI */


#endif // VALUE_H

