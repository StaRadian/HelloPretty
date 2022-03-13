#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "sandbox/SandKenny.h"
#include "sandbox/SandImgui.h"

#include "src/Debug.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

static inline void imgui_init(GLFWwindow* window)
{
    const char* glsl_version = "#version 460";
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

int main(void)
{
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  //opengl 메이저 버전 v4.6   //3.0
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);  //opengl 마이너 버전
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_DECORATED, false);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, true);
    // glfwWindowHint(GLFW_MOUSE_PASSTHROUGH, true);
    glfwWindowHint(GLFW_FLOATING, true);
    box::Sandbox *boxKenny = nullptr;
    boxKenny = new box::SandKenny;

    if (!boxKenny -> GetWindow())
    {
        delete boxKenny;
        glfwTerminate();
        return -1;
    }

    if (glewInit() != GLEW_OK)
    {
        delete boxKenny;
        glfwTerminate();
        return -1;
    }

    boxKenny -> RenderInit();

    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, false);
    box::Sandbox *boxImgui = nullptr;
    boxImgui = new box::SandImgui;

    if (!boxImgui -> GetWindow())
    {
        delete boxImgui;
        glfwTerminate();
        return -1;
    }
    
    if (glewInit() != GLEW_OK)
    {
        delete boxImgui;
        glfwTerminate();
        return -1;
    }

    boxImgui -> RenderInit();
    imgui_init(boxImgui -> GetWindow());

    LOG(glGetString(GL_VERSION));

    boxImgui -> GetDelta();
    boxKenny -> GetDelta();
    
    while (!glfwWindowShouldClose(boxKenny -> GetWindow()) && !glfwWindowShouldClose(boxImgui -> GetWindow()))  //loop
    {
        glfwPollEvents();
        glfwMakeContextCurrent(boxKenny -> GetWindow());

        boxKenny -> OnUpdate();

        boxKenny -> OnRender();

        glfwSwapBuffers(boxKenny -> GetWindow());
        /////////////////////////////////////////////////////////
        glfwMakeContextCurrent(boxImgui -> GetWindow());
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        boxImgui -> OnUpdate();

        boxImgui -> OnRender();

        boxImgui -> OnImGuiRender();
        boxKenny -> OnImGuiRender();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(boxImgui -> GetWindow());
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    
    delete boxKenny;
    delete boxImgui;
    glfwTerminate();
    return 0;
}