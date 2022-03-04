#pragma once
#include "KennyJoint.h"

namespace kenny
{
    struct KennyMoveData
    {
        float degree;
        float PantHeight;
        float PantDegree;
        float LeftArmAdd;
        float RightArmAdd;
        float NeckBow;
        float NeckRL;
        bool update;
    };

    class KennyControl : public KennyJoint
    {
    private:
        spat::Vec2 m_point;
        void PantSpineControl(float height, float degree);
        void BadyNeckControl(float& bow_angle, float& RL_angle);
        void FaceNeckControl(float& bow_angle, float& RL_angle);
    public:
        KennyControl(spat::TexQuard2D* quard) 
            : KennyJoint(quard), m_point({0,0})
        {

        }
        void PantFrontMain(KennyMoveData value);
        void EyeballsControl(spat::Vec2 target, const float distance, const int mode);
    };
}
