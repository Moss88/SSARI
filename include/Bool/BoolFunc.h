
#include <memory>
#include <Bool/BoolVar.h>
#include <Bool/BoolTseitin.h>

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


private:
    shared_ptr<BoolVar> bVar;
};

}
