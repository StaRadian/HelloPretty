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
    public:
        Kenny(float size);
        ~Kenny();
        spat::PosSizeData GetQuardPS(int i) const {return m_QuardPS[i];}
        spat::PosSizeData GetTexPS(int i) const {return m_TexPS[i];}
        int GetDataSize() {return static_cast<int>(Part::PartNumber);}
    };

}