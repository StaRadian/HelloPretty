#pragma once
#include "Kenny.h"

#include "src/TexQuard2D.h"

#include <unordered_map>

namespace kenny
{
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

    struct ArmRight_OpenJoint
    {
        spat::Vec2 BadyFront;
        spat::Vec2 HandLeft_Paper;    
        spat::Vec2 HandRight_Paper;
        spat::Vec2 HandLeft_Rock;
        spat::Vec2 HandRight_Rock;
    };

    struct Joint
    {
        BodyFrontJoint BodyFront;
        ArmRight_OpenJoint ArmRight_Open;
    };

    class KennyPart : public Kenny
    {
    private:
    public:
        void SetBadyFront(spat::Vec2 point, float degree);
        void SetArmRight_Open(spat::Vec2 point, float degree);
        
        Joint m_Joint;
    };
}