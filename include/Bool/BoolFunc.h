
#include <memory>
#include "./BoolVar.h"
#include "./BoolTseitin.h"

namespace SSARI {

class BoolFunc {
public:
    BoolFunc();
    BoolFunc(string name);
    BoolFunc(shared_ptr<BoolVar> var);
    BoolFunc operator|(const BoolFunc& rhs);
    BoolFunc operator&(const BoolFunc& rhs);
    BoolFunc operator!();
    shared_ptr<BoolTseitin> getTseitin();
    string toString() const;
    shared_ptr<BoolVar> getBoolVar();
    string getName() const;
    bool isValid() const;


private:
    shared_ptr<BoolVar> bVar;
};

}
