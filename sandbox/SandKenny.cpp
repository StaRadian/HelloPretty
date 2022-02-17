#include "SandKenny.h"

#include "src/Debug.h"

namespace box
{
    SandKenny::SandKenny()
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  //opengl 메이저 버전 v4.6   //3.0
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);  //opengl 마이너 버전
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //glfwWindowHint(GLFW_DECORATED, false);
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
        glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);

        m_WinSize = {471, 471};

        m_Window = glfwCreateWindow(m_WinSize.width, m_WinSize.height, "My Title", NULL, NULL);

        SetIcon("./res/textures/kenny.png");

        glfwMakeContextCurrent(GetWindow());
        
        glfwSwapInterval(1);    //vsync 활성화
    }

    SandKenny::~SandKenny()
    {

    }

    void SandKenny::RenderInit()
    {
        GLCall(glEnable(GL_BLEND));         //Blending
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));  //GL_SRC_ALPHA: 0, GL_ONE_MINUS_SRC_ALPHA: 1 - 0 = 1

        m_Kenny = std::make_unique<kenny::Kenny>(m_Quard);
        m_VertexBuffer = std::make_unique<spat::VertexBuffer>(nullptr, m_Quard.GetSize());

        spat::VertexBufferLayout layout;
        
        layout.Push<float>(2);
        layout.Push<float>(4);
        layout.Push<float>(2);
        layout.Push<float>(1);

        m_VAO = std::make_unique<spat::VertexArray>();
        m_VertexBuffer -> Bind();
        m_VAO -> AddBuffer(layout);

        m_IndexBuffer = std::make_unique<spat::IndexBuffer>(m_Quard.GetIndex(), m_Quard.GetIndexSize());

        m_Shader = std::make_unique<spat::Shader>("./res/shader/Kenny.vs", "./res/shader/Kenny.fs");

        m_Shader -> Bind();

        m_Main_charactersTex = std::make_unique<spat::Texture>("./res/textures/Kenny_sheet.png");
        
        int samplers[1] = { 0 };
        m_Shader -> SetUniform1iv("u_Texture", 1, samplers);

        m_MVP = glm::ortho(0.0f, (float)m_WinSize.width, 0.0f, (float)m_WinSize.height, -1.0f, 1.0f)
            * glm::translate(glm::mat4(1.0f), glm::vec3((float)m_WinSize.width / 2.0f, (float)m_WinSize.height / 2.0f, 0.0f))
            * glm::scale(glm::mat4(1.0f), glm::vec3(0.5, 0.5, 0.5));
        
        m_FrameBuffer = std::make_unique<spat::FrameBuffer>();
        m_FrameBuffer -> TextureAttach(m_WinSize.width, m_WinSize.height);
        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 0.0f));
        glfwSetWindowPos(GetWindow(), 0, 0);
        x_p = 0;
        y_p = 0;
        a = 0;
        b = 0;
        glfwGetCursorPos(m_Window, &x_pos, &y_pos);
    }

    void SandKenny::OnUpdate()
    {
        double x,y;
        float pixel[4];
        GetDelta();

        int state = glfwGetMouseButton(m_Window, GLFW_MOUSE_BUTTON_LEFT);
        if(state == 1)
        {
            int val;
            glfwGetCursorPos(m_Window, &x, &y);
            glReadPixels(x, m_WinSize.height - y, 1, 1, GL_RGBA, GL_FLOAT, &pixel);
            val = m_Kenny -> GetColorName(pixel[0]);
            if(val != -1)
            {
                if(a == 0)
                {
                    x_pos = x;
                    y_pos = y;
                    b = 1;
                }
            }
            else if(a == 0)
            {
                b = 0;
            }
            if(b != 0)
            {
                x_p +=  x - x_pos;
                y_p +=  y - y_pos;
            }
            glfwSetWindowPos(GetWindow(), x_p, y_p);
        }
        a = state;
        
        m_Quard.AddRotaion(static_cast<int>(kenny::Part::ArmRight_Open), -187.0f, -184.0f, 0.05f);
    }

    void SandKenny::OnRender()
    {   
        m_VertexBuffer -> Bind();
        glBufferSubData(GL_ARRAY_BUFFER, 0, m_Quard.GetSize(), m_Quard.GetVertex());

        m_Main_charactersTex -> Bind(0);
        m_Shader -> Bind();
        
        m_Shader -> SetUniformMat4f("u_MVP", m_MVP);
        glClear(GL_COLOR_BUFFER_BIT);
        m_Shader -> SetUniform1i("u_ViewMode", 1);
        GLCall(glDrawElements(GL_TRIANGLES,  m_IndexBuffer -> GetCount(), GL_UNSIGNED_INT, nullptr));
        m_FrameBuffer -> Unbind();

        glClear(GL_COLOR_BUFFER_BIT);
        m_Shader -> SetUniform1i("u_ViewMode", 0);
        GLCall(glDrawElements(GL_TRIANGLES,  m_IndexBuffer -> GetCount(), GL_UNSIGNED_INT, nullptr));
        m_FrameBuffer -> Bind();
    }   
}