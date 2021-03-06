#include "KennyJoint.h"

namespace kenny
{
    const spat::Vec2 m_PantFrontjoint[] = {
         0.0f, 100.0f      //BadyFront
    };

    void KennyJoint::SetPantFront(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Joint.PantFront.Point.x = point.x;
        m_Joint.PantFront.Point.y = point.y;
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_PantFrontjoint[0].x * (-1), m_PantFrontjoint[0].y * (-1)}, sind, cosd);
        m_Quard -> SetPosXY(static_cast<int>(Part::PantFront), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::PantFront), degree, sind, cosd);
        m_Joint.PantFront.BadyFront = m_Quard -> Vec2Rotation(pos, m_PantFrontjoint[0], sind, cosd);
        m_Joint.PantFront.degree = degree;
    }
    
    const spat::Vec2 m_BadyFrontjoint[] = {
           0.0f,  29.0f,   //PantFront
         197.0f,  75.0f,   //ArmLeft_Open
        -187.0f,  70.0f,   //ArmRight_Open
         140.0f,  23.0f,   //ArmLeft_Bend
        -128.0f,  21.0f,   //ArmRight_Bend
         246.0f,  48.0f,   //ArmFrontLeft_Basic
        -226.0f,  46.0f,   //ArmFrontRight_Basic
           0.0f, 171.0f    //Face
    };

    void KennyJoint::SetBadyFront(spat::Vec2 point, float degree, int rx)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Joint.BadyFront.Point.x = point.x;
        m_Joint.BadyFront.Point.y = point.y;
        spat::Vec2 pos;
        switch (rx)
        {
        case static_cast<int>(Part::PantFront):
            pos = m_Quard -> Vec2Rotation(point, {m_BadyFrontjoint[0].x * (-1), m_BadyFrontjoint[0].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::ArmLeft_Open):
            pos = m_Quard -> Vec2Rotation(point, {m_BadyFrontjoint[1].x * (-1), m_BadyFrontjoint[1].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::ArmRight_Open):
            pos = m_Quard -> Vec2Rotation(point, {m_BadyFrontjoint[2].x * (-1), m_BadyFrontjoint[2].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::ArmLeft_Bend):
            pos = m_Quard -> Vec2Rotation(point, {m_BadyFrontjoint[3].x * (-1), m_BadyFrontjoint[3].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::ArmRight_Bend):
            pos = m_Quard -> Vec2Rotation(point, {m_BadyFrontjoint[4].x * (-1), m_BadyFrontjoint[4].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::ArmFrontLeft_Basic):
            pos = m_Quard -> Vec2Rotation(point, {m_BadyFrontjoint[5].x * (-1), m_BadyFrontjoint[5].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::ArmFrontRight_Basic):
            pos = m_Quard -> Vec2Rotation(point, {m_BadyFrontjoint[6].x * (-1), m_BadyFrontjoint[6].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::Face):
            pos = m_Quard -> Vec2Rotation(point, {m_BadyFrontjoint[7].x * (-1), m_BadyFrontjoint[7].y * (-1)}, sind, cosd);
            break;
        default:
            pos = point;
            break;
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::BadyFront), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::BadyFront), degree, sind, cosd);
        m_Joint.BadyFront.PantFront = m_Quard -> Vec2Rotation(pos, m_BadyFrontjoint[0], sind, cosd);
        m_Joint.BadyFront.ArmLeft_Open = m_Quard -> Vec2Rotation(pos, m_BadyFrontjoint[1], sind, cosd);
        m_Joint.BadyFront.ArmRight_Open = m_Quard -> Vec2Rotation(pos, m_BadyFrontjoint[2], sind, cosd);
        m_Joint.BadyFront.ArmLeft_Bend = m_Quard -> Vec2Rotation(pos, m_BadyFrontjoint[3], sind, cosd);
        m_Joint.BadyFront.ArmRight_Bend = m_Quard -> Vec2Rotation(pos, m_BadyFrontjoint[4], sind, cosd);
        m_Joint.BadyFront.ArmFrontLeft_Basic = m_Quard -> Vec2Rotation(pos, m_BadyFrontjoint[5], sind, cosd);
        m_Joint.BadyFront.ArmFrontRight_Basic = m_Quard -> Vec2Rotation(pos, m_BadyFrontjoint[6], sind, cosd);
        m_Joint.BadyFront.Face = m_Quard -> Vec2Rotation(pos, m_BadyFrontjoint[7], sind, cosd);
        m_Joint.BadyFront.degree = degree;
    }
    const spat::Vec2 m_ArmLeft_Openjoint[] = {
        -65.0f,  18.0f,     //BadyFront
        108.0f,   3.0f,     //HandLeft_Paper 
        108.0f,   3.0f      //HandLeft_Rock  
    };

    void KennyJoint::SetArmLeft_Open(spat::Vec2 point, float degree, int rx)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Joint.ArmLeft_Open.Point.x = point.x;
        m_Joint.ArmLeft_Open.Point.y = point.y;
        spat::Vec2 pos;
        switch (rx)
        {
        case static_cast<int>(Part::BadyFront):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmLeft_Openjoint[0].x * (-1), m_ArmLeft_Openjoint[0].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::HandLeft_Paper):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmLeft_Openjoint[1].x * (-1), m_ArmLeft_Openjoint[1].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::HandLeft_Rock):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmLeft_Openjoint[2].x * (-1), m_ArmLeft_Openjoint[2].y * (-1)}, sind, cosd);
            break;
        default:
            pos = point;
            break;
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmLeft_Open), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmLeft_Open), degree, sind, cosd);
        m_Joint.ArmLeft_Open.BadyFront         = m_Quard -> Vec2Rotation(pos, m_ArmLeft_Openjoint[0], sind, cosd);
        m_Joint.ArmLeft_Open.HandLeft_Paper    = m_Quard -> Vec2Rotation(pos, m_ArmLeft_Openjoint[1], sind, cosd);
        m_Joint.ArmLeft_Open.HandLeft_Rock     = m_Quard -> Vec2Rotation(pos, m_ArmLeft_Openjoint[2], sind, cosd);
        m_Joint.ArmLeft_Open.degree = degree;
    }

    const spat::Vec2 m_ArmRight_Openjoint[] = {
          65.0f,  18.0f,     //BadyFront
        -108.0f,   3.0f,     //HandRight_Paper  
        -108.0f,   3.0f      //HandRight_Rock
    };

    void KennyJoint::SetArmRight_Open(spat::Vec2 point, float degree, int rx)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Joint.ArmRight_Open.Point.x = point.x;
        m_Joint.ArmRight_Open.Point.y = point.y;
        spat::Vec2 pos;
        switch (rx)
        {
        case static_cast<int>(Part::BadyFront):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmRight_Openjoint[0].x * (-1), m_ArmRight_Openjoint[0].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::HandRight_Paper):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmRight_Openjoint[1].x * (-1), m_ArmRight_Openjoint[1].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::HandRight_Rock):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmRight_Openjoint[2].x * (-1), m_ArmRight_Openjoint[2].y * (-1)}, sind, cosd);
            break;
        default:
            pos = point;
            break;
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmRight_Open), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmRight_Open), degree, sind, cosd);
        m_Joint.ArmRight_Open.BadyFront         = m_Quard -> Vec2Rotation(pos, m_ArmRight_Openjoint[0], sind, cosd);
        m_Joint.ArmRight_Open.HandRight_Paper   = m_Quard -> Vec2Rotation(pos, m_ArmRight_Openjoint[1], sind, cosd);
        m_Joint.ArmRight_Open.HandRight_Rock    = m_Quard -> Vec2Rotation(pos, m_ArmRight_Openjoint[2], sind, cosd);
        m_Joint.ArmRight_Open.degree = degree;
    }

    const spat::Vec2 m_ArmLeft_Bendjoint[] = {
        -80.0f,   0.0f,     //BadyFront
        -24.0f, -68.0f,     //HandLeft_Paper  
        -24.0f, -68.0f      //HandLeft_Rock
    };

    void KennyJoint::SetArmLeft_Bend(spat::Vec2 point, float degree, int rx)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Joint.ArmLeft_Bend.Point.x = point.x;
        m_Joint.ArmLeft_Bend.Point.y = point.y;
        spat::Vec2 pos;
        switch (rx)
        {
        case static_cast<int>(Part::BadyFront):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmLeft_Bendjoint[0].x * (-1), m_ArmLeft_Bendjoint[0].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::HandLeft_Paper):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmLeft_Bendjoint[1].x * (-1), m_ArmLeft_Bendjoint[1].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::HandLeft_Rock):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmLeft_Bendjoint[2].x * (-1), m_ArmLeft_Bendjoint[2].y * (-1)}, sind, cosd);
            break;
        default:
            pos = point;
            break;
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmLeft_Bend), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmLeft_Bend), degree, sind, cosd);
        m_Joint.ArmLeft_Bend.BadyFront      = m_Quard -> Vec2Rotation(pos, m_ArmLeft_Bendjoint[0], sind, cosd);
        m_Joint.ArmLeft_Bend.HandLeft_Paper = m_Quard -> Vec2Rotation(pos, m_ArmLeft_Bendjoint[1], sind, cosd);
        m_Joint.ArmLeft_Bend.HandLeft_Rock  = m_Quard -> Vec2Rotation(pos, m_ArmLeft_Bendjoint[2], sind, cosd);
        m_Joint.ArmLeft_Bend.degree = degree;
    }

    const spat::Vec2 m_ArmRight_Bendjoint[] = {
        80.0f,   0.0f,     //BadyFront
        24.0f, -66.0f,     //HandRight_Paper  
        24.0f, -66.0f      //HandRight_Rock
    };

    void KennyJoint::SetArmRight_Bend(spat::Vec2 point, float degree, int rx)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Joint.ArmRight_Bend.Point.x = point.x;
        m_Joint.ArmRight_Bend.Point.y = point.y;
        spat::Vec2 pos;
        switch (rx)
        {
        case static_cast<int>(Part::BadyFront):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmRight_Bendjoint[0].x * (-1), m_ArmRight_Bendjoint[0].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::HandRight_Paper):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmRight_Bendjoint[1].x * (-1), m_ArmRight_Bendjoint[1].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::HandRight_Rock):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmRight_Bendjoint[2].x * (-1), m_ArmRight_Bendjoint[2].y * (-1)}, sind, cosd);
            break;
        default:
            pos = point;
            break;
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmRight_Bend), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmRight_Bend), degree, sind, cosd);
        m_Joint.ArmRight_Bend.BadyFront         = m_Quard -> Vec2Rotation(pos, m_ArmRight_Bendjoint[0], sind, cosd);
        m_Joint.ArmRight_Bend.HandRight_Paper   = m_Quard -> Vec2Rotation(pos, m_ArmRight_Bendjoint[1], sind, cosd);
        m_Joint.ArmRight_Bend.HandRight_Rock    = m_Quard -> Vec2Rotation(pos, m_ArmRight_Bendjoint[2], sind, cosd);
        m_Joint.ArmRight_Bend.degree = degree;
    }

    const spat::Vec2 m_ArmFrontLeft_Basicjoint[] = {
         0.0f,    0.0f,     //BadyFront
         6.0f,  -90.0f,     //HandLeft_Paper  
        16.0f, -115.0f      //HandLeft_Rock
    };

    void KennyJoint::SetArmFrontLeft_Basic(spat::Vec2 point, float degree, int rx)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Joint.ArmFrontLeft_Basic.Point.x = point.x;
        m_Joint.ArmFrontLeft_Basic.Point.y = point.y;
        spat::Vec2 pos;
        switch (rx)
        {
        case static_cast<int>(Part::BadyFront):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmFrontLeft_Basicjoint[0].x * (-1), m_ArmFrontLeft_Basicjoint[0].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::HandLeft_Paper):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmFrontLeft_Basicjoint[1].x * (-1), m_ArmFrontLeft_Basicjoint[1].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::HandLeft_Rock):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmFrontLeft_Basicjoint[2].x * (-1), m_ArmFrontLeft_Basicjoint[2].y * (-1)}, sind, cosd);
            break;
        default:
            pos = point;
            break;
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmFrontLeft_Basic), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmFrontLeft_Basic), degree, sind, cosd);
        m_Joint.ArmFrontLeft_Basic.BadyFront        = m_Quard -> Vec2Rotation(pos, m_ArmFrontLeft_Basicjoint[0], sind, cosd);
        m_Joint.ArmFrontLeft_Basic.HandLeft_Paper   = m_Quard -> Vec2Rotation(pos, m_ArmFrontLeft_Basicjoint[1], sind, cosd);
        m_Joint.ArmFrontLeft_Basic.HandLeft_Rock    = m_Quard -> Vec2Rotation(pos, m_ArmFrontLeft_Basicjoint[2], sind, cosd);
        m_Joint.ArmFrontLeft_Basic.degree = degree;
    }

    const spat::Vec2 m_ArmFrontRight_Basicjoint[] = {
          0.0f,    0.0f,     //BadyFront
        -31.0f,  -90.0f,     //HandRight_Paper  
        -21.0f, -107.0f      //HandRight_Rock
    };

    void KennyJoint::SetArmFrontRight_Basic(spat::Vec2 point, float degree, int rx)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Joint.ArmFrontRight_Basic.Point.x = point.x;
        m_Joint.ArmFrontRight_Basic.Point.y = point.y;
        spat::Vec2 pos;
        switch (rx)
        {
        case static_cast<int>(Part::BadyFront):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmFrontRight_Basicjoint[0].x * (-1), m_ArmFrontRight_Basicjoint[0].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::HandRight_Paper):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmFrontRight_Basicjoint[1].x * (-1), m_ArmFrontRight_Basicjoint[1].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::HandRight_Rock):
            pos = m_Quard -> Vec2Rotation(point, {m_ArmFrontRight_Basicjoint[2].x * (-1), m_ArmFrontRight_Basicjoint[2].y * (-1)}, sind, cosd);
            break;
        default:
            pos = point;
            break;
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::ArmFrontRight_Basic), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::ArmFrontRight_Basic), degree, sind, cosd);
        m_Joint.ArmFrontRight_Basic.BadyFront       = m_Quard -> Vec2Rotation(pos, m_ArmFrontRight_Basicjoint[0], sind, cosd);
        m_Joint.ArmFrontRight_Basic.HandRight_Paper = m_Quard -> Vec2Rotation(pos, m_ArmFrontRight_Basicjoint[1], sind, cosd);
        m_Joint.ArmFrontRight_Basic.HandRight_Rock  = m_Quard -> Vec2Rotation(pos, m_ArmFrontRight_Basicjoint[2], sind, cosd);
        m_Joint.ArmFrontRight_Basic.degree = degree;
    }

    const spat::Vec2 m_Facejoint[] = {
          0.0f, -150.0f,    //BadyFront
          0.0f,   9.0f,     //EyesFront_Open
         90.0f,   9.0f,     //EyeCloseLeft   
        -90.0f,   9.0f,     //EyeCloseRight  
          0.0f,   0.0f,     //HatFront
         89.0f, 116.0f,     //EyebrowLeft
        -89.0f, 116.0f      //EyebrowRight
    };

    void KennyJoint::SetFace(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Joint.Face.Point.x = point.x;
        m_Joint.Face.Point.y = point.y;
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_Facejoint[0].x * (-1), m_Facejoint[0].y * (-1)}, sind, cosd);
        m_Quard -> SetPosXY(static_cast<int>(Part::Face), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::Face), degree, sind, cosd);
        m_Joint.Face.BadyFront      = m_Quard -> Vec2Rotation(pos, m_Facejoint[0], sind, cosd);
        m_Joint.Face.EyesFront_Open = m_Quard -> Vec2Rotation(pos, m_Facejoint[1], sind, cosd);
        m_Joint.Face.EyeCloseLeft   = m_Quard -> Vec2Rotation(pos, m_Facejoint[2], sind, cosd);    
        m_Joint.Face.EyeCloseRight  = m_Quard -> Vec2Rotation(pos, m_Facejoint[3], sind, cosd);    
        m_Joint.Face.HatFront       = m_Quard -> Vec2Rotation(pos, m_Facejoint[4], sind, cosd);    
        m_Joint.Face.EyebrowLeft    = m_Quard -> Vec2Rotation(pos, m_Facejoint[5], sind, cosd);    
        m_Joint.Face.EyebrowRight   = m_Quard -> Vec2Rotation(pos, m_Facejoint[6], sind, cosd);    
        m_Joint.Face.degree = degree;
    }
    


    const spat::Vec2 m_EyesFront_Openjoint[] = {
        
          0.0f,  0.0f,     //Face
         45.0f,  0.0f,     //EyeballLeft
        -45.0f,  0.0f,     //EyeballRight
    };

    void KennyJoint::SetEyesFront_Open(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Quard -> SetPosXY(static_cast<int>(Part::EyesFront_Open), point.x, point.y);
        m_Quard -> SetDegree(static_cast<int>(Part::EyesFront_Open), degree, sind, cosd);
        m_Joint.EyesFront_Open.Face         = m_Quard -> Vec2Rotation(point, m_EyesFront_Openjoint[0], sind, cosd);
        m_Joint.EyesFront_Open.EyeballLeft  = m_Quard -> Vec2Rotation(point, m_EyesFront_Openjoint[1], sind, cosd);
        m_Joint.EyesFront_Open.EyeballRight = m_Quard -> Vec2Rotation(point, m_EyesFront_Openjoint[2], sind, cosd);
        m_Joint.EyesFront_Open.degree = degree;
    }

    void KennyJoint::SetEyeballLeft(spat::Vec2 point)
    {
        m_Quard -> SetPosXY(static_cast<int>(Part::EyeballLeft), point.x, point.y);
        m_Joint.EyeballLeft.EyesFront_Open = point;
    }

    void KennyJoint::SetEyeballRight(spat::Vec2 point)
    {
        m_Quard -> SetPosXY(static_cast<int>(Part::EyeballRight), point.x, point.y);
        m_Joint.EyeballRight.EyesFront_Open = point;
    }

    void KennyJoint::SetEyeCloseLeft(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Quard -> SetPosXY(static_cast<int>(Part::EyeCloseLeft), point.x, point.y);
        m_Quard -> SetDegree(static_cast<int>(Part::EyeCloseLeft), degree, sind, cosd);
        m_Joint.EyeCloseLeft.Face = point;
    }

    void KennyJoint::SetEyeCloseRight(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Quard -> SetPosXY(static_cast<int>(Part::EyeCloseRight), point.x, point.y);
        m_Quard -> SetDegree(static_cast<int>(Part::EyeCloseRight), degree, sind, cosd);
        m_Joint.EyeCloseRight.Face = point;
    }

    void KennyJoint::SetHatFront(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Quard -> SetPosXY(static_cast<int>(Part::HatFront), point.x, point.y);
        m_Quard -> SetDegree(static_cast<int>(Part::HatFront), degree, sind, cosd);
        m_Joint.HatFront.Face = point;
    }

    const spat::Vec2 m_HandLeft_PaperJoint[] = {
        -20.0f, -5.0f,     //ArmLeft_Open    
        -20.0f, -5.0f,     //ArmLeft_Bend
        -20.0f, -5.0f      //ArmFrontLeft_Basic
    };

    void KennyJoint::SetHandLeft_Paper(spat::Vec2 point, float degree, int rx)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Joint.HandLeft_Paper.Point.x = point.x;
        m_Joint.HandLeft_Paper.Point.y = point.y;
        spat::Vec2 pos;
        switch (rx)
        {
        case static_cast<int>(Part::ArmLeft_Open):
            pos = m_Quard -> Vec2Rotation(point, {m_HandLeft_PaperJoint[0].x * (-1), m_HandLeft_PaperJoint[0].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::ArmLeft_Bend):
            pos = m_Quard -> Vec2Rotation(point, {m_HandLeft_PaperJoint[1].x * (-1), m_HandLeft_PaperJoint[1].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::ArmFrontLeft_Basic):
            pos = m_Quard -> Vec2Rotation(point, {m_HandLeft_PaperJoint[2].x * (-1), m_HandLeft_PaperJoint[2].y * (-1)}, sind, cosd);
            break;
        default:
            pos = point;
            break;
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::HandLeft_Paper), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::HandLeft_Paper), degree, sind, cosd);
        m_Joint.HandLeft_Paper.ArmLeft_Open          = m_Quard -> Vec2Rotation(pos, m_HandLeft_PaperJoint[0], sind, cosd);
        m_Joint.HandLeft_Paper.ArmLeft_Bend          = m_Quard -> Vec2Rotation(pos, m_HandLeft_PaperJoint[1], sind, cosd);
        m_Joint.HandLeft_Paper.ArmFrontLeft_Basic    = m_Quard -> Vec2Rotation(pos, m_HandLeft_PaperJoint[2], sind, cosd);    
        m_Joint.HandLeft_Paper.degree = degree;
    }       

    const spat::Vec2 m_HandRight_PaperJoint[] = {
        20.0f, -5.0f,     //ArmRight_Open    
        20.0f, -5.0f,     //ArmRight_Bend
        20.0f, -5.0f      //ArmFrontRight_Basic
    };

    void KennyJoint::SetHandRight_Paper(spat::Vec2 point, float degree, int rx)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Joint.HandRight_Paper.Point.x = point.x;
        m_Joint.HandRight_Paper.Point.y = point.y;
        spat::Vec2 pos;
        switch (rx)
        {
        case static_cast<int>(Part::ArmRight_Open):
            pos = m_Quard -> Vec2Rotation(point, {m_HandRight_PaperJoint[0].x * (-1), m_HandRight_PaperJoint[0].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::ArmRight_Bend):
            pos = m_Quard -> Vec2Rotation(point, {m_HandRight_PaperJoint[1].x * (-1), m_HandRight_PaperJoint[1].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::ArmFrontRight_Basic):
            pos = m_Quard -> Vec2Rotation(point, {m_HandRight_PaperJoint[2].x * (-1), m_HandRight_PaperJoint[2].y * (-1)}, sind, cosd);
            break;
        default:
            pos = point;
            break;
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::HandRight_Paper), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::HandRight_Paper), degree, sind, cosd);
        m_Joint.HandRight_Paper.ArmRight_Open          = m_Quard -> Vec2Rotation(pos, m_HandRight_PaperJoint[0], sind, cosd);
        m_Joint.HandRight_Paper.ArmRight_Bend          = m_Quard -> Vec2Rotation(pos, m_HandRight_PaperJoint[1], sind, cosd);
        m_Joint.HandRight_Paper.ArmFrontRight_Basic    = m_Quard -> Vec2Rotation(pos, m_HandRight_PaperJoint[2], sind, cosd);    
        m_Joint.HandRight_Paper.degree = degree;
    }

    const spat::Vec2 m_HandLeft_RockJoint[] = {
        0.0f, 0.0f,     //ArmLeft_Open    
        0.0f, 0.0f,     //ArmLeft_Bend
        0.0f, 0.0f      //ArmFrontLeft_Basic
    };

    void KennyJoint::SetHandLeft_Rock(spat::Vec2 point, float degree, int rx)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Joint.HandLeft_Rock.Point.x = point.x;
        m_Joint.HandLeft_Rock.Point.y = point.y;
        spat::Vec2 pos;
        switch (rx)
        {
        case static_cast<int>(Part::ArmLeft_Open):
            pos = m_Quard -> Vec2Rotation(point, {m_HandLeft_RockJoint[0].x * (-1), m_HandLeft_RockJoint[0].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::ArmLeft_Bend):
            pos = m_Quard -> Vec2Rotation(point, {m_HandLeft_RockJoint[1].x * (-1), m_HandLeft_RockJoint[1].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::ArmFrontLeft_Basic):
            pos = m_Quard -> Vec2Rotation(point, {m_HandLeft_RockJoint[2].x * (-1), m_HandLeft_RockJoint[2].y * (-1)}, sind, cosd);
            break;
        default:
            pos = point;
            break;
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::HandLeft_Rock), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::HandLeft_Rock), degree, sind, cosd);
        m_Joint.HandLeft_Rock.ArmLeft_Open          = m_Quard -> Vec2Rotation(pos, m_HandLeft_RockJoint[0], sind, cosd);
        m_Joint.HandLeft_Rock.ArmLeft_Bend          = m_Quard -> Vec2Rotation(pos, m_HandLeft_RockJoint[1], sind, cosd);
        m_Joint.HandLeft_Rock.ArmFrontLeft_Basic    = m_Quard -> Vec2Rotation(pos, m_HandLeft_RockJoint[2], sind, cosd);    
        m_Joint.HandLeft_Rock.degree = degree;
    }       

    const spat::Vec2 m_HandRight_RockJoint[] = {
        0.0f, 0.0f,     //ArmRight_Open    
        0.0f, 0.0f,     //ArmRight_Bend
        0.0f, 0.0f      //ArmFrontRight_Basic
    };

    void KennyJoint::SetHandRight_Rock(spat::Vec2 point, float degree, int rx)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        m_Joint.HandRight_Rock.Point.x = point.x;
        m_Joint.HandRight_Rock.Point.y = point.y;
        spat::Vec2 pos;
        switch (rx)
        {
        case static_cast<int>(Part::ArmRight_Open):
            pos = m_Quard -> Vec2Rotation(point, {m_HandRight_RockJoint[0].x * (-1), m_HandRight_RockJoint[0].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::ArmRight_Bend):
            pos = m_Quard -> Vec2Rotation(point, {m_HandRight_RockJoint[1].x * (-1), m_HandRight_RockJoint[1].y * (-1)}, sind, cosd);
            break;
        case static_cast<int>(Part::ArmFrontRight_Basic):
            pos = m_Quard -> Vec2Rotation(point, {m_HandRight_RockJoint[2].x * (-1), m_HandRight_RockJoint[2].y * (-1)}, sind, cosd);
            break;
        default:
            pos = point;
            break;
        }
        m_Quard -> SetPosXY(static_cast<int>(Part::HandRight_Rock), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::HandRight_Rock), degree, sind, cosd);
        m_Joint.HandRight_Rock.ArmRight_Open          = m_Quard -> Vec2Rotation(pos, m_HandRight_RockJoint[0], sind, cosd);
        m_Joint.HandRight_Rock.ArmRight_Bend          = m_Quard -> Vec2Rotation(pos, m_HandRight_RockJoint[1], sind, cosd);
        m_Joint.HandRight_Rock.ArmFrontRight_Basic    = m_Quard -> Vec2Rotation(pos, m_HandRight_RockJoint[2], sind, cosd);    
        m_Joint.HandRight_Rock.degree = degree;
    }       

    const spat::Vec2 m_EyebrowLeftJoint[] = {
        0.0f, 0.0f,     //Face    
    };

    void KennyJoint::SetEyebrowLeft(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_EyebrowLeftJoint[0].x * (-1), m_EyebrowLeftJoint[0].y * (-1)}, sind, cosd);
        m_Quard -> SetPosXY(static_cast<int>(Part::EyebrowLeft), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::EyebrowLeft), degree, sind, cosd);
        m_Joint.EyebrowLeft.Face = m_Quard -> Vec2Rotation(pos, m_EyebrowLeftJoint[0], sind, cosd);
        m_Joint.EyebrowLeft.degree = degree;
    }    

    const spat::Vec2 m_EyebrowRightJoint[] = {
        0.0f, 0.0f,     //Face    
    };

    void KennyJoint::SetEyebrowRight(spat::Vec2 point, float degree)
    {
        double sind = SIN(degree);
        double cosd = COS(degree);
        spat::Vec2 pos = m_Quard -> Vec2Rotation(point, {m_EyebrowRightJoint[0].x * (-1), m_EyebrowRightJoint[0].y * (-1)}, sind, cosd);
        m_Quard -> SetPosXY(static_cast<int>(Part::EyebrowRight), pos.x, pos.y);
        m_Quard -> SetDegree(static_cast<int>(Part::EyebrowRight), degree, sind, cosd);
        m_Joint.EyebrowRight.Face = m_Quard -> Vec2Rotation(pos, m_EyebrowRightJoint[0], sind, cosd);
        m_Joint.EyebrowRight.degree = degree;
    }
}