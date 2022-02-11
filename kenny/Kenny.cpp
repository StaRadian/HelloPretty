#include "Kenny.h"

namespace kenny
{
    Kenny::Kenny(float size)
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
        }
    }

    Kenny::~Kenny()
    {

    }
}