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
    protected:
        spat::TexQuard2D* m_Quard;
    public:
        Style m_CurrentStyle;
        Kenny(spat::TexQuard2D* quard);
        ~Kenny();
        int GetDataSize() {return static_cast<int>(Part::PartNumber);}
        void ViewHand(int shape);
        void ViewEyebrow(bool state);
        void ViewArm(int shape);
        int GetColorName(float color);
    };

}