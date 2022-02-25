#pragma once
#include "Kenny.h"

namespace kenny
{
    struct RelativeDirectionPos
    {
        float top;
        float left;
        float bottom;
        float right;
        float diagonal;
    };
    struct PantFrontJoint
    {
        spat::Vec2 BadyFront;
        RelativeDirectionPos RDPos;
        float degree;
    };
    struct BadyFrontJoint
    {
        spat::Vec2 PantFront;
        spat::Vec2 ArmLeft_Open;       
        spat::Vec2 ArmRight_Open;      
        spat::Vec2 ArmLeft_Bend;       
        spat::Vec2 ArmRight_Bend;    
        spat::Vec2 ArmFrontLeft_Basic; 
        spat::Vec2 ArmFrontRight_Basic;
        spat::Vec2 Face;
        RelativeDirectionPos RDPos;
        float degree;
    };
    struct ArmLeft_OpenJoint
    {
        spat::Vec2 BadyFront;
        spat::Vec2 HandLeft_Paper; 
        spat::Vec2 HandLeft_Rock;
        RelativeDirectionPos RDPos;
        float degree;
    };
    struct ArmRight_OpenJoint
    {
        spat::Vec2 BadyFront;    
        spat::Vec2 HandRight_Paper;
        spat::Vec2 HandRight_Rock;
        RelativeDirectionPos RDPos;
        float degree;
    };
    struct ArmLeft_BendJoint
    {
        spat::Vec2 BadyFront;    
        spat::Vec2 HandLeft_Paper;
        spat::Vec2 HandLeft_Rock;
        RelativeDirectionPos RDPos;
        float degree;
    };
    struct ArmRight_BendJoint
    {
        spat::Vec2 BadyFront;    
        spat::Vec2 HandRight_Paper;
        spat::Vec2 HandRight_Rock;
        RelativeDirectionPos RDPos;
        float degree;
    };
    struct ArmFrontLeft_BasicJoint
    {
        spat::Vec2 BadyFront;    
        spat::Vec2 HandLeft_Paper;
        spat::Vec2 HandLeft_Rock;
        RelativeDirectionPos RDPos;
        float degree;
    };
    struct ArmFrontRight_BasicJoint
    {
        spat::Vec2 BadyFront;    
        spat::Vec2 HandRight_Paper;
        spat::Vec2 HandRight_Rock;
        RelativeDirectionPos RDPos;
        float degree;
    };
    struct FaceJoint
    {
        spat::Vec2 BadyFront;    
        spat::Vec2 EyesFront_Open;
        spat::Vec2 HatFront;
        spat::Vec2 EyebrowLeft;
        spat::Vec2 EyebrowRight;
        RelativeDirectionPos RDPos;
        float degree;
    };
    struct EyesFront_OpenJoint
    {
        spat::Vec2 Face;
        spat::Vec2 EyeballLeft;
        spat::Vec2 EyeballRight;
        float degree;
    };
    struct EyeballLeftJoint
    {
        spat::Vec2 EyesFront_Open;
    };
    struct EyeballRightJoint
    {
        spat::Vec2 EyesFront_Open;
    };
    struct HatFrontJoint
    {
        spat::Vec2 Face;
        RelativeDirectionPos RDPos;
    };
    struct HandLeft_PaperJoint
    {
        spat::Vec2 ArmLeft_Open;    
        spat::Vec2 ArmLeft_Bend;
        spat::Vec2 ArmFrontLeft_Basic;
        RelativeDirectionPos RDPos;
        float degree;
    };
    struct HandRight_PaperJoint
    {
        spat::Vec2 ArmRight_Open;    
        spat::Vec2 ArmRight_Bend;
        spat::Vec2 ArmFrontRight_Basic;
        RelativeDirectionPos RDPos;
        float degree;
    };
    struct HandLeft_RockJoint
    {
        spat::Vec2 ArmLeft_Open;    
        spat::Vec2 ArmLeft_Bend;
        spat::Vec2 ArmFrontLeft_Basic;
        RelativeDirectionPos RDPos;
        float degree;
    };
    struct HandRight_RockJoint
    {
        spat::Vec2 ArmRight_Open;    
        spat::Vec2 ArmRight_Bend;
        spat::Vec2 ArmFrontRight_Basic;
        RelativeDirectionPos RDPos;
        float degree;
    };
    struct EyebrowLeftJoint
    {
        spat::Vec2 Face;   
        float degree;
    };
    struct EyebrowRightJoint
    {
        spat::Vec2 Face;   
        float degree;
    };
    struct Joint
    {
        PantFrontJoint              PantFront;
        BadyFrontJoint              BadyFront;
        ArmLeft_OpenJoint           ArmLeft_Open;
        ArmRight_OpenJoint          ArmRight_Open;
        ArmLeft_BendJoint           ArmLeft_Bend;
        ArmRight_BendJoint          ArmRight_Bend;
        ArmFrontLeft_BasicJoint     ArmFrontLeft_Basic;
        ArmFrontRight_BasicJoint    ArmFrontRight_Basic;
        FaceJoint                   Face;
        EyesFront_OpenJoint         EyesFront_Open;
        EyeballLeftJoint            EyeballLeft;
        EyeballRightJoint           EyeballRight;
        HatFrontJoint               HatFront;
        HandLeft_PaperJoint         HandLeft_Paper;  
        HandRight_PaperJoint        HandRight_Paper;
        HandLeft_RockJoint          HandLeft_Rock;    
        HandRight_RockJoint         HandRight_Rock;  
        EyebrowLeftJoint            EyebrowLeft;
        EyebrowRightJoint           EyebrowRight;
    };

    class KennyJoint : public Kenny
    {
    private:
    public:
        KennyJoint(spat::TexQuard2D* quard) 
            : Kenny(quard)
        {
            m_Joint.PantFront.RDPos.diagonal            = sqrt(g_TexData[static_cast<int>(Part::PantFront)].size.x              *);
            m_Joint.BadyFront.RDPos.diagonal            = sqrt(g_TexData[static_cast<int>(Part::BadyFront)].size.x              *);
            m_Joint.ArmLeft_Open.RDPos.diagonal         = sqrt(g_TexData[static_cast<int>(Part::ArmLeft_Open)].size.x           *);
            m_Joint.ArmRight_Open.RDPos.diagonal        = sqrt(g_TexData[static_cast<int>(Part::ArmRight_Open)].size.x          *);
            m_Joint.ArmLeft_Bend.RDPos.diagonal         = sqrt(g_TexData[static_cast<int>(Part::ArmLeft_Bend)].size.x           *);
            m_Joint.ArmRight_Bend.RDPos.diagonal        = sqrt(g_TexData[static_cast<int>(Part::ArmRight_Bend)].size.x          *);
            m_Joint.ArmFrontLeft_Basic.RDPos.diagonal   = sqrt(g_TexData[static_cast<int>(Part::ArmFrontLeft_Basic)].size.x     *);
            m_Joint.ArmFrontRight_Basic.RDPos.diagonal  = sqrt(g_TexData[static_cast<int>(Part::ArmFrontRight_Basic)].size.x    *);
            m_Joint.Face.RDPos.diagonal                 = sqrt(g_TexData[static_cast<int>(Part::Face)].size.x                   *);
            m_Joint.HatFront.RDPos.diagonal             = sqrt(g_TexData[static_cast<int>(Part::HatFront)].size.x               *);
            m_Joint.HandLeft_Paper.RDPos.diagonal       = sqrt(g_TexData[static_cast<int>(Part::HandLeft_Paper)].size.x         *);
            m_Joint.HandRight_Paper.RDPos.diagonal      = sqrt(g_TexData[static_cast<int>(Part::HandRight_Paper)].size.x        *);
            m_Joint.HandLeft_Rock.RDPos.diagonal        = sqrt(g_TexData[static_cast<int>(Part::HandLeft_Rock)].size.x          *);
            m_Joint.HandRight_Rock.RDPos.diagonal       = sqrt(g_TexData[static_cast<int>(Part::HandRight_Rock)].size.x         *);
        }
        void SetPantFront(spat::Vec2 point, float degree);
        void SetBadyFront(spat::Vec2 point, float degree, int rx);
        void SetArmLeft_Open(spat::Vec2 point, float degree, int rx);
        void SetArmRight_Open(spat::Vec2 point, float degree, int rx);
        void SetArmLeft_Bend(spat::Vec2 point, float degree, int rx);
        void SetArmRight_Bend(spat::Vec2 point, float degree, int rx);
        void SetArmFrontLeft_Basic(spat::Vec2 point, float degree, int rx);
        void SetArmFrontRight_Basic(spat::Vec2 point, float degree, int rx);
        void SetFace(spat::Vec2 point, float degree);
        void SetEyesFront_Open(spat::Vec2 point, float degree);
        void SetEyeballLeft(spat::Vec2 point);
        void SetEyeballRight(spat::Vec2 point);
        void SetHatFront(spat::Vec2 point, float degree);
        void SetHandLeft_Paper(spat::Vec2 point, float degree, int rx);
        void SetHandRight_Paper(spat::Vec2 point, float degree, int rx);
        void SetHandLeft_Rock(spat::Vec2 point, float degree, int rx);
        void SetHandRight_Rock(spat::Vec2 point, float degree, int rx);
        void SetEyebrowLeft(spat::Vec2 point, float degree);
        void SetEyebrowRight(spat::Vec2 point, float degree);
        
        float m_f;
        Joint m_Joint;
    };
}