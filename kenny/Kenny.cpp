#include "Kenny.h"

namespace kenny
{
    Kenny::Kenny(spat::TexQuard2D& quard)
        :m_Quard(quard)
    {
        for(int i = 0; i < static_cast<int>(Part::PartNumber); i++)
        {
            m_QuardPS[i].size.x = (float)g_TexData[i].size.x;
            m_QuardPS[i].size.y = (float)g_TexData[i].size.y;
            m_QuardPS[i].pos.x  = (float)g_TexData[i].basicPos.x;
            m_QuardPS[i].pos.y  = (float)g_TexData[i].basicPos.y;
            m_TexPS[i].size.x   = (float)g_TexData[i].size.x     / static_cast<float>(Sheetsize::x);
            m_TexPS[i].size.y   = (float)g_TexData[i].size.y     / static_cast<float>(Sheetsize::y);
            m_TexPS[i].pos.x    = (float)g_TexData[i].sheetPos.x / static_cast<float>(Sheetsize::x);
            m_TexPS[i].pos.y    = (float)g_TexData[i].sheetPos.y / static_cast<float>(Sheetsize::y);
            m_Quard.CreateQuard(m_QuardPS[i], m_TexPS[i], 0.0f);
            m_Quard.AddColor(i, {0.04f * (i+10), 0.04f * (i+10), 0.04f * (i+10), 1.0f});
        }
        m_Quard.DeleteSize(static_cast<int>(Part::ArmLeft_Open));
        m_Quard.DeleteSize(static_cast<int>(Part::ArmRight_Open));
        m_Quard.DeleteSize(static_cast<int>(Part::ArmLeft_Bend));
        m_Quard.DeleteSize(static_cast<int>(Part::ArmRight_Bend));
        m_Quard.DeleteSize(static_cast<int>(Part::HandLeft_Paper));
        m_Quard.DeleteSize(static_cast<int>(Part::HandRight_Paper));
        m_Quard.DeleteSize(static_cast<int>(Part::HandLeft_Paper));
        // m_Quard.DeleteSize(static_cast<int>(Part::BadyFront));
        // m_Quard.DeleteSize(static_cast<int>(Part::HatFront));
        // m_Quard.DeleteSize(static_cast<int>(Part::Face));

        SetEyebrow(false);
        m_CurrentStyle.eyes = static_cast<int>(Part::EyebrowRight);
        m_CurrentStyle.arm = {static_cast<int>(Part::ArmFrontRight_Basic), static_cast<int>(Part::ArmFrontLeft_Basic)};
        m_CurrentStyle.hand = {static_cast<int>(Part::HandRight_Rock), static_cast<int>(Part::HandLeft_Rock)};

        SetArm(static_cast<int>(Part::ArmRight_Open));
    }

    Kenny::~Kenny()
    {

    }

    void Kenny::SetHand(int shape)
    {
        switch (shape)
        {
        case static_cast<int>(Part::HandLeft_Paper):
            m_Quard.RestoreSize(static_cast<int>(Part::HandLeft_Paper));
            m_Quard.DeleteSize(m_CurrentStyle.hand.left);
            m_CurrentStyle.hand.left = shape;
            break;

        case static_cast<int>(Part::HandRight_Paper):
            m_Quard.RestoreSize(static_cast<int>(Part::HandRight_Paper));
            m_Quard.DeleteSize(m_CurrentStyle.hand.right);
            m_CurrentStyle.hand.right = shape;
            break;

        case static_cast<int>(Part::HandLeft_Rock):
            m_Quard.RestoreSize(static_cast<int>(Part::HandLeft_Rock));
            m_Quard.DeleteSize(m_CurrentStyle.hand.left);
            m_CurrentStyle.hand.left = shape;
            break;

        case static_cast<int>(Part::HandRight_Rock):
            m_Quard.RestoreSize(static_cast<int>(Part::HandRight_Rock));
            m_Quard.DeleteSize(m_CurrentStyle.hand.right);
            m_CurrentStyle.hand.right = shape;
            break;
        
        default:

            break;
        }
    }

    void Kenny::SetEyebrow(bool state)
    {
        if(state)
        {
            m_Quard.RestoreSize(static_cast<int>(Part::EyebrowRight));
            m_Quard.RestoreSize(static_cast<int>(Part::EyebrowLeft));
            m_CurrentStyle.eyebrow = true;
        }
        else
        {
            m_Quard.DeleteSize(static_cast<int>(Part::EyebrowRight));
            m_Quard.DeleteSize(static_cast<int>(Part::EyebrowLeft));
            m_CurrentStyle.eyebrow = false;
        }
    }

    void Kenny::SetArm(int shape)
    {
        switch (shape)
        {
        case static_cast<int>(Part::ArmLeft_Open):
            m_Quard.RestoreSize(static_cast<int>(Part::ArmLeft_Open));
            m_Quard.DeleteSize(m_CurrentStyle.arm.left);
            m_CurrentStyle.arm.left = shape;
            break;

        case static_cast<int>(Part::ArmRight_Open):
            m_Quard.RestoreSize(static_cast<int>(Part::ArmRight_Open));
            m_Quard.DeleteSize(m_CurrentStyle.arm.right);
            m_CurrentStyle.arm.right = shape;
            break;

        case static_cast<int>(Part::ArmLeft_Bend):
            m_Quard.RestoreSize(static_cast<int>(Part::ArmLeft_Bend));
            m_Quard.DeleteSize(m_CurrentStyle.arm.left);
            m_CurrentStyle.arm.left = shape;
            break;

        case static_cast<int>(Part::ArmRight_Bend):
            m_Quard.RestoreSize(static_cast<int>(Part::ArmRight_Bend));
            m_Quard.DeleteSize(m_CurrentStyle.arm.right);
            m_CurrentStyle.arm.right = shape;
            break;

        case static_cast<int>(Part::ArmFrontLeft_Basic):
            m_Quard.RestoreSize(static_cast<int>(Part::ArmFrontLeft_Basic));
            m_Quard.DeleteSize(m_CurrentStyle.arm.left);
            m_CurrentStyle.arm.left = shape;
            break;

        case static_cast<int>(Part::ArmFrontRight_Basic):
            m_Quard.RestoreSize(static_cast<int>(Part::ArmFrontRight_Basic));
            m_Quard.DeleteSize(m_CurrentStyle.arm.right);
            m_CurrentStyle.arm.right = shape;
            break;
        
        default:

            break;
        }
    }
}