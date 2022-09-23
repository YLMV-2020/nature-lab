#include "../interfaces/interface_gui.h"

namespace nature_lab
{
    class gui_controller final : public interface_controller
    {
    public:
        static gui_controller* instance()
        {
            static gui_controller instance;
            return &instance;
        }

        gui_controller()
        {
        }

        void start() override
        {
            interface_controller::start();
            init();
        }

        void update() override
        {
            interface_controller::update();
            for (interface_gui*& inteface : controls_)
                inteface->update();
            new_frame();
        }

        void render() override
        {
            interface_controller::render();
            for (interface_gui*& inteface : controls_)
                inteface->render();
            end_frame();
        }

        void load_gui()
        {
            for (interface_gui*& inteface : controls_)
                inteface->start();
        }

        void add_control(interface_gui* control)
        {
            this->controls_.push_back(control);
        }

        void set_window(GLFWwindow* window_)
        {
            ImGui_ImplGlfw_InitForOpenGL(window_, true);
        }

    private:
        void init()
        {
            const std::string glsl_version = "#version 330";

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

            ImGui_ImplOpenGL3_Init(glsl_version.c_str());
        }

        void new_frame()
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
        }

        void end_frame() const
        {
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

        std::vector<interface_gui*> controls_;
        ImGuiWindowFlags _window_flags{};
    };
}
