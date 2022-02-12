#pragma once
#include "KennyTexData.h"
#include "src/TexQuard2D.h"

namespace kenny
{
    class Kenny
    {
    private:
        spat::PosSizeData m_QuardPS[static_cast<int>(Part::PartNumber)];
        spat::PosSizeData m_TexPS[static_cast<int>(Part::PartNumber)];
        spat::TexQuard2D& m_Quard;
        Style m_CurrentStyle;
        float m_Size;
        void SetHand(int shape);
    public:
        Kenny(spat::TexQuard2D& quard, float size);
        ~Kenny();
        int GetDataSize() {return static_cast<int>(Part::PartNumber);}
    };

}