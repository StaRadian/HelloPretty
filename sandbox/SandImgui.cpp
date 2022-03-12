#include "SandImgui.h"

namespace box
{
    SandImgui::SandImgui()
    {
        m_WinSize = {600, 600};

        m_Window = glfwCreateWindow(m_WinSize.width, m_WinSize.height, "HelloPretty", NULL, NULL);

        glfwMakeContextCurrent(GetWindow());
    }

    SandImgui::~SandImgui()
    {

    }

    void SandImgui::RenderInit()
    {
        
    }

    void SandImgui::OnUpdate()
    {
    
    }

    void SandImgui::OnRender()
    {   
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void SandImgui::OnImGuiRender()
    {

    }
}