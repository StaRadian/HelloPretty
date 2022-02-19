#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "sandbox/SandKenny.h"

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

    box::Sandbox *box = nullptr;
    box = new box::SandKenny;

    if (!box -> GetWindow())
    {
        delete box;
        glfwTerminate();
        return -1;
    }
    
    if (glewInit() != GLEW_OK)
    {
        delete box;
        glfwTerminate();
        return -1;
    }

    box -> RenderInit();

    imgui_init(box -> GetWindow());

    LOG(glGetString(GL_VERSION));

    box -> OnRender();
    
    while (!glfwWindowShouldClose(box -> GetWindow()))  //loop
    {
        glfwPollEvents();
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        box -> OnUpdate();

        box -> OnRender();

        box -> OnImGuiRender();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(box -> GetWindow());
    }    

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    
    delete box;
    glfwTerminate();
    return 0;
}