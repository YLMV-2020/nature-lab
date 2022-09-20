#include "../interfaces/IWindow.h"
#include "../interfaces/IMouseEventWindow.h"

#include "SettingWindow.h"


namespace NatureLab
{
    class WindowController
    {
    public:
        static WindowController* Instance()
        {
            static WindowController instance;
            return &instance;
        }

        inline WindowController()
        {
        }

        inline void update()
        {
        }

        inline void newFrame()
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
        }

         void render(const int indexScene)
        {
            // this->showWindows(indexScene);

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            ImGuiIO& io = ImGui::GetIO();
            (void)io;

            if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
            {
                GLFWwindow* backup_current_context = glfwGetCurrentContext();
                ImGui::UpdatePlatformWindows();
                ImGui::RenderPlatformWindowsDefault();
                glfwMakeContextCurrent(backup_current_context);
            }
        }

        inline void start(GLFWwindow* window, std::string version)
        {
            std::string glsl_version = "#version " + version + "0";

            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO();
            (void)io;
            io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
            io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
            io.ConfigFlags |= ImGuiWindowFlags_AlwaysHorizontalScrollbar;

            ImGui::StyleColorsDark();

            _window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar |
                ImGuiWindowFlags_NoCollapse |
                ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus |
                ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground;

            ImGuiStyle& style = ImGui::GetStyle();
            if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
            {
                style.WindowRounding = 0.0f;
                style.Colors[ImGuiCol_WindowBg].w = 1.0f;
            }

            ImGui_ImplGlfw_InitForOpenGL(window, true);
            ImGui_ImplOpenGL3_Init(glsl_version.c_str());
        }

    private:
        inline void addWindow(NatureLab::IWindow* control)
        {
            this->addControl(control);
        }

        inline void addControl(NatureLab::IWindow* control)
        {
            this->_controls.push_back(control);
        }


        inline void showWindows()
        {
            for (NatureLab::IWindow*& inteface : _controls)
                inteface->show();
        }

        inline void showWindows(int indexScene)
        {
            _controls[indexScene]->show();
        }


    private:
        ImVec2 _displayRender;
        ImVec2 _display;

        std::vector<NatureLab::IWindow*> _controls;

        ImGuiWindowFlags _window_flags;
    };
}
