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
        void PantSpineControl(float height, float degree);
        void BadyNeckControl(float& bow_angle, float& RL_angle);
        void FaceNeckControl(float& bow_angle, float& RL_angle);
        void EyeballsControl(spat::Vec2 target, const float distance, const int mode);
        void KennySize();
    };
}
