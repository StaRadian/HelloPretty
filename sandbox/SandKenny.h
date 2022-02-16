#pragma once
#include "Sandbox.h"

#include "src/VertexArray.h"
#include "src/VertexBuffer.h"
#include "src/IndexBuffer.h"
#include "src/Shader.h"
#include "src/Texture.h"
#include "src/TexQuard2D.h"

#include "kenny/Kenny.h"
#include "kenny/KennyPicking.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <memory>

namespace box
{
    class SandKenny : public Sandbox
    {   
    private:
        std::unique_ptr<spat::VertexArray> m_VAO;
        std::unique_ptr<spat::VertexBuffer> m_VertexBuffer;
        std::unique_ptr<spat::IndexBuffer> m_IndexBuffer;
        std::unique_ptr<spat::Shader> m_Shader;
        std::unique_ptr<spat::Texture> m_Main_charactersTex;
        std::unique_ptr<spat::FrameBuffer> m_FrameBuffer;
        spat::TexQuard2D m_Quard;
        std::unique_ptr<kenny::Kenny> m_Kenny;
        glm::mat4 m_MVP;

        double x_b,y_b;
        int x_pos, y_pos, x_p, y_p;
    public:
        SandKenny();
        ~SandKenny();
        void RenderInit() override;
        void OnUpdate() override;
        void OnRender() override;
    };
}