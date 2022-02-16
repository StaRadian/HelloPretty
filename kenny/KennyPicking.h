#pragma once
#include "src/FrameBuffer.h"
#include "src/Shader.h"

namespace kenny
{
    class KennyPicking
    {
    private:
        spat::FrameBuffer fbo;
        spat::Shader& m_Shader;
    public:
        KennyPicking(int width, int height, spat::Shader &shader);
        ~KennyPicking();
        void HitboxRender(unsigned int indexSize);
    };
}