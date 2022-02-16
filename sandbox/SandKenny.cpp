#include "SandKenny.h"

#include "src/Debug.h"

namespace box
{
    SandKenny::SandKenny()
    {
        //glfwWindowHint(GLFW_DECORATED, false);
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
        glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);

        m_WinSize = {951, 951};

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

        m_Kenny = std::make_unique<kenny::Kenny>(m_Quard);
        m_VertexBuffer = std::make_unique<spat::VertexBuffer>(nullptr, m_Quard.GetSize());

        spat::VertexBufferLayout layout;
        
        layout.Push<float>(2);
        layout.Push<float>(4);
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
            * glm::translate(glm::mat4(1.0f), glm::vec3((float)m_WinSize.width / 2.0f, (float)m_WinSize.height / 2.0f, 0.0f))
            * glm::scale(glm::mat4(1.0f), glm::vec3(0.5, 0.5, 0.5));
        
        m_KennyPick = std::make_unique<kenny::KennyPicking>(m_WinSize.width, m_WinSize.height, m_Shader);
    }

    void SandKenny::OnUpdate()
    {
        double x,y;
        float pixel[4];
        GetDelta();

        int state = glfwGetMouseButton(m_Window, GLFW_MOUSE_BUTTON_LEFT);
        glfwGetCursorPos(m_Window, &x, &y);
        glReadPixels(x, m_WinSize.height - y, 1, 1, GL_RGBA, GL_FLOAT, &pixel);
        LOG(pixel[0] << ", " << pixel[1] << ", " << pixel[2] << ", " << pixel[3] << "/ " << x << ", " << y << "(" << state <<")");
        m_Quard.AddRotaion(static_cast<int>(kenny::Part::ArmRight_Open), -187.0f, -184.0f, 0.05f);
    }

    void SandKenny::OnRender()
    {   
        glClear(GL_COLOR_BUFFER_BIT);
        m_VertexBuffer -> Bind();
        glBufferSubData(GL_ARRAY_BUFFER, 0, m_Quard.GetSize(), m_Quard.GetVertex());

        m_Main_charactersTex -> Bind(0);
        m_Shader -> Bind();
        
        m_Shader -> SetUniformMat4f("u_MVP", m_MVP);
        m_KennyPick ->HitboxRender(m_IndexBuffer -> GetCount());
    }   
}