#include "KennyPart.h"

namespace kenny
{
    const spat::Vec2 m_BodyFrontjoint[] = {
           0.0f, -21.0f,     //PantFront
         197.0f,  75.0f,     //ArmLeft_Open
        -187.0f,  70.0f,     //ArmRight_Open
         140.0f,  23.0f,     //ArmLeft_Bend
        -128.0f,  21.0f,     //ArmRight_Bend
         246.0f,  48.0f,     //ArmFrontLeft_Basic
        -226.0f,  46.0f,     //ArmFrontRight_Basic
        -187.0f,  70.0f      //Face
    };

    void KennyPart::SetBadyFront(spat::Vec2 point, float degree)
    {
        m_Quard -> SetDegree(static_cast<int>(Part::BadyFront), degree);
        m_Quard -> SetPosXY(static_cast<int>(Part::BadyFront), point.x, point.y);
        m_Joint.BodyFront.PantFront             = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[0], degree);
        m_Joint.BodyFront.ArmLeft_Open          = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[1], degree);
        m_Joint.BodyFront.ArmRight_Open         = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[2], degree);
        m_Joint.BodyFront.ArmLeft_Bend          = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[3], degree);
        m_Joint.BodyFront.ArmRight_Bend         = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[4], degree);
        m_Joint.BodyFront.ArmFrontLeft_Basic    = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[5], degree);
        m_Joint.BodyFront.ArmFrontRight_Basic   = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[6], degree);
        m_Joint.BodyFront.Face                  = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[7], degree);
        
        SetPantFront(m_Joint.BodyFront.PantFront, degree * 2.0f);
        // SetArmLeft_Open(m_Joint.BodyFront.ArmLeft_Open, degree * 2.0f);
        // SetArmRight_Open(m_Joint.BodyFront.ArmRight_Open, degree * 2.0f);
        // SetArmLeft_Bend(m_Joint.BodyFront.ArmLeft_Bend, degree * 2.0f);
        // SetArmRight_Bend(m_Joint.BodyFront.ArmRight_Bend, degree * 2.0f);
        SetArmFrontLeft_Basic(m_Joint.BodyFront.ArmFrontLeft_Basic, degree);
        SetArmFrontRight_Basic(m_Joint.BodyFront.ArmFrontRight_Basic, degree);
    }

    const spat::Vec2 m_PantFrontjoint[] = {
         0.0f, 50.0f,     //BadyFront
    };

    void KennyPart::SetPantFront(spat::Vec2 point, float degree)
    {
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_PantFrontjoint[0].x * (-1), m_PantFrontjoint[0].y * (-1)}, degree);
        m_Quard -> SetPosXY(static_cast<int>(Part::PantFront), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::PantFront), degree);
        m_Joint.PantFront.BadyFront = m_Quard -> Vec2Rotation(point, m_PantFrontjoint[0], degree);
    }
    const spat::Vec2 m_ArmLeft_Openjoint[] = {
         -65.0f, 18.0f,     //BadyFront
        -187.0f, 70.0f,     //HandLeft_Paper 
        -187.0f, 70.0f,     //HandLeft_Rock  
    };

    void KennyPart::SetArmLeft_Open(spat::Vec2 point, float degree)
    {
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_ArmLeft_Openjoint[0].x * (-1), m_ArmLeft_Openjoint[0].y * (-1)}, degree);
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmLeft_Open), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmLeft_Open), degree);
        m_Joint.ArmLeft_Open.BadyFront         = m_Quard -> Vec2Rotation(point, m_ArmLeft_Openjoint[0], degree);
        m_Joint.ArmLeft_Open.HandLeft_Paper    = m_Quard -> Vec2Rotation(point, m_ArmLeft_Openjoint[1], degree);
        m_Joint.ArmLeft_Open.HandLeft_Rock     = m_Quard -> Vec2Rotation(point, m_ArmLeft_Openjoint[2], degree);
    }

    const spat::Vec2 m_ArmRight_Openjoint[] = {
          65.0f, 18.0f,     //BadyFront
        -187.0f, 70.0f,     //HandRight_Paper  
        -187.0f, 70.0f,     //HandRight_Rock
    };

    void KennyPart::SetArmRight_Open(spat::Vec2 point, float degree)
    {
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_ArmRight_Openjoint[0].x * (-1), m_ArmRight_Openjoint[0].y * (-1)}, degree);
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmRight_Open), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmRight_Open), degree);
        m_Joint.ArmRight_Open.BadyFront         = m_Quard -> Vec2Rotation(point, m_ArmRight_Openjoint[0], degree);
        m_Joint.ArmRight_Open.HandRight_Paper   = m_Quard -> Vec2Rotation(point, m_ArmRight_Openjoint[1], degree);
        m_Joint.ArmRight_Open.HandRight_Rock    = m_Quard -> Vec2Rotation(point, m_ArmRight_Openjoint[2], degree);
    }

    const spat::Vec2 m_ArmLeft_Bendjoint[] = {
          -80.0f, 0.0f,     //BadyFront
        -187.0f, 70.0f,     //HandLeft_Paper  
        -187.0f, 70.0f,     //HandLeft_Rock
    };

    void KennyPart::SetArmLeft_Bend(spat::Vec2 point, float degree)
    {
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_ArmLeft_Bendjoint[0].x * (-1), m_ArmLeft_Bendjoint[0].y * (-1)}, degree);
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmLeft_Bend), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmLeft_Bend), degree);
        m_Joint.ArmLeft_Bend.BadyFront      = m_Quard -> Vec2Rotation(point, m_ArmLeft_Bendjoint[0], degree);
        m_Joint.ArmLeft_Bend.HandLeft_Paper = m_Quard -> Vec2Rotation(point, m_ArmLeft_Bendjoint[1], degree);
        m_Joint.ArmLeft_Bend.HandLeft_Rock  = m_Quard -> Vec2Rotation(point, m_ArmLeft_Bendjoint[2], degree);
    }

    const spat::Vec2 m_ArmRight_Bendjoint[] = {
          80.0f,  0.0f,     //BadyFront
        -187.0f, 70.0f,     //HandRight_Paper  
        -187.0f, 70.0f,     //HandRight_Rock
    };

    void KennyPart::SetArmRight_Bend(spat::Vec2 point, float degree)
    {
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_ArmRight_Bendjoint[0].x * (-1), m_ArmRight_Bendjoint[0].y * (-1)}, degree);
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmRight_Bend), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmRight_Bend), degree);
        m_Joint.ArmRight_Bend.BadyFront         = m_Quard -> Vec2Rotation(point, m_ArmRight_Bendjoint[0], degree);
        m_Joint.ArmRight_Bend.HandRight_Paper   = m_Quard -> Vec2Rotation(point, m_ArmRight_Bendjoint[1], degree);
        m_Joint.ArmRight_Bend.HandRight_Rock    = m_Quard -> Vec2Rotation(point, m_ArmRight_Bendjoint[2], degree);
    }

    const spat::Vec2 m_ArmFrontLeft_Basicjoint[] = {
           0.0f,  0.0f,     //BadyFront
        -187.0f, 70.0f,     //HandRight_Paper  
        -187.0f, 70.0f,     //HandRight_Rock
    };

    void KennyPart::SetArmFrontLeft_Basic(spat::Vec2 point, float degree)
    {
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmFrontLeft_Basic), point.x, point.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmFrontLeft_Basic), degree);
        m_Joint.ArmFrontLeft_Basic.BadyFront        = m_Quard -> Vec2Rotation(point, m_ArmFrontLeft_Basicjoint[0], degree);
        m_Joint.ArmFrontLeft_Basic.HandLeft_Paper   = m_Quard -> Vec2Rotation(point, m_ArmFrontLeft_Basicjoint[1], degree);
        m_Joint.ArmFrontLeft_Basic.HandLeft_Rock    = m_Quard -> Vec2Rotation(point, m_ArmFrontLeft_Basicjoint[2], degree);
    }

    const spat::Vec2 m_ArmFrontRight_Basicjoint[] = {
           0.0f,  0.0f,     //BadyFront
        -187.0f, 70.0f,     //HandRight_Paper  
        -187.0f, 70.0f,     //HandRight_Rock
    };

    void KennyPart::SetArmFrontRight_Basic(spat::Vec2 point, float degree)
    {
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmFrontRight_Basic), point.x, point.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmFrontRight_Basic), degree);
        m_Joint.ArmFrontRight_Basic.BadyFront       = m_Quard -> Vec2Rotation(point, m_ArmFrontRight_Basicjoint[0], degree);
        m_Joint.ArmFrontRight_Basic.HandRight_Paper = m_Quard -> Vec2Rotation(point, m_ArmFrontRight_Basicjoint[1], degree);
        m_Joint.ArmFrontRight_Basic.HandRight_Rock  = m_Quard -> Vec2Rotation(point, m_ArmFrontRight_Basicjoint[2], degree);
    }
}