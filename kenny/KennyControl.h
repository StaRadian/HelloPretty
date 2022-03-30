#pragma once
#include "KennyJoint.h"

namespace kenny
{
    struct EyeballData
    {
        spat::Vec2 target;
        float distance;
        int mode;
    };

    struct KennyMoveData
    {
        float degree;               // PI * (-1), PI
        float PantHeight;           // -25.0, 25.0
        float PantDegree;           // PI / 20.0f * (-1), PI / 20.0f
        float LeftArmAdd;           // -1.5 1.4
        float RightArmAdd;          // -1.4 1.5
        float NeckBow;              // PI / 3.0f, PI
        float NeckRL;               // PI / 8.0f * (-1), PI / 8.0f
        spat::Vec2 LeftHandPos;     // 
        spat::Vec2 RightHandPos;    // 
        float LeftHandDegree;       // 
        float RightHandDegree;      //
        EyeballData EyesData; 
    };

    class KennyControl : public KennyJoint
    {
    private:
        void BadySpineControl(float height, float degree);
        void PantSpineControl(float height, float degree);
        void BadyNeckControl(float& bow_angle, float& RL_angle);
        void FaceNeckControl(float& bow_angle, float& RL_angle);
        inline void LeftArmsControl(float& leftArmAdd, float& NeckRL);
        inline void RightArmsControl(float& rightArmAdd, float& NeckRL);
        void EyeballsControlLeft(EyeballData& value, spat::Vec2& LRdistance);
        void EyeballsControlRight(EyeballData& value, spat::Vec2& LRdistance);
    public:
        spat::Vec2 m_point;
        KennyControl(spat::TexQuard2D* quard) 
            : KennyJoint(quard), m_point({0,0})
        {

        }
        void PantFrontMain(KennyMoveData& value);
        void BadyFrontMain(KennyMoveData& value);
        void FaceMain(KennyMoveData& value);
        void LeftArmMain(KennyMoveData& value);
        void RightArmMain(KennyMoveData& value);
        void LeftHandMain(KennyMoveData& value);
        void RightHandMain(KennyMoveData& value);
    };
}
