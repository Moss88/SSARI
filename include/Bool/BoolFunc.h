
#include <memory>
#include "./BoolValue.h"
#include "./BoolTseitin.h"

namespace SSARI {

class BoolFunc {
public:
    BoolFunc();
    BoolFunc(string name);
    BoolFunc(shared_ptr<BoolValue> var);
    BoolFunc operator|(const BoolFunc& rhs) const;
    BoolFunc operator&(const BoolFunc& rhs) const;
    BoolFunc operator!() const;
    shared_ptr<BoolTseitin> getTseitin();
    string toString() const;
    shared_ptr<BoolValue> getBoolVar();
    string getName() const;
    bool isValid() const;
    bool isSat();

private:
    shared_ptr<BoolValue> bVar;
};

}
