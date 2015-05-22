#ifndef BOOLTSEITIN_H
#define BOOLTSEITIN_H


#include <vector>
#include <memory>
#include <string>

using std::string;
using std::vector;
using std::shared_ptr;



namespace SSARI {
class BoolValue;
class BoolTseitin {
public:
    BoolTseitin();
    void addOperand(shared_ptr<BoolValue> op);
    string toString() const ;
    string writeToDimacs();
    bool isSat();


private:
    vector<shared_ptr<BoolValue> > operands;
};

}

#endif // BOOLTSEITIN_H

