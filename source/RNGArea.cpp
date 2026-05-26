#include "RNGArea.h"
using namespace MR;

RNGArea::RNGArea(const char *pName) : AreaObj(pName) {
    mGo = true;
}

void RNGArea::init(const JMapInfoIter &rIter) {
    AreaObj::init(rIter);
    connectToSceneAreaObj(this);
    mArg0 = mObjArg0;
    mArg1 = mObjArg1;
}

bool RNGArea::rng() {
    if (mArg0 <= 0) return false;
    u32 seed = OSGetTick() * 1664525 + 1013904223;
    s32 cSeed = (s32)(abs(seed % 100));
    //OSReport("[RNGArea] Testing %d vs %d\n", cSeed, mArg0);
    return (cSeed < mArg0);
}

void RNGArea::movement() {
    if (mGo && isInVolume(*getPlayerPos())) {
        mGo = false;
        rng() ? onSwitchA() : offSwitchA();
        if (mArg1) mGo = true;
    }

}

const char* RNGArea::getManagerName() const {
    return "RNGArea";
}