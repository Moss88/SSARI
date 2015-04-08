#ifndef BOOLAND_H
#define BOOLAND_H



namespace SSARI {

class BoolValue;
class BoolBinary;

class BoolAnd: public BoolBinary {
public:
    BoolAnd(shared_ptr<BoolValue> opA, shared_ptr<BoolValue> opB);
    shared_ptr<BoolValue> toTseitin(shared_ptr<BoolTseitin> tseitin, int &cnt);
};

}


#endif // BOOLAND_H

