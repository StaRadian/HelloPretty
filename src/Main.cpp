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

    box::Sandbox *boxKenny = nullptr;
    boxKenny = new box::SandKenny;
    box::Sandbox *boxImgui = nullptr;
    boxImgui = new box::SandImgui;

    if ((!boxKenny -> GetWindow()) || (!boxImgui -> GetWindow()))
    {
        delete boxKenny;
        delete boxImgui;
        glfwTerminate();
        return -1;
    }
    
    if (glewInit() != GLEW_OK)
    {
        delete boxKenny;
        delete boxImgui;
        glfwTerminate();
        return -1;
    }

    boxKenny -> RenderInit();
    boxImgui -> RenderInit();

    imgui_init(boxKenny -> GetWindow());

    LOG(glGetString(GL_VERSION));

    boxKenny -> OnRender();
    boxImgui -> OnRender();
    
    while (!glfwWindowShouldClose(boxKenny -> GetWindow()) && !glfwWindowShouldClose(boxImgui -> GetWindow()))  //loop
    {
        glfwPollEvents();
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        boxKenny -> OnUpdate();

        boxKenny -> OnRender();

        boxKenny -> OnImGuiRender();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(boxKenny -> GetWindow());
        /////////////////////////////////////////////////////////
        // ImGui_ImplOpenGL3_NewFrame();
        // ImGui_ImplGlfw_NewFrame();
        // ImGui::NewFrame();

        boxImgui -> OnUpdate();

        boxImgui -> OnRender();

        boxImgui -> OnImGuiRender();

        // ImGui::Render();
        // ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

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