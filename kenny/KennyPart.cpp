#include "KennyPart.h"

namespace kenny
{
    const spat::Vec2 m_PantFrontjoint[] = {
         0.0f, 50.0f      //BadyFront
    };

    void KennyPart::SetPantFront(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_PantFrontjoint[0].x * (-1), m_PantFrontjoint[0].y * (-1)}, sind, cosd);
        m_Quard -> SetPosXY(static_cast<int>(Part::PantFront), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::PantFront), degree, sind, cosd);
        m_Joint.PantFront.BadyFront = m_Quard -> Vec2Rotation(point, m_PantFrontjoint[0], sind, cosd);
    }
    
    const spat::Vec2 m_BodyFrontjoint[] = {
           0.0f, -21.0f,     //PantFront
         197.0f,  75.0f,     //ArmLeft_Open
        -187.0f,  70.0f,     //ArmRight_Open
         140.0f,  23.0f,     //ArmLeft_Bend
        -128.0f,  21.0f,     //ArmRight_Bend
         246.0f,  48.0f,     //ArmFrontLeft_Basic
        -226.0f,  46.0f,     //ArmFrontRight_Basic
           0.0f,  251.0f      //Face
    };

    void KennyPart::SetBadyFront(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Quard -> SetDegree(static_cast<int>(Part::BadyFront), degree, sind, cosd);
        m_Quard -> SetPosXY(static_cast<int>(Part::BadyFront), point.x, point.y);
        m_Joint.BodyFront.PantFront = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[0], sind, cosd);
        SetPantFront(m_Joint.BodyFront.PantFront, degree);
        if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmLeft_Open))
        {
            m_Joint.BodyFront.ArmLeft_Open = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[1], sind, cosd);
            SetArmLeft_Open(m_Joint.BodyFront.ArmLeft_Open, degree * 2.0f);
        }
        else if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmLeft_Bend))
        {
            m_Joint.BodyFront.ArmLeft_Bend = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[3], sind, cosd);
            SetArmLeft_Bend(m_Joint.BodyFront.ArmLeft_Bend, degree);
        }
        else if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmFrontLeft_Basic))
        {
            m_Joint.BodyFront.ArmFrontLeft_Basic = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[5], sind, cosd);
            SetArmFrontLeft_Basic(m_Joint.BodyFront.ArmFrontLeft_Basic, degree);
        }
        if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmRight_Open))
        {
            m_Joint.BodyFront.ArmRight_Open = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[2], sind, cosd);
            SetArmRight_Open(m_Joint.BodyFront.ArmRight_Open, degree * 2.0f);
        }
        else if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmRight_Bend))
        {
            m_Joint.BodyFront.ArmRight_Bend = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[4], sind, cosd);
            SetArmRight_Bend(m_Joint.BodyFront.ArmRight_Bend, degree);
        }
        else if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmFrontRight_Basic))
        {
            m_Joint.BodyFront.ArmFrontRight_Basic = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[6], sind, cosd);
            SetArmFrontRight_Basic(m_Joint.BodyFront.ArmFrontRight_Basic, degree);
        }
        m_Joint.BodyFront.Face = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[7], sind, cosd);
        SetFace(m_Joint.BodyFront.Face, degree);
    }
    const spat::Vec2 m_ArmLeft_Openjoint[] = {
        -65.0f,  18.0f,     //BadyFront
        160.0f, -18.0f,     //HandLeft_Paper 
        160.0f, -18.0f      //HandLeft_Rock  
    };

    void KennyPart::SetArmLeft_Open(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_ArmLeft_Openjoint[0].x * (-1), m_ArmLeft_Openjoint[0].y * (-1)}, sind, cosd);
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmLeft_Open), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmLeft_Open), degree, sind, cosd);
        m_Joint.ArmLeft_Open.BadyFront         = m_Quard -> Vec2Rotation(point, m_ArmLeft_Openjoint[0], sind, cosd);
        m_Joint.ArmLeft_Open.HandLeft_Paper    = m_Quard -> Vec2Rotation(point, m_ArmLeft_Openjoint[1], sind, cosd);
        m_Joint.ArmLeft_Open.HandLeft_Rock     = m_Quard -> Vec2Rotation(point, m_ArmLeft_Openjoint[2], sind, cosd);

        if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Paper))
        {
            SetHandLeft_Paper(m_Joint.ArmLeft_Open.HandLeft_Paper, degree * 2.0f);
        }
        else if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Rock))
        {
            SetHandLeft_Rock(m_Joint.ArmLeft_Open.HandLeft_Rock, degree * 2.0f);
        }
    }

    const spat::Vec2 m_ArmRight_Openjoint[] = {
          65.0f,  18.0f,     //BadyFront
        -160.0f, -18.0f,     //HandRight_Paper  
        -160.0f, -18.0f      //HandRight_Rock
    };

    void KennyPart::SetArmRight_Open(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_ArmRight_Openjoint[0].x * (-1), m_ArmRight_Openjoint[0].y * (-1)}, sind, cosd);
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmRight_Open), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmRight_Open), degree, sind, cosd);
        m_Joint.ArmRight_Open.BadyFront         = m_Quard -> Vec2Rotation(point, m_ArmRight_Openjoint[0], sind, cosd);
        m_Joint.ArmRight_Open.HandRight_Paper   = m_Quard -> Vec2Rotation(point, m_ArmRight_Openjoint[1], sind, cosd);
        m_Joint.ArmRight_Open.HandRight_Rock    = m_Quard -> Vec2Rotation(point, m_ArmRight_Openjoint[2], sind, cosd);

        if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Paper))
        {
            SetHandRight_Paper(m_Joint.ArmRight_Open.HandRight_Paper, degree * 2.0f);
        }
        else if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Rock))
        {
            SetHandRight_Rock(m_Joint.ArmRight_Open.HandRight_Rock, degree * 2.0f);
        }
    }

    const spat::Vec2 m_ArmLeft_Bendjoint[] = {
        -80.0f,   0.0f,     //BadyFront
         56.0f, -62.0f,     //HandLeft_Paper  
         56.0f, -62.0f      //HandLeft_Rock
    };

    void KennyPart::SetArmLeft_Bend(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_ArmLeft_Bendjoint[0].x * (-1), m_ArmLeft_Bendjoint[0].y * (-1)}, sind, cosd);
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmLeft_Bend), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmLeft_Bend), degree, sind, cosd);
        m_Joint.ArmLeft_Bend.BadyFront      = m_Quard -> Vec2Rotation(point, m_ArmLeft_Bendjoint[0], sind, cosd);
        m_Joint.ArmLeft_Bend.HandLeft_Paper = m_Quard -> Vec2Rotation(point, m_ArmLeft_Bendjoint[1], sind, cosd);
        m_Joint.ArmLeft_Bend.HandLeft_Rock  = m_Quard -> Vec2Rotation(point, m_ArmLeft_Bendjoint[2], sind, cosd);

        if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Paper))
        {
            SetHandLeft_Paper(m_Joint.ArmLeft_Bend.HandLeft_Paper, degree * 2.0f);
        }
        else if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Rock))
        {
            SetHandLeft_Rock(m_Joint.ArmLeft_Bend.HandLeft_Rock, degree * 2.0f);
        }
    }

    const spat::Vec2 m_ArmRight_Bendjoint[] = {
         80.0f,   0.0f,     //BadyFront
        -56.0f, -62.0f,     //HandRight_Paper  
        -56.0f, -62.0f      //HandRight_Rock
    };

    void KennyPart::SetArmRight_Bend(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_ArmRight_Bendjoint[0].x * (-1), m_ArmRight_Bendjoint[0].y * (-1)}, sind, cosd);
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmRight_Bend), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmRight_Bend), degree, sind, cosd);
        m_Joint.ArmRight_Bend.BadyFront         = m_Quard -> Vec2Rotation(point, m_ArmRight_Bendjoint[0], sind, cosd);
        m_Joint.ArmRight_Bend.HandRight_Paper   = m_Quard -> Vec2Rotation(point, m_ArmRight_Bendjoint[1], sind, cosd);
        m_Joint.ArmRight_Bend.HandRight_Rock    = m_Quard -> Vec2Rotation(point, m_ArmRight_Bendjoint[2], sind, cosd);

        if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Paper))
        {
            SetHandRight_Paper(m_Joint.ArmRight_Bend.HandRight_Paper, degree * 2.0f);
        }
        else if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Rock))
        {
            SetHandRight_Rock(m_Joint.ArmRight_Bend.HandRight_Rock, degree * 2.0f);
        }
    }

    const spat::Vec2 m_ArmFrontLeft_Basicjoint[] = {
         0.0f,    0.0f,     //BadyFront
         6.0f,  -85.0f,     //HandLeft_Paper  
        16.0f, -115.0f      //HandLeft_Rock
    };

    void KennyPart::SetArmFrontLeft_Basic(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmFrontLeft_Basic), point.x, point.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmFrontLeft_Basic), degree, sind, cosd);
        m_Joint.ArmFrontLeft_Basic.BadyFront        = m_Quard -> Vec2Rotation(point, m_ArmFrontLeft_Basicjoint[0], sind, cosd);
        m_Joint.ArmFrontLeft_Basic.HandLeft_Paper   = m_Quard -> Vec2Rotation(point, m_ArmFrontLeft_Basicjoint[1], sind, cosd);
        m_Joint.ArmFrontLeft_Basic.HandLeft_Rock    = m_Quard -> Vec2Rotation(point, m_ArmFrontLeft_Basicjoint[2], sind, cosd);

        if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Paper))
        {
            SetHandLeft_Paper(m_Joint.ArmFrontLeft_Basic.HandLeft_Paper, degree * 2.0f);
        }
        else if(m_CurrentStyle.hand.left == static_cast<int>(Part::HandLeft_Rock))
        {
            SetHandLeft_Rock(m_Joint.ArmFrontLeft_Basic.HandLeft_Rock, degree * 2.0f);
        }
    }

    const spat::Vec2 m_ArmFrontRight_Basicjoint[] = {
          0.0f,    0.0f,     //BadyFront
        -31.0f,  -97.0f,     //HandRight_Paper  
        -21.0f, -107.0f      //HandRight_Rock
    };

    void KennyPart::SetArmFrontRight_Basic(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmFrontRight_Basic), point.x, point.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmFrontRight_Basic), degree, sind, cosd);
        m_Joint.ArmFrontRight_Basic.BadyFront       = m_Quard -> Vec2Rotation(point, m_ArmFrontRight_Basicjoint[0], sind, cosd);
        m_Joint.ArmFrontRight_Basic.HandRight_Paper = m_Quard -> Vec2Rotation(point, m_ArmFrontRight_Basicjoint[1], sind, cosd);
        m_Joint.ArmFrontRight_Basic.HandRight_Rock  = m_Quard -> Vec2Rotation(point, m_ArmFrontRight_Basicjoint[2], sind, cosd);

        if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Paper))
        {
            SetHandRight_Paper(m_Joint.ArmFrontRight_Basic.HandRight_Paper, degree * 2.0f);
        }
        else if(m_CurrentStyle.hand.right == static_cast<int>(Part::HandRight_Rock))
        {
            SetHandRight_Rock(m_Joint.ArmFrontRight_Basic.HandRight_Rock, degree * 2.0f);
        }
    }

    const spat::Vec2 m_Facejoint[] = {
           0.0f, -120.0f,     //BadyFront
        -187.0f,   70.0f,     //EyesFront_Open
        -187.0f,   70.0f,     //HatFront
        -187.0f,   70.0f,     //EyebrowLeft
        -187.0f,   70.0f      //EyebrowRight
    };

    void KennyPart::SetFace(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_Facejoint[0].x * (-1), m_Facejoint[0].y * (-1)}, sind, cosd);
        m_Quard -> SetPosXY(static_cast<int>(Part::Face), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::Face), degree, sind, cosd);
        m_Joint.Face.BadyFront      = m_Quard -> Vec2Rotation(point, m_Facejoint[0], sind, cosd);
        m_Joint.Face.EyesFront_Open = m_Quard -> Vec2Rotation(point, m_Facejoint[1], sind, cosd);
        m_Joint.Face.HatFront       = m_Quard -> Vec2Rotation(point, m_Facejoint[2], sind, cosd);    
        m_Joint.Face.EyebrowLeft    = m_Quard -> Vec2Rotation(point, m_Facejoint[3], sind, cosd);    
        m_Joint.Face.EyebrowRight   = m_Quard -> Vec2Rotation(point, m_Facejoint[4], sind, cosd);    
    }

    const spat::Vec2 m_HandLeft_PaperJoint[] = {
        -20.0f, -5.0f,     //ArmLeft_Open    
        -20.0f, -5.0f,     //ArmLeft_Bend
        -20.0f, -5.0f      //ArmFrontLeft_Basic
    };

    void KennyPart::SetHandLeft_Paper(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        spat::Vec2 pos;
        if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmLeft_Open))
        {
            pos = m_Quard -> Vec2Rotation(point, {m_HandLeft_PaperJoint[0].x * (-1), m_HandLeft_PaperJoint[0].y * (-1)}, sind, cosd);
        }
        else if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmLeft_Bend))
        {
            pos = m_Quard -> Vec2Rotation(point, {m_HandLeft_PaperJoint[1].x * (-1), m_HandLeft_PaperJoint[1].y * (-1)}, sind, cosd);
        }
        else if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmFrontLeft_Basic))
        {
            pos = m_Quard -> Vec2Rotation(point, {m_HandLeft_PaperJoint[2].x * (-1), m_HandLeft_PaperJoint[2].y * (-1)}, sind, cosd);
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::HandLeft_Paper), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::HandLeft_Paper), degree, sind, cosd);
        m_Joint.HandLeft_Paper.ArmLeft_Open          = m_Quard -> Vec2Rotation(point, m_HandLeft_PaperJoint[0], sind, cosd);
        m_Joint.HandLeft_Paper.ArmLeft_Bend          = m_Quard -> Vec2Rotation(point, m_HandLeft_PaperJoint[1], sind, cosd);
        m_Joint.HandLeft_Paper.ArmFrontLeft_Basic    = m_Quard -> Vec2Rotation(point, m_HandLeft_PaperJoint[2], sind, cosd);    
    }       

    const spat::Vec2 m_HandRight_PaperJoint[] = {
        20.0f, -5.0f,     //ArmRight_Open    
        20.0f, -5.0f,     //ArmRight_Bend
        20.0f, -5.0f      //ArmFrontRight_Basic
    };

    void KennyPart::SetHandRight_Paper(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        spat::Vec2 pos;
        if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmRight_Open))
        {
            pos = m_Quard -> Vec2Rotation(point, {m_HandRight_PaperJoint[0].x * (-1), m_HandRight_PaperJoint[0].y * (-1)}, sind, cosd);
        }
        else if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmRight_Bend))
        {
            pos = m_Quard -> Vec2Rotation(point, {m_HandRight_PaperJoint[1].x * (-1), m_HandRight_PaperJoint[1].y * (-1)}, sind, cosd);
        }
        else if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmFrontRight_Basic))
        {
            pos = m_Quard -> Vec2Rotation(point, {m_HandRight_PaperJoint[2].x * (-1), m_HandRight_PaperJoint[2].y * (-1)}, sind, cosd);
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::HandRight_Paper), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::HandRight_Paper), degree, sind, cosd);
        m_Joint.HandRight_Paper.ArmRight_Open          = m_Quard -> Vec2Rotation(point, m_HandRight_PaperJoint[0], sind, cosd);
        m_Joint.HandRight_Paper.ArmRight_Bend          = m_Quard -> Vec2Rotation(point, m_HandRight_PaperJoint[1], sind, cosd);
        m_Joint.HandRight_Paper.ArmFrontRight_Basic    = m_Quard -> Vec2Rotation(point, m_HandRight_PaperJoint[2], sind, cosd);    
    }

    const spat::Vec2 m_HandLeft_RockJoint[] = {
        0.0f, 0.0f,     //ArmLeft_Open    
        0.0f, 0.0f,     //ArmLeft_Bend
        0.0f, 0.0f      //ArmFrontLeft_Basic
    };

    void KennyPart::SetHandLeft_Rock(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        spat::Vec2 pos;
        if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmLeft_Open))
        {
            pos = m_Quard -> Vec2Rotation(point, {m_HandLeft_RockJoint[0].x * (-1), m_HandLeft_RockJoint[0].y * (-1)}, sind, cosd);
        }
        else if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmLeft_Bend))
        {
            pos = m_Quard -> Vec2Rotation(point, {m_HandLeft_RockJoint[1].x * (-1), m_HandLeft_RockJoint[1].y * (-1)}, sind, cosd);
        }
        else if(m_CurrentStyle.arm.left == static_cast<int>(Part::ArmFrontLeft_Basic))
        {
            pos = m_Quard -> Vec2Rotation(point, {m_HandLeft_RockJoint[2].x * (-1), m_HandLeft_RockJoint[2].y * (-1)}, sind, cosd);
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::HandLeft_Rock), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::HandLeft_Rock), degree, sind, cosd);
        m_Joint.HandLeft_Rock.ArmLeft_Open          = m_Quard -> Vec2Rotation(point, m_HandLeft_RockJoint[0], sind, cosd);
        m_Joint.HandLeft_Rock.ArmLeft_Bend          = m_Quard -> Vec2Rotation(point, m_HandLeft_RockJoint[1], sind, cosd);
        m_Joint.HandLeft_Rock.ArmFrontLeft_Basic    = m_Quard -> Vec2Rotation(point, m_HandLeft_RockJoint[2], sind, cosd);    
    }       

    const spat::Vec2 m_HandRight_RockJoint[] = {
        0.0f, 0.0f,     //ArmRight_Open    
        0.0f, 0.0f,     //ArmRight_Bend
        0.0f, 0.0f      //ArmFrontRight_Basic
    };

    void KennyPart::SetHandRight_Rock(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        spat::Vec2 pos;
        if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmRight_Open))
        {
            pos = m_Quard -> Vec2Rotation(point, {m_HandRight_RockJoint[0].x * (-1), m_HandRight_RockJoint[0].y * (-1)}, sind, cosd);
        }
        else if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmRight_Bend))
        {
            pos = m_Quard -> Vec2Rotation(point, {m_HandRight_RockJoint[1].x * (-1), m_HandRight_RockJoint[1].y * (-1)}, sind, cosd);
        }
        else if(m_CurrentStyle.arm.right == static_cast<int>(Part::ArmFrontRight_Basic))
        {
            pos = m_Quard -> Vec2Rotation(point, {m_HandRight_RockJoint[2].x * (-1), m_HandRight_RockJoint[2].y * (-1)}, sind, cosd);
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::HandRight_Rock), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::HandRight_Rock), degree, sind, cosd);
        m_Joint.HandRight_Rock.ArmRight_Open          = m_Quard -> Vec2Rotation(point, m_HandRight_RockJoint[0], sind, cosd);
        m_Joint.HandRight_Rock.ArmRight_Bend          = m_Quard -> Vec2Rotation(point, m_HandRight_RockJoint[1], sind, cosd);
        m_Joint.HandRight_Rock.ArmFrontRight_Basic    = m_Quard -> Vec2Rotation(point, m_HandRight_RockJoint[2], sind, cosd);    
    }       
}