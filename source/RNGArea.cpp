#include "RNGArea.h"
using namespace MR;

RNGArea::RNGArea(const char *pName) : AreaObj(pName) {
    mGo = true;
}

void RNGArea::init(const JMapInfoIter &rIter) {
    AreaObj::init(rIter);
    connectToSceneAreaObj(this);
}

bool RNGArea::rng() {
    if (mObjArg0 < 0) return false;
    u32 seed = OSGetTick() * 1664525 + 1013904223;
    s32 cSeed = abs(((s32)seed % 100));
    return (cSeed < mObjArg0);
}

void RNGArea::movement() {
    if (mGo && isInVolume(*getPlayerPos())) {
        if (!mObjArg1) mGo = false;
        rng() ? onSwitchA() : offSwitchA();
    }
}

const char* RNGArea::getManagerName() const {
    return "RNGArea";
}