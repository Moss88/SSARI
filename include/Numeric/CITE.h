#ifndef CITE_H
#define CITE_H

#include "CTernary.h"

namespace SSARI {
class CITE : public CTernary {
public:
    CITE(shared_ptr<CValue> c, shared_ptr<CValue> t, shared_ptr<CValue> e) : CTernary(COperator("ITE"), c, t, e) {}
};
}
#endif // CITE_H

