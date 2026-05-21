#include "RNGArea.h"

RNGArea::RNGArea(const char *pName) : AreaObj(pName) {
    mRoll = false;
}

void RNGArea::init(const JMapInfoIter &rIter) {
    AreaObj::init(rIter);
    MR::connectToSceneAreaObj(this);
    mArg = mObjArg0;
}

bool RNGArea::rng() {
    mTick = OSGetTick();
    MarioActor *pMarioActor = MarioAccess::getPlayerActor();
    //OSReport("[RNGArea] Tick: %lu\n", mTick);
    u32 seed = mTick * 1664525 + 1013904223;
    s32 check_seed = abs(((s32)seed % 100));
    //OSReport("[RNGArea] Checking %d vs %d\n", check_seed, mArg);
    if (check_seed < mArg) {
        return true;
    }
    else {
        return false;
    }
}

void RNGArea::movement() {
    if (isInVolume(*MR::getPlayerPos()) && !mRoll) {
        mRoll = true;
        //OSReport("[RNGArea] ROLLING\n");
        if (rng()) {
            onSwitchA();
            //OSReport("[RNGArea] SW_A on\n");
        }
        else {
            offSwitchA();
            //OSReport("[RNGArea] SW_A off\n");
        }
    }
}

const char* RNGArea::getManagerName() const {
    return "RNGArea";
}