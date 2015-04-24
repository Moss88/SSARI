#ifndef CEXPR
#define CEXPR

#include "CValue.h"
#include "COperator.h"
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

namespace SSARI {

class CExpr : public CValue {
public:
    CExpr(COperator op);
    virtual COperator getOperator() const;
    virtual vector<shared_ptr<CValue> >::const_iterator cbegin() const;
    virtual vector<shared_ptr<CValue> >::const_iterator cend() const;
    virtual vector<shared_ptr<CValue> >::iterator begin();
    virtual vector<shared_ptr<CValue> >::iterator end();
protected:
    COperator op;
    vector<shared_ptr<CValue> > operands;
};


}

#endif // CEXPR

