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
        void ComparisonSize(spat::Vec2 input);
    protected:
        spat::TexQuard2D* m_Quard;
    public:
        Style m_CurrentStyle;
        spat::Vec2 m_MaxSize;
        spat::Vec2 m_MinSize;
        Kenny(spat::TexQuard2D* quard);
        ~Kenny();
        int GetDataSize() {return static_cast<int>(Part::PartNumber);}
        void ViewArm(int shape);
        void ViewHand(int shape);
        void ViewEyebrow(bool state);
        int GetColorName(float color);
        void GetKennySize();
    };

}