/*
 * registerFile.h
 *
 *  Created on: Feb 18, 2015
 *      Author: lpierce
 */

#ifndef TOOL_INCLUDE_IRNAV_REGISTERFILE_H_
#define TOOL_INCLUDE_IRNAV_REGISTERFILE_H_
#include "./Numeric/CFunc.h"
#include "./Numeric/CVar.h"
#include<memory>
#include<string>
#include<iostream>
#include <stdexcept>
#include <sstream>
#include <unordered_map>
#include <functional>

using std::size_t;
using std::hash;
using std::unordered_map;
using std::shared_ptr;
using std::stringstream;
using std::endl;
using std::string;
using std::cout;
using std::runtime_error;

namespace std {

  template <> struct hash<SSARI::CVar>
  {
    std::size_t operator()(const SSARI::CVar& k) const
    {
      string sKey = k.getFuncName()+"_"+k.getName()+"_"+to_string(k.getIndex());
      return (hash<string>()(sKey));
    }
  };
}

namespace SSARI {

class RegisterFile {
public:
	RegisterFile() {}

    CFunc getVar(const CVar &varName) {
            return CFunc (registers.at(varName));
	}

    void setVar(const CVar &varName, CFunc var)
	{
        if(!var.getCValue())
            throw runtime_error("RegisterFile: null constraint");
        this->registers[varName] =var;
	}

    string dumpRegister() const {
		stringstream ss;
		for(auto iter = registers.begin(); iter != registers.end(); iter++)
            ss << iter->first.getName() << "_" << iter->first.getIndex() << " = " << iter->second.toString() << endl;
		return ss.str();
	}

    unordered_map<CVar, CFunc>::const_iterator cbegin() const {
		return registers.cbegin();
	}

    unordered_map<CVar, CFunc>::const_iterator cend() const {
		return registers.cend();
	}

	virtual ~RegisterFile(){}

protected:
    unordered_map<CVar, CFunc> registers;
};



} /* namespace SSARI */

#endif /* TOOL_INCLUDE_IRNAV_REGISTERFILE_H_ */
