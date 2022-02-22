#include "KennyControl.h"
#include "src/Debug.h"
#include "imgui/imgui.h"

namespace kenny
{
    void KennyControl::PantFrontMain(spat::Vec2 point, float degree)
    {
        SetPantFront(point, degree);
        SetBadyFront(m_Joint.PantFront.BadyFront, degree);
        if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmLeft_Open))
        {
            SetArmLeft_Open(m_Joint.BodyFront.ArmLeft_Open, degree );
            if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Paper))
            {
                SetHandLeft_Paper(m_Joint.ArmLeft_Open.HandLeft_Paper, degree );
            }
            else if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Rock))
            {
                SetHandLeft_Rock(m_Joint.ArmLeft_Open.HandLeft_Rock, degree );
            }
        }
        else if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmLeft_Bend))
        {
            SetArmLeft_Bend(m_Joint.BodyFront.ArmLeft_Bend, degree);
            if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Paper))
            {
                SetHandLeft_Paper(m_Joint.ArmLeft_Bend.HandLeft_Paper, degree );
            }
            else if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Rock))
            {
                SetHandLeft_Rock(m_Joint.ArmLeft_Bend.HandLeft_Rock, degree );
            }
        }
        else if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmFrontLeft_Basic))
        {
            SetArmFrontLeft_Basic(m_Joint.BodyFront.ArmFrontLeft_Basic, degree);
            if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Paper))
            {
                SetHandLeft_Paper(m_Joint.ArmFrontLeft_Basic.HandLeft_Paper, degree );
            }
            else if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Rock))
            {
                SetHandLeft_Rock(m_Joint.ArmFrontLeft_Basic.HandLeft_Rock, degree );
            }
        }
        if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmRight_Open))
        {
            SetArmRight_Open(m_Joint.BodyFront.ArmRight_Open, degree );
            if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Paper))
            {
                SetHandRight_Paper(m_Joint.ArmRight_Open.HandRight_Paper, degree );
            }
            else if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Rock))
            {
                SetHandRight_Rock(m_Joint.ArmRight_Open.HandRight_Rock, degree );
            }
        }
        else if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmRight_Bend))
        {
            SetArmRight_Bend(m_Joint.BodyFront.ArmRight_Bend, degree);
            if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Paper))
            {
                SetHandRight_Paper(m_Joint.ArmRight_Bend.HandRight_Paper, degree );
            }
            else if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Rock))
            {
                SetHandRight_Rock(m_Joint.ArmRight_Bend.HandRight_Rock, degree );
            }
        }
        else if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmFrontRight_Basic))
        {
            SetArmFrontRight_Basic(m_Joint.BodyFront.ArmFrontRight_Basic, degree);
            if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Paper))
            {
                SetHandRight_Paper(m_Joint.ArmFrontRight_Basic.HandRight_Paper, degree );
            }
            else if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Rock))
            {
                SetHandRight_Rock(m_Joint.ArmFrontRight_Basic.HandRight_Rock, degree );
            }
        }
        // SetFace(m_Joint.BodyFront.Face, degree);
        // SetEyesFront_Open(m_Joint.Face.EyesFront_Open, degree);
        // SetHatFront(m_Joint.Face.HatFront, degree);
        m_Quard -> DeleteSize(static_cast<int>(Part::HatFront));
        if(m_CurrentStyle.eyebrow == true)
        {
            SetEyebrowLeft(m_Joint.Face.EyebrowLeft, degree);
            SetEyebrowRight(m_Joint.Face.EyebrowRight, degree);
        }
    }

    
    void KennyControl::SetEyeballsPos(spat::Vec2 target, const float distance, const float degree, const int mode)
    {
        if(mode == 1)
        {
            const float ballsize = 400.0f;
            spat::Vec2 trailL;
            spat::Vec2 trailR;
            spat::Vec2 centerL = {m_Joint.Face.EyesFront_Open.x + 90.0f, m_Joint.Face.EyesFront_Open.y};
            spat::Vec2 centerR = {m_Joint.Face.EyesFront_Open.x - 90.0f, m_Joint.Face.EyesFront_Open.y};
            spat::Vec2 posL = {target.x - centerL.x, target.y - centerL.y};
            spat::Vec2 posR = {target.x - centerR.x, target.y - centerR.y};
            float degreeL = atan2(posL.y, posL.x);
            float degreeR = atan2(posR.y, posR.x);
            float lengthL = sqrt(posL.x * posL.x + posL.y * posL.y);
            float lengthR = sqrt(posR.x * posR.x + posR.y * posR.y);
            float sizeL = ballsize * SIN(atan2(lengthL, distance));
            float sizeR = ballsize * SIN(atan2(lengthR, distance));

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

    void KennyControl::Test(float degree)
    {
        const float neck = 500.0;
        if(degree == 0)
            m_Joint.BodyFront.Face.y += neck;
        else
        {
            m_Joint.BodyFront.Face.x += (neck / PI / 2.0 - degree) * (1.0 + COS(PI / 2.0 - degree));
            m_Joint.BodyFront.Face.y += (neck / PI / 2.0 - degree) * (1.0 + SIN(PI / 2.0 - degree));
        }

        SetFace(m_Joint.BodyFront.Face, degree);
        SetEyesFront_Open(m_Joint.Face.EyesFront_Open, degree);
        SetHatFront(m_Joint.Face.HatFront, degree);       
    }
}