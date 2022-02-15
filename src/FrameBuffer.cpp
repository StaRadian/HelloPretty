#include "FrameBuffer.h"

#include "Debug.h"

namespace spat
{
    FrameBuffer::FrameBuffer()
    {
        GLCall(glGenFramebuffers(1, &m_RendererID));
        Bind();
    }

    FrameBuffer::~FrameBuffer()
    {
        GLCall(glDeleteFramebuffers(1, &m_RendererID));
    }

    unsigned int FrameBuffer::TextureAttach(int width, int height)
    {
        unsigned int texture;
        GLCall(glGenTextures(1, &texture));
        GLCall(glBindTexture(GL_TEXTURE_2D, texture)); //texture 2D

        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));   //gl doc 해석 필요
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

        GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL));
        GLCall(glBindTexture(GL_TEXTURE_2D, 0));
        GLCall(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0));
        return texture;
    }

    unsigned int FrameBuffer::DepthTextureAttach(int width, int height)
    {
        unsigned int texture;
        GLCall(glGenTextures(1, &texture));
        GLCall(glBindTexture(GL_TEXTURE_2D, texture)); //texture 2D

        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));   //gl doc 해석 필요
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

        GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32, width, height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL));
        GLCall(glBindTexture(GL_TEXTURE_2D, 0));
        GLCall(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, texture, 0));
        return texture;
    }

    unsigned int FrameBuffer::DepthBufferAttach(int width, int height)
    {
        unsigned int depthBuffer;
        GLCall(glGenRenderbuffers(1, &depthBuffer));
        GLCall(glBindRenderbuffer(GL_RENDERBUFFER, depthBuffer)); 
        GLCall(glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height));  
        GLCall(glBindRenderbuffer(GL_RENDERBUFFER, 0));       
        GLCall(glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, depthBuffer)); 
        return depthBuffer;
    }

    void FrameBuffer::Bind() const
    {
        GLCall(glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID));
    }

    void FrameBuffer::Unbind() const
    {
        GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));
    }
}