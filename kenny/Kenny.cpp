#include "Kenny.h"

namespace kenny
{
    Kenny::Kenny(spat::TexQuard2D* quard)
        :m_Quard(quard)
    {
        for(int i = 0; i < static_cast<int>(Part::PartNumber); i++)
        {
            m_QuardPS[i].size.x = g_TexData[i].size.x;
            m_QuardPS[i].size.y = g_TexData[i].size.y;
            m_QuardPS[i].pos.x  = g_TexData[i].basicPos.x;
            m_QuardPS[i].pos.y  = g_TexData[i].basicPos.y;
            m_TexPS[i].size.x   = g_TexData[i].size.x     / static_cast<float>(Sheetsize::x);
            m_TexPS[i].size.y   = g_TexData[i].size.y     / static_cast<float>(Sheetsize::y);
            m_TexPS[i].pos.x    = g_TexData[i].sheetPos.x / static_cast<float>(Sheetsize::x);
            m_TexPS[i].pos.y    = g_TexData[i].sheetPos.y / static_cast<float>(Sheetsize::y);
            m_Quard -> CreateQuard(m_QuardPS[i], m_TexPS[i], 0.0f);
            m_Quard -> AddColor(i, {0.02f * (i + 1), 0.02f * (i + 1), 0.02f * (i + 1), 1.0f});
        }
        m_Quard -> DeleteSize(static_cast<int>(Part::ArmLeft_Open));
        m_Quard -> DeleteSize(static_cast<int>(Part::ArmRight_Open));
        m_Quard -> DeleteSize(static_cast<int>(Part::ArmLeft_Bend));
        m_Quard -> DeleteSize(static_cast<int>(Part::ArmRight_Bend));
        m_Quard -> DeleteSize(static_cast<int>(Part::HandLeft_Paper));
        m_Quard -> DeleteSize(static_cast<int>(Part::HandRight_Paper));

        ViewEyebrow(false);
        m_CurrentStyle.arm = {static_cast<int>(Part::ArmFrontRight_Basic), static_cast<int>(Part::ArmFrontLeft_Basic)};
        m_CurrentStyle.hand = {static_cast<int>(Part::HandRight_Rock), static_cast<int>(Part::HandLeft_Rock)};
    }

    Kenny::~Kenny()
    {

    }

    void Kenny::ViewArm(int shape)
    {
        switch (shape)
        {
        case static_cast<int>(Part::ArmLeft_Open):
            m_Quard -> RestoreSize(static_cast<int>(Part::ArmLeft_Open));
            m_Quard -> DeleteSize(m_CurrentStyle.arm.left);
            m_CurrentStyle.arm.left = shape;
            break;

        case static_cast<int>(Part::ArmRight_Open):
            m_Quard -> RestoreSize(static_cast<int>(Part::ArmRight_Open));
            m_Quard -> DeleteSize(m_CurrentStyle.arm.right);
            m_CurrentStyle.arm.right = shape;
            break;

        case static_cast<int>(Part::ArmLeft_Bend):
            m_Quard -> RestoreSize(static_cast<int>(Part::ArmLeft_Bend));
            m_Quard -> DeleteSize(m_CurrentStyle.arm.left);
            m_CurrentStyle.arm.left = shape;
            break;

        case static_cast<int>(Part::ArmRight_Bend):
            m_Quard -> RestoreSize(static_cast<int>(Part::ArmRight_Bend));
            m_Quard -> DeleteSize(m_CurrentStyle.arm.right);
            m_CurrentStyle.arm.right = shape;
            break;

        case static_cast<int>(Part::ArmFrontLeft_Basic):
            m_Quard -> RestoreSize(static_cast<int>(Part::ArmFrontLeft_Basic));
            m_Quard -> DeleteSize(m_CurrentStyle.arm.left);
            m_CurrentStyle.arm.left = shape;
            break;

        case static_cast<int>(Part::ArmFrontRight_Basic):
            m_Quard -> RestoreSize(static_cast<int>(Part::ArmFrontRight_Basic));
            m_Quard -> DeleteSize(m_CurrentStyle.arm.right);
            m_CurrentStyle.arm.right = shape;
            break;
        
        default:

            break;
        }
    }

    void Kenny::ViewHand(int shape)
    {
        switch (shape)
        {
        case static_cast<int>(Part::HandLeft_Paper):
            m_Quard -> RestoreSize(static_cast<int>(Part::HandLeft_Paper));
            m_Quard -> DeleteSize(m_CurrentStyle.hand.left);
            m_CurrentStyle.hand.left = shape;
            break;

        case static_cast<int>(Part::HandRight_Paper):
            m_Quard -> RestoreSize(static_cast<int>(Part::HandRight_Paper));
            m_Quard -> DeleteSize(m_CurrentStyle.hand.right);
            m_CurrentStyle.hand.right = shape;
            break;

        case static_cast<int>(Part::HandLeft_Rock):
            m_Quard -> RestoreSize(static_cast<int>(Part::HandLeft_Rock));
            m_Quard -> DeleteSize(m_CurrentStyle.hand.left);
            m_CurrentStyle.hand.left = shape;
            break;

        case static_cast<int>(Part::HandRight_Rock):
            m_Quard -> RestoreSize(static_cast<int>(Part::HandRight_Rock));
            m_Quard -> DeleteSize(m_CurrentStyle.hand.right);
            m_CurrentStyle.hand.right = shape;
            break;
        
        default:

            break;
        }
    }

    void Kenny::ViewEyebrow(bool state)
    {
        if(state == true)
        {
            m_Quard -> RestoreSize(static_cast<int>(Part::EyebrowRight));
            m_Quard -> RestoreSize(static_cast<int>(Part::EyebrowLeft));
            m_CurrentStyle.eyebrow = true;
        }
        else
        {
            m_Quard -> DeleteSize(static_cast<int>(Part::EyebrowRight));
            m_Quard -> DeleteSize(static_cast<int>(Part::EyebrowLeft));
            m_CurrentStyle.eyebrow = false;
        }
    }


    int Kenny::GetColorName(float color)
    {
        for(int i = 0; i < static_cast<int>(Part::PartNumber); i++)
        {
            if((color < (i + 1.5) * 0.02) && (color > (i + 0.5) * 0.02))
            {
                return i;
            }
        }
        return -1;
    }

    void Kenny::GetKennySize()
    {
        m_MaxSize.x = m_Quard -> GetElement(static_cast<int>(Part::PantFront)) -> v0.Position2D.x;
        m_MaxSize.y = m_Quard -> GetElement(static_cast<int>(Part::PantFront)) -> v0.Position2D.y;
        m_MinSize.x = m_MaxSize.x;
        m_MinSize.y = m_MaxSize.y;

        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::PantFront)) -> v1.Position2D);
        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::PantFront)) -> v2.Position2D);
        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::PantFront)) -> v3.Position2D);

        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::BadyFront)) -> v0.Position2D);
        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::BadyFront)) -> v1.Position2D);
        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::BadyFront)) -> v2.Position2D);
        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::BadyFront)) -> v3.Position2D);
        
#if 0
        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::Face)) -> v0.Position2D);
        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::Face)) -> v1.Position2D);
        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::Face)) -> v2.Position2D);
        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::Face)) -> v3.Position2D);
#endif

        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::HatFront)) -> v0.Position2D);
        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::HatFront)) -> v1.Position2D);
        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::HatFront)) -> v2.Position2D);
        ComparisonSize(m_Quard -> GetElement(static_cast<int>(Part::HatFront)) -> v3.Position2D);
        


        //////////////////////////////

        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.arm.left) -> v0.Position2D);
        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.arm.left) -> v1.Position2D);
        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.arm.left) -> v2.Position2D);
        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.arm.left) -> v3.Position2D);

        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.arm.right) -> v0.Position2D);
        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.arm.right) -> v1.Position2D);
        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.arm.right) -> v2.Position2D);
        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.arm.right) -> v3.Position2D);

        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.hand.left) -> v0.Position2D);
        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.hand.left) -> v1.Position2D);
        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.hand.left) -> v2.Position2D);
        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.hand.left) -> v3.Position2D);

        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.hand.right) -> v0.Position2D);
        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.hand.right) -> v1.Position2D);
        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.hand.right) -> v2.Position2D);
        ComparisonSize(m_Quard -> GetElement(m_CurrentStyle.hand.right) -> v3.Position2D);
    }
    
    void Kenny::ComparisonSize(spat::Vec2 input)
    {
        if(m_MaxSize.x < input.x)
        {
            m_MaxSize.x = input.x;
        }
        else if(m_MinSize.x > input.x)
        {
            m_MinSize.x = input.x;
        }
        if(m_MaxSize.y < input.y)
        {
            m_MaxSize.y = input.y;
        }
        else if(m_MinSize.y > input.y)
        {
            m_MinSize.y = input.y;
        }
    }
}