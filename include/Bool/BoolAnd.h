#ifndef BOOLAND_H
#define BOOLAND_H



namespace SSARI {

class BoolVar;
class BoolBinary;

class BoolAnd: public BoolBinary {
public:
    BoolAnd(shared_ptr<BoolVar> opA, shared_ptr<BoolVar> opB);
    shared_ptr<BoolVar> toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt);
};

}


#endif // BOOLAND_H

