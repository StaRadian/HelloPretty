#pragma once
#include "Kenny.h"

#include "src/TexQuard2D.h"

#include <unordered_map>

namespace kenny
{
    struct PantFrontJoint
    {
        spat::Vec2 BadyFront;
    };
    struct BodyFrontJoint
    {
        spat::Vec2 PantFront;
        spat::Vec2 ArmLeft_Open;       
        spat::Vec2 ArmRight_Open;      
        spat::Vec2 ArmLeft_Bend;       
        spat::Vec2 ArmRight_Bend;    
        spat::Vec2 ArmFrontLeft_Basic; 
        spat::Vec2 ArmFrontRight_Basic;
        spat::Vec2 Face;
    };
    struct ArmLeft_OpenJoint
    {
        spat::Vec2 BadyFront;
        spat::Vec2 HandLeft_Paper; 
        spat::Vec2 HandLeft_Rock;
    };
    struct ArmRight_OpenJoint
    {
        spat::Vec2 BadyFront;    
        spat::Vec2 HandRight_Paper;
        spat::Vec2 HandRight_Rock;
    };
    struct ArmLeft_BendJoint
    {
        spat::Vec2 BadyFront;    
        spat::Vec2 HandLeft_Paper;
        spat::Vec2 HandLeft_Rock;
    };
    struct ArmRight_BendJoint
    {
        spat::Vec2 BadyFront;    
        spat::Vec2 HandRight_Paper;
        spat::Vec2 HandRight_Rock;
    };
    struct ArmFrontLeft_BasicJoint
    {
        spat::Vec2 BadyFront;    
        spat::Vec2 HandLeft_Paper;
        spat::Vec2 HandLeft_Rock;
    };
    struct ArmFrontRight_BasicJoint
    {
        spat::Vec2 BadyFront;    
        spat::Vec2 HandRight_Paper;
        spat::Vec2 HandRight_Rock;
    };
    struct FaceJoint
    {
        spat::Vec2 BadyFront;    
        spat::Vec2 EyesFront_Open;
        spat::Vec2 HatFront;
        spat::Vec2 EyebrowLeft;
        spat::Vec2 EyebrowRight;
    };
    struct EyesFront_OpenJoint
    {
        spat::Vec2 Face;
        spat::Vec2 EyeballLeft;
        spat::Vec2 EyeballRight;
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
    };
    struct HandLeft_PaperJoint
    {
        spat::Vec2 ArmLeft_Open;    
        spat::Vec2 ArmLeft_Bend;
        spat::Vec2 ArmFrontLeft_Basic;
    };
    struct HandRight_PaperJoint
    {
        spat::Vec2 ArmRight_Open;    
        spat::Vec2 ArmRight_Bend;
        spat::Vec2 ArmFrontRight_Basic;
    };
    struct HandLeft_RockJoint
    {
        spat::Vec2 ArmLeft_Open;    
        spat::Vec2 ArmLeft_Bend;
        spat::Vec2 ArmFrontLeft_Basic;
    };
    struct HandRight_RockJoint
    {
        spat::Vec2 ArmRight_Open;    
        spat::Vec2 ArmRight_Bend;
        spat::Vec2 ArmFrontRight_Basic;
    };
    struct EyebrowLeftJoint
    {
        spat::Vec2 Face;   
    };
    struct EyebrowRightJoint
    {
        spat::Vec2 Face;   
    };
    struct Joint
    {
        PantFrontJoint PantFront;
        BodyFrontJoint BodyFront;
        ArmLeft_OpenJoint ArmLeft_Open;
        ArmRight_OpenJoint ArmRight_Open;
        ArmLeft_BendJoint ArmLeft_Bend;
        ArmRight_BendJoint ArmRight_Bend;
        ArmFrontLeft_BasicJoint ArmFrontLeft_Basic;
        ArmFrontRight_BasicJoint ArmFrontRight_Basic;
        FaceJoint Face;
        EyesFront_OpenJoint EyesFront_Open;
        EyeballLeftJoint EyeballLeft;
        EyeballRightJoint EyeballRight;
        HatFrontJoint HatFront;
        HandLeft_PaperJoint HandLeft_Paper;  
        HandRight_PaperJoint HandRight_Paper;
        HandLeft_RockJoint HandLeft_Rock;    
        HandRight_RockJoint HandRight_Rock;  
        EyebrowLeftJoint EyebrowLeft;
        EyebrowRightJoint EyebrowRight;
    };

    class KennyPart : public Kenny
    {
    private:
    public:
        void SetPantFront(spat::Vec2 point, float degree);
        void SetBadyFront(spat::Vec2 point, float degree);
        void SetArmLeft_Open(spat::Vec2 point, float degree);
        void SetArmRight_Open(spat::Vec2 point, float degree);
        void SetArmLeft_Bend(spat::Vec2 point, float degree);
        void SetArmRight_Bend(spat::Vec2 point, float degree);
        void SetArmFrontLeft_Basic(spat::Vec2 point, float degree);
        void SetArmFrontRight_Basic(spat::Vec2 point, float degree);
        void SetFace(spat::Vec2 point, float degree);
        void SetEyesFront_Open(spat::Vec2 point, float degree);
        void SetEyeballLeft(spat::Vec2 point, float degree);
        void SetEyeballRight(spat::Vec2 point, float degree);
        void SetHatFront(spat::Vec2 point, float degree);
        void SetHandLeft_Paper(spat::Vec2 point, float degree);
        void SetHandRight_Paper(spat::Vec2 point, float degree);
        void SetHandLeft_Rock(spat::Vec2 point, float degree);
        void SetHandRight_Rock(spat::Vec2 point, float degree);
        void SetEyebrowLeft(spat::Vec2 point, float degree);
        void SetEyebrowRight(spat::Vec2 point, float degree);
        
        float m_f;
        Joint m_Joint;
    };
}