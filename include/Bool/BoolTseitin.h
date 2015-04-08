#ifndef BOOLTSEITIN_H
#define BOOLTSEITIN_H


#include <vector>
#include <memory>
#include "../CValue.h"

using std::vector;
using std::shared_ptr;



namespace SSARI {
class BoolVar;
class BoolTseitin : public CValue {
public:
    BoolTseitin();
    void addOperand(shared_ptr<BoolVar> op);
    string toString() const ;
    void writeXml(xmlpp::Node *parent, string indentation = "") const ;
    bool writeToDimacs(string filePath);
    bool isSat();

private:
    vector<shared_ptr<BoolVar> > operands;
};

}

#endif // BOOLTSEITIN_H

