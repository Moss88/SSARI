/*
 * registerFile.h
 *
 *  Created on: Feb 18, 2015
 *      Author: lpierce
 */

#ifndef TOOL_INCLUDE_IRNAV_REGISTERFILE_H_
#define TOOL_INCLUDE_IRNAV_REGISTERFILE_H_
#include "Constraint.h"
#include "CVar.h"
#include<memory>
#include<string>
#include<map>
#include<iostream>
#include <stdexcept>
#include <sstream>
using std::shared_ptr;
using std::stringstream;
using std::endl;
using std::string;
using std::map;
using std::cout;
namespace SSARI {

class RegisterFile {
public:
	RegisterFile() {}

	shared_ptr<Constraint> getVar(CVar varName) {
		try {
			return shared_ptr<Constraint> (registers.at(varName));
		} catch(const std::out_of_range& oor) {
			cout << "Error Occurred Fetching " << varName.getName() << " " << varName.getIndex() << " from regFile" << endl;
			return shared_ptr<Constraint>(nullptr);
		}
	}

	void setVar(CVar varName, shared_ptr<Constraint> var)
	{
        if(!var)
            throw runtime_error("RegisterFile: null constraint");

		registers[varName] = var;
	}

	string dumpRegister() {
		stringstream ss;
		for(auto iter = registers.begin(); iter != registers.end(); iter++)
			ss << iter->first.getName() << "_" << iter->first.getIndex() << " = " << iter->second->toString() << endl;
		return ss.str();
	}

	map<CVar, shared_ptr<Constraint>>::const_iterator cbegin() const {
		return registers.cbegin();
	}

	map<CVar, shared_ptr<Constraint>>::const_iterator cend() const {
		return registers.cend();
	}

	virtual ~RegisterFile(){}

protected:
	map<CVar, shared_ptr<Constraint>> registers;
};



} /* namespace SSARI */

#endif /* TOOL_INCLUDE_IRNAV_REGISTERFILE_H_ */
