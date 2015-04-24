#ifndef SVALUE_H
#define SVALUE_H
/*
 * CValue.h
 *
 *  Created on: Mar 4, 2015
 *      Author: lukepierc
 */


#include <string>
using std::string;

namespace SSARI {

class SValue {
public:
    SValue(){};
    virtual string toString() const = 0;
    virtual ~SValue(){};
};

} /* namespace SSARI */


#endif // VALUE_H

