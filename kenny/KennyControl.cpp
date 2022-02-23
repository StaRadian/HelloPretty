#include "KennyControl.h"
#include "src/Debug.h"
#include "imgui/imgui.h"

namespace kenny
{
    void KennyControl::PantFrontMain(spat::Vec2 point, float degree)
    {
        SetPantFront(point, degree);
        SetBadyFront(m_Joint.PantFront.BadyFront, degree, static_cast<int>(Part::PantFront));
        if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmLeft_Open))
        {
            SetArmLeft_Open(m_Joint.BadyFront.ArmLeft_Open, degree, static_cast<int>(Part::BadyFront));
            if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Paper))
            {
                SetHandLeft_Paper(m_Joint.ArmLeft_Open.HandLeft_Paper, degree, static_cast<int>(Part::ArmLeft_Open));
            }
            else if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Rock))
            {
                SetHandLeft_Rock(m_Joint.ArmLeft_Open.HandLeft_Rock, degree, static_cast<int>(Part::ArmLeft_Open));
            }
        }
        else if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmLeft_Bend))
        {
            SetArmLeft_Bend(m_Joint.BadyFront.ArmLeft_Bend, degree, static_cast<int>(Part::BadyFront));
            if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Paper))
            {
                SetHandLeft_Paper(m_Joint.ArmLeft_Bend.HandLeft_Paper, degree, static_cast<int>(Part::ArmLeft_Bend));
            }
            else if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Rock))
            {
                SetHandLeft_Rock(m_Joint.ArmLeft_Bend.HandLeft_Rock, degree, static_cast<int>(Part::ArmLeft_Bend));
            }
        }
        else if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmFrontLeft_Basic))
        {
            SetArmFrontLeft_Basic(m_Joint.BadyFront.ArmFrontLeft_Basic, degree, static_cast<int>(Part::BadyFront));
            if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Paper))
            {
                SetHandLeft_Paper(m_Joint.ArmFrontLeft_Basic.HandLeft_Paper, degree, static_cast<int>(Part::ArmFrontLeft_Basic));
            }
            else if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Rock))
            {
                SetHandLeft_Rock(m_Joint.ArmFrontLeft_Basic.HandLeft_Rock, degree, static_cast<int>(Part::ArmFrontLeft_Basic));
            }
        }
        if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmRight_Open))
        {
            SetArmRight_Open(m_Joint.BadyFront.ArmRight_Open, degree, static_cast<int>(Part::BadyFront));
            if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Paper))
            {
                SetHandRight_Paper(m_Joint.ArmRight_Open.HandRight_Paper, degree, static_cast<int>(Part::ArmRight_Open));
            }
            else if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Rock))
            {
                SetHandRight_Rock(m_Joint.ArmRight_Open.HandRight_Rock, degree, static_cast<int>(Part::ArmRight_Open));
            }
        }
        else if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmRight_Bend))
        {
            SetArmRight_Bend(m_Joint.BadyFront.ArmRight_Bend, degree, static_cast<int>(Part::BadyFront));
            if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Paper))
            {
                SetHandRight_Paper(m_Joint.ArmRight_Bend.HandRight_Paper, degree, static_cast<int>(Part::ArmRight_Bend));
            }
            else if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Rock))
            {
                SetHandRight_Rock(m_Joint.ArmRight_Bend.HandRight_Rock, degree, static_cast<int>(Part::ArmRight_Bend));
            }
        }
        else if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmFrontRight_Basic))
        {
            SetArmFrontRight_Basic(m_Joint.BadyFront.ArmFrontRight_Basic, degree, static_cast<int>(Part::BadyFront));
            if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Paper))
            {
                SetHandRight_Paper(m_Joint.ArmFrontRight_Basic.HandRight_Paper, degree, static_cast<int>(Part::ArmFrontRight_Basic));
            }
            else if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Rock))
            {
                SetHandRight_Rock(m_Joint.ArmFrontRight_Basic.HandRight_Rock, degree, static_cast<int>(Part::ArmFrontRight_Basic));
            }
        }
        // SetFace(m_Joint.BadyFront.Face, degree);
        // SetEyesFront_Open(m_Joint.Face.EyesFront_Open, degree);
        // SetHatFront(m_Joint.Face.HatFront, degree);
        m_Quard -> DeleteSize(static_cast<int>(Part::HatFront));
        if(m_CurrentStyle.eyebrow == true)
        {
            SetEyebrowLeft(m_Joint.Face.EyebrowLeft, m_Joint.Face.degree);
            SetEyebrowRight(m_Joint.Face.EyebrowRight, m_Joint.Face.degree);
        }
    }

    void KennyControl::BadyNeckControl(float& bow_angle, float& RL_angle)
    {
        const float neck = 100.0;
        float neck_height;
        float sind = SIN(m_Joint.BadyFront.degree);
        float cosd = COS(m_Joint.BadyFront.degree);
        spat::Vec2 trail;

        if(bow_angle > PI / 3.0f && bow_angle < (PI * 2.0f) / 3.0f)
        {
            if(RL_angle > (bow_angle - PI / 3.0f) * 3.0f / 8.0f) RL_angle = (bow_angle - PI / 3.0f) * 3.0f / 8.0f;
            else if(RL_angle < (bow_angle - PI / 3.0f) * -3.0f / 8.0f) RL_angle = (bow_angle - PI / 3.0f) * -3.0f / 8.0f;
        }
        

        if(bow_angle == 0)
            neck_height = neck;
        else
            neck_height = neck * SIN(bow_angle) / bow_angle;

        if(RL_angle == 0)
        {
            trail.x = 0;
            trail.y = neck_height;
        }
        else
        {
            trail.x = (neck_height / RL_angle) * (1.0 - COS(RL_angle));
            trail.y = (neck_height / RL_angle) * SIN(RL_angle);
        }
        trail = m_Quard -> Vec2Rotation({0, 0}, {trail.x, trail.y}, sind, cosd);
        trail.x += m_Joint.BadyFront.Face.x;
        trail.y += m_Joint.BadyFront.Face.y;

        SetFace(trail, RL_angle * (-1) + m_Joint.BadyFront.degree);
        SetEyesFront_Open(m_Joint.Face.EyesFront_Open, m_Joint.Face.degree);
        SetHatFront(m_Joint.Face.HatFront, m_Joint.Face.degree);
    }

    void KennyControl::FaceNeckControl(float& bow_angle, float& RL_angle)
    {
        const float neck = -100.0;
        float neck_height;
        float sind = SIN(m_Joint.Face.degree);
        float cosd = COS(m_Joint.Face.degree);
        spat::Vec2 trail;

        if(bow_angle > PI / 3.0f && bow_angle < (PI * 2.0f) / 3.0f)
        {
            if(RL_angle > (bow_angle - PI / 3.0f) * 3.0f / 8.0f) RL_angle = (bow_angle - PI / 3.0f) * 3.0f / 8.0f;
            else if(RL_angle < (bow_angle - PI / 3.0f) * -3.0f / 8.0f) RL_angle = (bow_angle - PI / 3.0f) * -3.0f / 8.0f;
        }
        

        if(bow_angle == 0)
            neck_height = neck;
        else
            neck_height = neck * SIN(bow_angle) / bow_angle;

        if(RL_angle == 0)
        {
            trail.x = 0;
            trail.y = neck_height;
        }
        else
        {
            trail.x = (neck_height / RL_angle) * (1.0 - COS(RL_angle));
            trail.y = (neck_height / RL_angle) * SIN(RL_angle);
        }
        trail = m_Quard -> Vec2Rotation({0, 0}, {trail.x, trail.y}, sind, cosd);
        trail.x += m_Joint.Face.BadyFront.x;
        trail.y += m_Joint.Face.BadyFront.y;

        SetBadyFront(trail, RL_angle * (-1) + m_Joint.Face.degree, static_cast<int>(Part::Face));
    }
    
    void KennyControl::EyeballsControl(spat::Vec2 target, const float distance, const int mode)
    {
        if(mode == 1)
        {
            const float ballsize = 400.0f;
            spat::Vec2 trailL;
            spat::Vec2 trailR;
            spat::Vec2 LRdistance = {
                m_Joint.EyesFront_Open.EyeballLeft.x - m_Joint.EyesFront_Open.EyeballRight.x,
                m_Joint.EyesFront_Open.EyeballLeft.y - m_Joint.EyesFront_Open.EyeballRight.y};
            spat::Vec2 centerL = {m_Joint.Face.EyesFront_Open.x + LRdistance.x, m_Joint.Face.EyesFront_Open.y + LRdistance.y};
            spat::Vec2 centerR = {m_Joint.Face.EyesFront_Open.x - LRdistance.x, m_Joint.Face.EyesFront_Open.y - LRdistance.y};
            spat::Vec2 posL = {target.x - centerL.x, target.y - centerL.y};
            spat::Vec2 posR = {target.x - centerR.x, target.y - centerR.y};
            float degreeL = atan2(posL.y, posL.x);
            float degreeR = atan2(posR.y, posR.x);
            float lengthL = sqrt(posL.x * posL.x + posL.y * posL.y);
            float lengthR = sqrt(posR.x * posR.x + posR.y * posR.y);
            float sizeL = ballsize * SIN(atan2(lengthL, distance));
            float sizeR = ballsize * SIN(atan2(lengthR, distance));

            //후드 필터
            float degreeLhood =  degreeL - m_Joint.EyesFront_Open.degree;
            float degreeRhood =  degreeR - m_Joint.EyesFront_Open.degree;
            for(;degreeLhood > PI;)
            {
                degreeLhood -= PI * 2.0;
            }
            for(;degreeLhood < PI * (-1);)
            {
                degreeLhood += PI * 2.0;
            }
            for(;degreeRhood > PI;)
            {
                degreeRhood -= PI * 2.0;
            }
            for(;degreeRhood < PI * (-1);)
            {
                degreeRhood += PI * 2.0;
            }
            if(degreeLhood < 1.8f && degreeLhood > 0.0f)
            {
                float hoodvaltop = (32.0f / (1.8f * 1.8f)) * degreeLhood * degreeLhood;
                if(sizeL > 33.0f + hoodvaltop) sizeL = 33.0f + hoodvaltop;
            }
            else if(degreeLhood < 0.0f && degreeLhood > -1.3f)
            {
                float hoodvalbottom = (32.0f / (1.3f * 1.3f)) * degreeLhood * degreeLhood;
                if(sizeL > 33.0f + hoodvalbottom) sizeL = 33.0f + hoodvalbottom;
            }
            float topDegreeR = PI - degreeRhood;
            float bottomDegreeR = PI * (-1) - degreeRhood;
            if(topDegreeR > 0.0f && topDegreeR < 1.8f)
            {
                float hoodvaltop = (32.0f / (1.8f * 1.8f)) * topDegreeR * topDegreeR;
                if(sizeR > 33.0f + hoodvaltop) sizeR = 33.0f + hoodvaltop;
            }
            else if(bottomDegreeR > -1.3f && bottomDegreeR < 0.0f)
            {
                float hoodvalbottom = (32.0f / (1.3f * 1.3f)) * bottomDegreeR * bottomDegreeR;
                if(sizeR > 33.0f + hoodvalbottom) sizeR = 33.0f + hoodvalbottom;
            }

            if(sizeL > 65.0f) sizeL = 65.0f;
            if(sizeR > 65.0f) sizeR = 65.0f;
            
            trailL.x = sizeL * COS(degreeL);
            trailL.y = sizeL * SIN(degreeL);
            trailR.x = sizeR * COS(degreeR);
            trailR.y = sizeR * SIN(degreeR);

            trailL.x += centerL.x;
            trailL.y += centerL.y;
            trailR.x += centerR.x;
            trailR.y += centerR.y;
            
            SetEyeballLeft(trailL);
            SetEyeballRight(trailR);
        }
        else
        {
            SetEyeballLeft(m_Joint.EyesFront_Open.EyeballLeft);
            SetEyeballRight(m_Joint.EyesFront_Open.EyeballRight);
        }
    }

}