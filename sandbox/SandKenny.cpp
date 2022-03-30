#include "SandKenny.h"

#include "src/Debug.h"
#include "imgui/imgui.h"

namespace box
{
    SandKenny::SandKenny()
    {
        m_WinSize = {m_MonitorSize.width - 2, m_MonitorSize.height - 2};

        m_Window = glfwCreateWindow(m_WinSize.width, m_WinSize.height, "HelloPretty", NULL, NULL);

        SetIcon("./res/textures/kenny.png");

        glfwSwapInterval(1);    //vsync 활성화
        glfwMakeContextCurrent(GetWindow());
    }

    SandKenny::~SandKenny()
    {

    }

    void SandKenny::RenderInit()
    {
        GLCall(glEnable(GL_BLEND));         //Blending
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));  //GL_SRC_ALPHA: 0, GL_ONE_MINUS_SRC_ALPHA: 1 - 0 = 1

        m_Kenny = std::make_unique<kenny::KennyControl>(&m_Quard);
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

        m_Main_charactersTex = std::make_unique<spat::Texture>("./res/textures/Kenny_sheet_v2.png");
        
        int samplers[1] = { 0 };
        m_Shader -> SetUniform1iv("u_Texture", 1, samplers);
        
        m_FrameBuffer = std::make_unique<spat::FrameBuffer>();
        m_FrameBuffer -> TextureAttach(m_WinSize.width, m_WinSize.height);

        m_KennySize = 0.2f;
        m_kennyMovedata = {
            0.0f,                       //main
            0.0f, 0.0f,                 //Pant
            0.0f, 0.0f,                 //Arm
            1.9f, 0.0f,                 //Neck
            {0.0f, 0.0f}, {0.0f, 0.0f}, //HandPos
            0.0f, 0.0f,                 //HandDegree
            {                           //Eyeball
                {0.0f, 0.0f},
                800.0f,
                0
            }
        };
        m_drawpoint = 0;

        GetDelta();
    }

    void SandKenny::OnUpdate()
    {
        GetDelta();
        m_FrameBuffer -> Bind();
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(m_kennyMovedata.EyesData.mode == 1)
        {
            m_kennyMovedata.EyesData.target.x = (float)cursor_x / m_KennySize;
            m_kennyMovedata.EyesData.target.y = (float)(m_WinSize.height - cursor_y) / m_KennySize;
        }

        switch (m_drawpoint)
        {
        case 0:
            m_Kenny -> PantFrontMain(m_kennyMovedata);
            break;

        case 1:
            m_Kenny -> BadyFrontMain(m_kennyMovedata);
            break;
        
        default:
            break;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        m_MVP = glm::ortho(0.0f, (float)m_WinSize.width, 0.0f, (float)m_WinSize.height, -1.0f, 1.0f)
            * glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, 0.0))
            * glm::scale(glm::mat4(1.0f), glm::vec3(m_KennySize, m_KennySize, 0.0));
    }

    void SandKenny::OnRender()
    {   
        glBufferSubData(GL_ARRAY_BUFFER, 0, m_Quard.GetSize(), m_Quard.GetVertex());
        m_VertexBuffer -> Bind();
        m_Main_charactersTex -> Bind(0);

        m_Shader -> Bind();
        
        m_Shader -> SetUniformMat4f("u_MVP", m_MVP);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_Shader -> SetUniform1i("u_ViewMode", 1);
        GLCall(glDrawElements(GL_TRIANGLES,  m_IndexBuffer -> GetCount(), GL_UNSIGNED_INT, nullptr));
        MouseCheck();
        m_FrameBuffer -> Unbind();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 0.0f));
        m_Shader -> SetUniform1i("u_ViewMode", 0);
        GLCall(glDrawElements(GL_TRIANGLES,  m_IndexBuffer -> GetCount(), GL_UNSIGNED_INT, nullptr));
    }

    void SandKenny::OnImGuiRender()
    {
        ImGui::Begin("Kenny");

        ImGui::SliderFloat("PositionX", &(m_Kenny -> m_point.x), 0, m_WinSize.width / m_KennySize);
        ImGui::SliderFloat("PositionY", &(m_Kenny -> m_point.y), 0, m_WinSize.height / m_KennySize);
        ImGui::SliderFloat("Size", &m_KennySize, 0.0f, 1.0f);
        ImGui::SliderFloat("degree", &m_kennyMovedata.degree, PI * (-1), PI);
        ImGui::SliderFloat("NeckBow", &m_kennyMovedata.NeckBow, PI / 3.0f, PI);
        ImGui::SliderFloat("NeckRL", &m_kennyMovedata.NeckRL, PI / 8.0f * (-1), PI / 8.0f);
        ImGui::SliderFloat("PantHeight", &m_kennyMovedata.PantHeight, -25.0, 25.0);
        ImGui::SliderFloat("PantDegree", &m_kennyMovedata.PantDegree, PI / 20.0f * (-1), PI / 20.0f);
        ImGui::SliderFloat("LeftArmAdd", &m_kennyMovedata.LeftArmAdd, -1.5f, 1.4f);
        ImGui::SliderFloat("RightArmAdd", &m_kennyMovedata.RightArmAdd, -1.4f, 1.5f);
        ImGui::SliderInt("DrawPoint", &m_drawpoint, 0, 1);
        ImGui::Text("x: %.1f, y: %.1f, degree: %.2f, click: %d, state: %d", cursor_x, cursor_y, m_kennyMovedata.degree, m_mouse_click, m_state);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        
        ImGui::End();

        ImGui::Begin("State");
        if (ImGui::Button("Left Open  "))
        {
            m_Kenny -> ViewArm(static_cast<int>(kenny::Part::ArmLeft_Open));
        }
        ImGui::SameLine();
        if (ImGui::Button("Right Open "))
        {
            m_Kenny -> ViewArm(static_cast<int>(kenny::Part::ArmRight_Open));
        }
        if (ImGui::Button("Left Bend  "))
        {
            m_Kenny -> ViewArm(static_cast<int>(kenny::Part::ArmLeft_Bend));
        }
        ImGui::SameLine();
        if (ImGui::Button("Right Bend "))
        {
            m_Kenny -> ViewArm(static_cast<int>(kenny::Part::ArmRight_Bend));
        }
        if (ImGui::Button("Left Basic "))
        {
            m_Kenny -> ViewArm(static_cast<int>(kenny::Part::ArmFrontLeft_Basic));
        }
        ImGui::SameLine();
        if (ImGui::Button("Right Basic"))
        {
            m_Kenny -> ViewArm(static_cast<int>(kenny::Part::ArmFrontRight_Basic));
        }

        if (ImGui::Button("Left Paper "))
        {
            m_Kenny -> ViewHand(static_cast<int>(kenny::Part::HandLeft_Paper));
        }
        ImGui::SameLine();
        if (ImGui::Button("Right Paper"))
        {
            m_Kenny -> ViewHand(static_cast<int>(kenny::Part::HandRight_Paper));
        }
        if (ImGui::Button("Left Rock  "))
        {
            m_Kenny -> ViewHand(static_cast<int>(kenny::Part::HandLeft_Rock));
        }
        ImGui::SameLine();
        if (ImGui::Button("Right Rock "))
        {
            m_Kenny -> ViewHand(static_cast<int>(kenny::Part::HandRight_Rock));
        }
        if (ImGui::Button("Eyebrow    "))
        {
            m_Kenny -> ViewEyebrow(true);
        }
        ImGui::SameLine();
        if (ImGui::Button("Not Eyebrow"))
        {
            m_Kenny -> ViewEyebrow(false);
        }
        if (ImGui::Button("Left Eye   "))
        {
            if(m_Kenny -> m_CurrentStyle.eye.left == 0)
                m_Kenny -> ViewEyeL(true);
            else
                m_Kenny -> ViewEyeL(false);
        }
        ImGui::SameLine();
        if (ImGui::Button("Right Eye  "))
        {
            if(m_Kenny -> m_CurrentStyle.eye.right == 0)
                m_Kenny -> ViewEyeR(true);
            else
                m_Kenny -> ViewEyeR(false);
        }
        if (ImGui::Button("Targeting  "))
        {
            m_kennyMovedata.EyesData.mode = 1;
        }
        ImGui::SameLine();
        if (ImGui::Button("Untargeting"))
        {
            m_kennyMovedata.EyesData.mode = 0;
        }
        ImGui::End();
    }

    void SandKenny::MouseCheck()
    {
        float pixel[4];
        m_mouse_click = glfwGetMouseButton(m_Window, GLFW_MOUSE_BUTTON_LEFT);
        glfwGetCursorPos(m_Window, &cursor_x, &cursor_y);
        glReadPixels(cursor_x, (m_WinSize.height - cursor_y), 1, 1, GL_RGBA, GL_FLOAT, &pixel);
        m_state = m_Kenny -> GetColorName(pixel[0]);
        if(m_state != -1)
        {
            glfwSetWindowAttrib(GetWindow(), GLFW_MOUSE_PASSTHROUGH, false);
        }
        else
        {
            glfwSetWindowAttrib(GetWindow(), GLFW_MOUSE_PASSTHROUGH, true);
        }
    }
}