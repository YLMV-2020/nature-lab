#include "../interfaces/interface_gui.h"

namespace nature_lab
{
    class window_controller
    {
    public:
        static window_controller* instance()
        {
            static window_controller instance;
            return &instance;
        }

        window_controller()
        {
        }

        void update()
        {
        }

        void new_frame()
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
        }

        void render(const int index_scene) const
        {
            // this->show_windows(index_scene);

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

        void start(GLFWwindow* window, const std::string& version)
        {
            const std::string glsl_version = "#version " + version + "0";

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
         void add_window(interface_gui* control)
        {
            this->add_control(control);
        }

         void add_control(interface_gui* control)
        {
            this->controls_.push_back(control);
        }
        
        void show_windows()
        {
            for (interface_gui*& inteface : controls_)
                inteface->show();
        }

        void show_windows(const int index_scene) const
        {
            controls_[index_scene]->show();
        }


    private:
        ImVec2 display_render_;
        ImVec2 display_;

        std::vector<interface_gui*> controls_;

        ImGuiWindowFlags _window_flags{};
    };
}
