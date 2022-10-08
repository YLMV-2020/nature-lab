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

        void update(const float& delta_time) override
        {
            interface_controller::update(delta_time);
            // for (const auto& it : controls_)
            //     it.second->update();
            control_current->update();
            new_frame();
        }

        void render() override
        {
            interface_controller::render();
            // for (const auto& it : controls_)
            //     it.second->render();
            control_current->render();
            end_frame();
        }

        void load_gui() const
        {
            for (const auto& it : controls_)
                it.second->start();
        }

        interface_gui* get_control(laboratory name_control)
        {
            const auto it = controls_.find(name_control);
            if (it != controls_.end())
                return it->second;
            return nullptr;
        }

        void add_control(laboratory name_control, interface_gui* control)
        {
            controls_.insert(std::pair<laboratory, interface_gui*>(name_control, control));

        }

        void link_window(GLFWwindow* window_)
        {
            ImGui_ImplGlfw_InitForOpenGL(window_, true);
        }

        void bind_control(laboratory name_lab)
        {
            control_current = get_control(name_lab);
            control_current->start();
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

        std::map<laboratory, interface_gui*> controls_;
        interface_gui* control_current = nullptr;
        ImGuiWindowFlags _window_flags{};
    };
}
