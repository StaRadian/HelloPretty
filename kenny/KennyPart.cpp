#include "KennyPart.h"

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
        m_Quard -> SetPosXY(static_cast<int>(Part::BadyFront), point.x, point.y);
        m_Quard -> SetDegree(static_cast<int>(Part::BadyFront), degree);
        // for(int i = 0; i < 8; i++)
        //     m_Joint.BodyFront[i] = m_Quard -> Vec2Rotation(point, m_BodyFrontjoint[i], degree);

    }
}