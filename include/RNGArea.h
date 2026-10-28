#pragma once
#include "syati.h"

class RNGArea : public AreaObj {
public:
    RNGArea(const char *pName);

    virtual void init(const JMapInfoIter &rIter);
    virtual bool rng();
    virtual void movement();
    virtual const char* getManagerName() const;

    u32 rand;
    s32 res;
    s32 mArg0;
    bool mGo;
};