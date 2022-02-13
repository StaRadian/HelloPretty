#include "Kenny.h"

namespace kenny
{
    Kenny::Kenny(spat::TexQuard2D& quard, float size)
        :m_Quard(quard), m_Size(size)
    {
        for(int i = 0; i < static_cast<int>(Part::PartNumber); i++)
        {
            m_QuardPS[i].size.x = (float)g_TexData[i].size.x     * size;
            m_QuardPS[i].size.y = (float)g_TexData[i].size.y     * size;
            m_QuardPS[i].pos.x  = (float)g_TexData[i].basicPos.x * size;
            m_QuardPS[i].pos.y  = (float)g_TexData[i].basicPos.y * size;
            m_TexPS[i].size.x   = (float)g_TexData[i].size.x     / static_cast<float>(Sheetsize::x);
            m_TexPS[i].size.y   = (float)g_TexData[i].size.y     / static_cast<float>(Sheetsize::y);
            m_TexPS[i].pos.x    = (float)g_TexData[i].sheetPos.x / static_cast<float>(Sheetsize::x);
            m_TexPS[i].pos.y    = (float)g_TexData[i].sheetPos.y / static_cast<float>(Sheetsize::y);
            m_Quard.CreateQuard(m_QuardPS[i], m_TexPS[i], 0.0f);
        }
        m_Quard.DeleteSize(static_cast<int>(Part::ArmLeft_Open));
        m_Quard.DeleteSize(static_cast<int>(Part::ArmRight_Open));
        m_Quard.DeleteSize(static_cast<int>(Part::ArmLeft_Bend));
        m_Quard.DeleteSize(static_cast<int>(Part::ArmRight_Bend));
        m_Quard.DeleteSize(static_cast<int>(Part::HandLeft_Paper));
        m_Quard.DeleteSize(static_cast<int>(Part::HandRight_Paper));
        m_Quard.DeleteSize(static_cast<int>(Part::HandLeft_Paper));
        m_Quard.DeleteSize(static_cast<int>(Part::EyebrowLeft));
        m_CurrentStyle.eyes = static_cast<int>(Part::EyebrowRight);
        m_CurrentStyle.eyebrow = false;
        m_CurrentStyle.arm = {static_cast<int>(Part::ArmFrontRight_Basic), static_cast<int>(Part::ArmFrontLeft_Basic)};
        m_CurrentStyle.hand = {static_cast<int>(Part::HandRight_Rock), static_cast<int>(Part::HandLeft_Rock)};
    }

    Kenny::~Kenny()
    {

    }

    void Kenny::SetHand(int shape)
    {
        if((m_CurrentStyle.hand.left == shape) | (m_CurrentStyle.hand.right == shape)) return;

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
}