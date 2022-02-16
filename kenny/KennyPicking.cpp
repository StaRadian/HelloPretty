#include "KennyPicking.h"
#include <GL/glew.h>

#include "src/Debug.h"

namespace kenny
{
    KennyPicking::KennyPicking(int width, int height, spat::Shader &shader)
        :m_Shader(shader)
    {
        fbo.TextureAttach(width, height);
    }

    KennyPicking::~KennyPicking()
    {

    }

    void KennyPicking::HitboxRender(unsigned int indexSize)
    {   
        glClear(GL_COLOR_BUFFER_BIT);
        m_Shader.SetUniform1i("u_ViewMode", 1);
        GLCall(glDrawElements(GL_TRIANGLES, indexSize, GL_UNSIGNED_INT, nullptr));
        fbo.Unbind();

        glClear(GL_COLOR_BUFFER_BIT);
        m_Shader.SetUniform1i("u_ViewMode", 0);
        GLCall(glDrawElements(GL_TRIANGLES, indexSize, GL_UNSIGNED_INT, nullptr));
        fbo.Bind();
    }
}