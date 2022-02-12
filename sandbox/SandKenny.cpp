#include "SandKenny.h"

#include "src/Debug.h"

#include "kenny/Kenny.h"

namespace box
{
    SandKenny::SandKenny()
    {
        //glfwWindowHint(GLFW_DECORATED, false);
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
        glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);

        m_WinSize = {451, 451};

        m_Window = glfwCreateWindow(m_WinSize.width, m_WinSize.height, "My Title", NULL, NULL);

        SetIcon("./res/textures/kenny.png");

        glfwMakeContextCurrent(GetWindow());
        
        glfwSwapInterval(1);    //vsync 활성화

        //glfwSetWindowPos(GetWindow(), 0, 0);;
    }

    SandKenny::~SandKenny()
    {

    }

    void SandKenny::RenderInit()
    {
        GLCall(glEnable(GL_BLEND));         //Blending
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));  //GL_SRC_ALPHA: 0, GL_ONE_MINUS_SRC_ALPHA: 1 - 0 = 1

        kenny::Kenny kenny(m_Quard, 0.5f);

        m_VertexBuffer = std::make_unique<spat::VertexBuffer>(nullptr, m_Quard.GetSize());

        spat::VertexBufferLayout layout;
        
        layout.Push<float>(2);
        layout.Push<float>(2);
        layout.Push<float>(1);
        
        m_VertexBuffer -> Bind();
        m_VAO -> AddBuffer(layout);

        m_IndexBuffer = std::make_unique<spat::IndexBuffer>(m_Quard.GetIndex(), m_Quard.GetIndexSize());

        m_Shader = std::make_unique<spat::Shader>("./res/shader/Kenny.vs", "./res/shader/Kenny.fs");

        m_Shader -> Bind();

        m_Main_charactersTex = std::make_unique<spat::Texture>("./res/textures/Kenny_sheet.png");
        
        int samplers[1] = { 0 };
        m_Shader -> SetUniform1iv("u_Texture", 1, samplers);

        m_MVP = glm::ortho(0.0f, (float)m_WinSize.width, 0.0f, (float)m_WinSize.height, -1.0f, 1.0f)
            * glm::translate(glm::mat4(1.0f), glm::vec3((float)m_WinSize.width / 2.0f, (float)m_WinSize.height / 2.0f, 0.0f));
    }

    void SandKenny::OnUpdate()
    {
        // glfwSetWindowPos(GetWindow(), 
        //     sin(j) * (m_MonitorSize.width - m_WinSize.width) / 2 + (m_MonitorSize.width - m_WinSize.width) / 2,
        //     cos(j) * (m_MonitorSize.height - m_WinSize.height) / 2 * (-1) + (m_MonitorSize.height - m_WinSize.height) / 2);
        //m_Quard.SetDegree(0, i);
    }

    void SandKenny::OnRender()
    {   
        m_VertexBuffer -> Bind();
        glBufferSubData(GL_ARRAY_BUFFER, 0, m_Quard.GetSize(), m_Quard.GetVertex());

        m_Main_charactersTex -> Bind(0);
        m_Shader -> Bind();
        
        m_Shader -> SetUniformMat4f("u_MVP", m_MVP);
        GLCall(glDrawElements(GL_TRIANGLES, m_IndexBuffer -> GetCount(), GL_UNSIGNED_INT, nullptr));
    }   
}