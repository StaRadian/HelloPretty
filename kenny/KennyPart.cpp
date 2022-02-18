#include "KennyPart.h"
#include "src/Debug.h"

namespace kenny
{
    const spat::Vec2 m_BodyFrontjoint[] = {
        -187.0f, 70.0f,     //PantFront
        -187.0f, 70.0f,     //ArmLeft_Open
        -187.0f, 70.0f,     //ArmRight_Open
        -187.0f, 70.0f,     //ArmLeft_Bend
        -187.0f, 70.0f,     //ArmRight_Bend
        -187.0f, 70.0f,     //ArmRight_Open
        -187.0f, 70.0f,     //ArmFrontLeft_Basic
        -187.0f, 70.0f,     //ArmFrontRight_Basic
        -187.0f, 70.0f      //Face
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
        
        //SetArmRight_Open(m_Joint.BodyFront.ArmRight_Open, 0);
        m_Quard -> SetPosXY(static_cast<int>(Part::HandRight_Rock), m_Joint.BodyFront.ArmRight_Open.x, m_Joint.BodyFront.ArmRight_Open.y);
        LOG(m_Joint.BodyFront.ArmRight_Open.x << ", " << m_Joint.BodyFront.ArmRight_Open.y << ", " << point.x << ", " << point.y);
    }

    const spat::Vec2 m_ArmRight_Openjoint[] = {
        65.0f, 18.0f,     //BadyFront
        -187.0f, 70.0f,     //HandLeft_Paper 
        -187.0f, 70.0f,     //HandRight_Paper
        -187.0f, 70.0f,     //HandLeft_Rock  
        -187.0f, 70.0f,     //HandRight_Rock
    };

    void KennyPart::SetArmRight_Open(spat::Vec2 point, float degree)
    {
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_ArmRight_Openjoint[0].x * (-1), m_ArmRight_Openjoint[0].y * (-1)}, degree);
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmRight_Open), pos.x, pos.y);
        m_Quard -> SetPosXY(static_cast<int>(Part::HandRight_Rock), pos.x, pos.y);
        //m_Quard -> SetDegree(static_cast<int>(Part::ArmRight_Open), degree);
        m_Joint.ArmRight_Open.BadyFront         = m_Quard -> Vec2Rotation(point, m_ArmRight_Openjoint[0], degree);
        m_Joint.ArmRight_Open.HandLeft_Paper    = m_Quard -> Vec2Rotation(point, m_ArmRight_Openjoint[1], degree);
        m_Joint.ArmRight_Open.HandRight_Paper   = m_Quard -> Vec2Rotation(point, m_ArmRight_Openjoint[2], degree);
        m_Joint.ArmRight_Open.HandLeft_Rock     = m_Quard -> Vec2Rotation(point, m_ArmRight_Openjoint[3], degree);
        m_Joint.ArmRight_Open.HandRight_Rock    = m_Quard -> Vec2Rotation(point, m_ArmRight_Openjoint[4], degree);
    }
}