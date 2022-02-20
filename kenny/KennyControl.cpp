#include "KennyControl.h"
#include "src/Debug.h"

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
            if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Paper))
            {
                SetHandRight_Paper(m_Joint.ArmRight_Open.HandRight_Paper, degree );
            }
            else if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Rock))
            {
                SetHandRight_Rock(m_Joint.ArmRight_Open.HandRight_Rock, degree );
            }
        }
        else if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmRight_Bend))
        {
            SetArmRight_Bend(m_Joint.BodyFront.ArmRight_Bend, degree);
            if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Paper))
            {
                SetHandRight_Paper(m_Joint.ArmRight_Bend.HandRight_Paper, degree );
            }
            else if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Rock))
            {
                SetHandRight_Rock(m_Joint.ArmRight_Bend.HandRight_Rock, degree );
            }
        }
        else if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmFrontRight_Basic))
        {
            SetArmFrontRight_Basic(m_Joint.BodyFront.ArmFrontRight_Basic, degree);
            if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Paper))
            {
                SetHandRight_Paper(m_Joint.ArmFrontRight_Basic.HandRight_Paper, degree );
            }
            else if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Rock))
            {
                SetHandRight_Rock(m_Joint.ArmFrontRight_Basic.HandRight_Rock, degree );
            }
        }
        SetFace(m_Joint.BodyFront.Face, degree);
        SetEyesFront_Open(m_Joint.Face.EyesFront_Open, degree);
        SetEyeballLeft(m_Joint.EyesFront_Open.EyeballLeft, degree);
        SetEyeballRight(m_Joint.EyesFront_Open.EyeballRight, degree);
        SetHatFront(m_Joint.Face.HatFront, degree);
        if(m_CurrentStyle.eyebrow == true)
        {
            SetEyebrowLeft(m_Joint.Face.EyebrowLeft, degree);
            SetEyebrowRight(m_Joint.Face.EyebrowRight, degree);
        }
    }

    void KennyControl::Test(spat::Vec2 point, float height, float compact)
    {
        spat::Vec2 posL;
        spat::Vec2 posR;
        float degree1 = PI - asin(height / 1.2232080958047292571970774274258) + 0.44806334134395240307231595147263;
        float degree2 = PI - asin(height / 1.2232080958047292571970774274258) - 0.44806334134395240307231595147263;
        const double sind = SIN(0.558505); //0.52991926423320495404678115181609 A
        const double cosd = COS(0.558505); //0.84804809615642597038617617869039 B

        SetEyesFront_Open(point, 0);

        posL.x = compact * SIN(degree1);
        posL.y = compact * COS(degree1) * 1.3f;
        posR.x = compact * SIN(degree2);
        posR.y = compact * COS(degree2) * 1.3f;
        posL = m_Quard -> Vec2Rotation({0, 0}, posL, sind, cosd);
        posR = m_Quard -> Vec2Rotation({0, 0}, posR, sind * (-1), cosd);
        m_Joint.EyesFront_Open.EyeballLeft.x += posL.x;
        m_Joint.EyesFront_Open.EyeballLeft.y += posL.y;
        m_Joint.EyesFront_Open.EyeballRight.x += posR.x;
        m_Joint.EyesFront_Open.EyeballRight.y += posR.y;
        SetEyeballLeft(m_Joint.EyesFront_Open.EyeballLeft, 0);
        SetEyeballRight(m_Joint.EyesFront_Open.EyeballRight, 0);
    }
}