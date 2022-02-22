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
        void NeckControl(float bow_angle, float RL_angle);
        void EyeballsControl(spat::Vec2 target, const float distance, const int mode);
    };
}
