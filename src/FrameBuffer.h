#pragma once
#include <GL/glew.h>

namespace spat
{
    class FrameBuffer
    {
    private:
        unsigned int m_RendererID;
    public:
        FrameBuffer();
        ~FrameBuffer();

        unsigned int TextureAttach(int width, int height);
        unsigned int DepthTextureAttach(int width, int height);
        unsigned int DepthBufferAttach(int width, int height);
        void Bind() const;
        void Unbind() const;
    };
}