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
        float m_Size;
    public:
        Style m_CurrentStyle;
        Kenny(spat::TexQuard2D& quard, float size);
        ~Kenny();
        int GetDataSize() {return static_cast<int>(Part::PartNumber);}
        void SetHand(int shape);
        void SetEyebrow(bool state);
        void SetArm(int shape);
    };

}