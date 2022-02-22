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
        SetFace(m_Joint.BodyFront.Face, degree);
        SetEyesFront_Open(m_Joint.Face.EyesFront_Open, degree);
        // SetEyeballLeft(m_Joint.EyesFront_Open.EyeballLeft, degree);
        // SetEyeballRight(m_Joint.EyesFront_Open.EyeballRight, degree);
        // SetHatFront(m_Joint.Face.HatFront, degree);
        m_Quard -> DeleteSize(static_cast<int>(Part::HatFront));
        if(m_CurrentStyle.eyebrow == true)
        {
            SetEyebrowLeft(m_Joint.Face.EyebrowLeft, degree);
            SetEyebrowRight(m_Joint.Face.EyebrowRight, degree);
        }
    }

    
    void KennyControl::SetEyeballsPos(spat::Vec2 target, const float viewSize, const int mode)
    {
        const double sin32 = 0.52991926423320495404678115181609; // SIN(0.558505) 32
        const double cos32 = 0.84804809615642597038617617869039; // COS(0.558505) 32
        
        spat::Vec2 trailL;
        spat::Vec2 trailR;
        float xL = target.x - m_Joint.EyesFront_Open.EyeballLeft.x;
        float yL = target.y - m_Joint.EyesFront_Open.EyeballLeft.y;
        float xR = target.x - m_Joint.EyesFront_Open.EyeballRight.x;
        float yR = target.y - m_Joint.EyesFront_Open.EyeballRight.y;
        float sizeL = sqrt(xL * xL + yL * yL) / 10.0;
        float sizeR = sqrt(xR * xR + yR * yR) / 10.0;
        if(sizeL > 65.0f) sizeL = 65.0f;
        if(sizeR > 65.0f) sizeR = 65.0f;

        spat::Vec2 LellipseCenter = {
            m_Joint.Face.EyesFront_Open.x + (90.0f / 65.0f) * sizeL, m_Joint.Face.EyesFront_Open.y};
        spat::Vec2 RellipseCenter = {
            m_Joint.Face.EyesFront_Open.x - (90.0f / 65.0f) * sizeR, m_Joint.Face.EyesFront_Open.y};

        sizeL = 65.0;
        sizeR = 65.0;

        float posxL = m_Joint.Face.EyesFront_Open.x + 90.0f;
        float posyL = m_Joint.Face.EyesFront_Open.y;
        float posxR = m_Joint.Face.EyesFront_Open.x - 90.0f;
        float posyR = m_Joint.Face.EyesFront_Open.y;

        float degreeL = atan2(target.x - posxL, target.y - posyL);
        float degreeR = atan2(target.x - posxR, target.y - posyR);

        //타원 생성
        trailL.x = sizeL * SIN(degreeL + 0.558505);
        trailL.y = sizeL * COS(degreeL + 0.558505) * 1.3f;
        trailR.x = sizeR * SIN(degreeR - 0.558505);
        trailR.y = sizeR * COS(degreeR - 0.558505) * 1.3f;
        trailL = m_Quard -> Vec2Rotation({0, 0}, trailL, sin32, cos32);
        trailR = m_Quard -> Vec2Rotation({0, 0}, trailR, sin32 * (-1), cos32);
        
        trailL.x += m_Joint.Face.EyesFront_Open.x + 90.0f;
        trailL.y += m_Joint.Face.EyesFront_Open.y;
        trailR.x += m_Joint.Face.EyesFront_Open.x - 90.0f;
        trailR.y += m_Joint.Face.EyesFront_Open.y;
        
        SetEyeballLeft(trailL, 0);
        SetEyeballRight(trailR, 0);
        
        ImGui::Begin("Control");

        ImGui::SliderFloat("degreeL", &degreeL, PI * (-1), PI);
        ImGui::SliderFloat("degreeR", &degreeR, PI * (-1), PI);
        
        ImGui::End();
    }

    void KennyControl::Test(spat::Vec2 point, float height, float compact, const int mode)
    {
        spat::Vec2 posL;
        spat::Vec2 posR;
        const float coef = 1.2232080958047292571970774274258;
        const double sin32 = 0.52991926423320495404678115181609; // SIN(0.558505) 32
        const double cos32 = 0.84804809615642597038617617869039; // COS(0.558505) 32
        float degree1;
        float degree2;
        height *= coef * 2.0 / PI;
        if(height < coef * (-1.0))
        {
            height += coef * 2.0;
            degree1 = asin(height / coef) + 0.44806334134395240307231595147263;
            degree2 = asin(height / coef) - 0.44806334134395240307231595147263;
        }
        else if(height < coef)
        {
            height *= -1;
            degree1 = PI - asin(height / coef) + 0.44806334134395240307231595147263;
            degree2 = PI - asin(height / coef) - 0.44806334134395240307231595147263;
        }
        else if(height < coef * 2.0)
        {
            height -= coef * 2.0;
            degree1 = asin(height / coef) + 0.44806334134395240307231595147263;
            degree2 = asin(height / coef) - 0.44806334134395240307231595147263;
        }

        SetEyesFront_Open(point, 0);

        posL.x = compact * SIN(degree1);
        posL.y = compact * COS(degree1) * 1.3f;
        posR.x = compact * SIN(degree2);
        posR.y = compact * COS(degree2) * 1.3f;
        posL = m_Quard -> Vec2Rotation({0, 0}, posL, sin32, cos32);
        posR = m_Quard -> Vec2Rotation({0, 0}, posR, sin32 * (-1), cos32);
        m_Joint.EyesFront_Open.EyeballLeft.x += posL.x;
        m_Joint.EyesFront_Open.EyeballLeft.y += posL.y;
        m_Joint.EyesFront_Open.EyeballRight.x += posR.x;
        m_Joint.EyesFront_Open.EyeballRight.y += posR.y;
        SetEyeballLeft(m_Joint.EyesFront_Open.EyeballLeft, 0);
        SetEyeballRight(m_Joint.EyesFront_Open.EyeballRight, 0);
    }
    // sin^2a = 0.28081442660546129127363272967087
    // cos^2a = 0.71918557339453870872636727032913
    // cos^2a * 1.69 = 1.2154236190367704177475606868562
    // sin^2a + cos^2a * 1.69 = 1.4962380456422317090211934165271
    // sqrt(sin^2a + cos^2a * 1.69) = 1.2232080958047292571970774274258
    // sin^2a/sqrt(sin^2a + cos^2a * 1.69) = 0.43322086082546686589122412682419
    // degree1 = 0.44806334134395240307231595147263
    // degree2 = -0.44806334134395240307231595147263
}