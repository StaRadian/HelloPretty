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
        m_Quard.SetSize(static_cast<int>(Part::ArmLeft_Open),0.0f,0.0f);
        m_Quard.SetSize(static_cast<int>(Part::ArmRight_Open),0.0f,0.0f);
        m_Quard.SetSize(static_cast<int>(Part::ArmLeft_Bend),0.0f,0.0f);
        m_Quard.SetSize(static_cast<int>(Part::ArmRight_Bend),0.0f,0.0f);
        m_Quard.SetSize(static_cast<int>(Part::HandLeft_Paper),0.0f,0.0f);
        m_Quard.SetSize(static_cast<int>(Part::HandRight_Paper),0.0f,0.0f);
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
            m_Quard.SetSize(static_cast<int>(Part::HandLeft_Paper),
                m_QuardPS[static_cast<int>(Part::HandLeft_Paper)].size.x,
                m_QuardPS[static_cast<int>(Part::HandLeft_Paper)].size.y);

            m_Quard.SetSize(m_CurrentStyle.hand.left, 0.0f, 0.0f);
            m_CurrentStyle.hand.left = shape;
            break;

        case static_cast<int>(Part::HandRight_Paper):
            m_CurrentStyle.hand.right = shape;
            break;

        case static_cast<int>(Part::HandLeft_Rock):
            m_CurrentStyle.hand.left = shape;
            break;

        case static_cast<int>(Part::HandRight_Rock):
            m_CurrentStyle.hand.right = shape;
            break;
        
        default:

            break;
        }
    }
}