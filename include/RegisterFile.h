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
#include <memory>
#include <string>
#include <stdexcept>
#include <ostream>
#include <unordered_map>
#include <functional>


using std::size_t;
using std::hash;
using std::unordered_map;
using std::shared_ptr;
using std::string;
using std::runtime_error;

namespace std {

  template <> struct hash<SSARI::CVar>
  {
    std::size_t operator()(const SSARI::CVar& k) const
    {
      string sKey = k.getName()+"_"+to_string(k.getIndex());
      return (hash<string>()(sKey));
    }
  };
}

namespace SSARI {

template <typename Func>
class RegisterFile {
public:
    RegisterFile() = default;
    Func getVar(const CVar &varName);
    void setVar(const CVar &varName, Func var);
   
    friend std::ostream& operator<<(std::ostream& os, const RegisterFile<Func> &rf) {
        for(auto &entry:rf.registers)
            os << entry.first << " = " << entry.second << std::endl;
        return os;
    }

    typename unordered_map<CVar, Func>::const_iterator cbegin() const;
    typename unordered_map<CVar, Func>::const_iterator cend() const;
    typename unordered_map<CVar, Func>::iterator begin();
    typename unordered_map<CVar, Func>::iterator end();

    virtual ~RegisterFile();

protected:
    unordered_map<CVar, Func> registers;
};

template<typename Func>
Func RegisterFile<Func>::getVar(const CVar &varName) {
    return registers.at(varName);
}

template<typename Func>
void RegisterFile<Func>::setVar(const CVar &varName, Func var)
{
    this->registers[varName] = var;
}

template<typename Func>
typename unordered_map<CVar, Func>::const_iterator RegisterFile<Func>::cbegin() const {
    return registers.cbegin();
}

template<typename Func>
typename unordered_map<CVar, Func>::const_iterator RegisterFile<Func>::cend() const {
    return registers.cend();
}

template<typename Func>
typename unordered_map<CVar, Func>::iterator RegisterFile<Func>::begin() {
    return registers.begin();
}

template<typename Func>
typename unordered_map<CVar, Func>::iterator RegisterFile<Func>::end() {
return registers.end();
}

template<typename Func>
RegisterFile<Func>::~RegisterFile(){}

}

#endif /* TOOL_INCLUDE_IRNAV_REGISTERFILE_H_ */
