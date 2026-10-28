#include "RNGArea.h"
using namespace MR;

RNGArea::RNGArea(const char *pName) : AreaObj(pName) {
    mGo = true;
}

void RNGArea::init(const JMapInfoIter &rIter) {
    AreaObj::init(rIter);
    connectToSceneAreaObj(this);
    mArg0 = mObjArg0;
}

bool RNGArea::rng() {
    if (mArg0 < 1) return false;
    JMath::TRandom_fast_ mRand(OSGetTick());
    rand = abs(mRand.rand());
    res = (s32)(((rand ^ (rand >> 16)) % 100) + 1);
    //OSReport("[RNGArea] Testing %d <= %d\n", res, mArg0);
    return (res <= mArg0);
}

void RNGArea::movement() {
    if (mGo && isInVolume(*getPlayerPos())) {
        mGo = false;
        rng() ? onSwitchA() : offSwitchA();
    }
}

const char* RNGArea::getManagerName() const {
    return "RNGArea";
}