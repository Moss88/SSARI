
#include <memory>
#include "BoolValue.h"
#include "BoolTseitin.h"
#include "BoolConstant.h"
namespace SSARI {

class BoolFunc {
public:
    // Constructors
    BoolFunc();
    BoolFunc(string name);
    BoolFunc(shared_ptr<BoolValue> var);
    BoolFunc(char const* name);
    BoolFunc(bool val);
    BoolFunc(const BoolFunc& rhs);

    // Assignment Overloads
    BoolFunc operator=(const BoolFunc& rhs);
    BoolFunc operator=(bool val);

    // Operator Overloads
    BoolFunc operator|(const BoolFunc& rhs) const;
    BoolFunc operator&(const BoolFunc& rhs) const;
    BoolFunc operator!() const;

    // General Methods
    shared_ptr<BoolTseitin> getTseitin();
    string toString() const;
    shared_ptr<BoolValue> getBoolVar();
    string getName() const;
    bool isValid() const;
    bool isSat();
    bool isOne() const;
    bool isZero() const;

private:
    shared_ptr<BoolValue> bVar;
};

BoolFunc operator&(bool lhs, const BoolFunc& rhs);
BoolFunc operator&(const BoolFunc& lhs, bool rhs);
BoolFunc operator|(bool lhs, const BoolFunc& rhs);
BoolFunc operator|(const BoolFunc& lhs, bool rhs);

}
