#pragma once
#include "KennyJoint.h"

namespace kenny
{
    class KennyControl : public KennyJoint
    {
    private:
    public:
        KennyControl(spat::TexQuard2D* quard) 
            : KennyJoint(quard) 
        {

        }
        void PantFrontMain(spat::Vec2 point, float degree);
        void SetEyeballsPos(spat::Vec2 target, const float distance, const float degree, const int mode);
        void Test(float degree);
    };
}
