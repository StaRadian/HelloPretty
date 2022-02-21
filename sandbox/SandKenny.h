#pragma once
#include "Sandbox.h"

#include "src/VertexArray.h"
#include "src/VertexBuffer.h"
#include "src/IndexBuffer.h"
#include "src/Shader.h"
#include "src/Texture.h"
#include "src/FrameBuffer.h"

#include "kenny/KennyControl.h"

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

        std::unique_ptr<kenny::KennyControl> m_Kenny;
        glm::mat4 m_MVP;

        double cursor_x;
        double cursor_y;
        int m_mouse_click;
        int m_state;
        int m_val;
        float m_x;
        float m_y;
        float m_height;
        float m_degree;
        // float m_degree1;
        // float m_degree2;
        float m_rotationspeed;
        float m_rotationspeed2;
        float m_distance;
        float m_compact;
    public:
        SandKenny();
        ~SandKenny();
        void RenderInit() override;
        void OnUpdate() override;
        void OnRender() override;
        void OnImGuiRender() override;
    };
}