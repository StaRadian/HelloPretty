#include "Texture.h"

#include <GL/glew.h>
#include "stb_image/stb_image.h"
#include "Debug.h"

namespace spat
{
    Texture::Texture(const std::string& path)
        :m_RendererID(0), m_FilePath(path), m_LocalBuffer(nullptr), 
        m_Width(0), m_Height(0), m_BPP(0)
    {
        stbi_set_flip_vertically_on_load(1);    //upside down //opengl texture은 bottom left부터 시작
        m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);    //desired_channels: RGBA

        GLCall(glGenTextures(1, &m_RendererID));
        GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID)); //texture 2D

        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));   //gl doc 해석 필요
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));    //s&t like x&y
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

        GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));
        GLCall(glBindTexture(GL_TEXTURE_2D, 0));

        if(m_LocalBuffer)
            stbi_image_free(m_LocalBuffer);
    }

    Texture::~Texture()
    {
        GLCall(glDeleteTextures(1, &m_RendererID));
    }

    void Texture::Bind(unsigned int slot) const     //window have 32 texture slot
    {
        GLCall(glActiveTexture(GL_TEXTURE0 + slot));
        GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));
    }

    void Texture::Unbind() const
    {
        GLCall(glBindTexture(GL_TEXTURE_2D, 0));
    }
}