#include "IWindow.h"

#include "SettingWindow.h"

namespace NatureLab
{
    class WindowController
    {

    

    public:

        inline WindowController(GLFWwindow* window, std::string version)
        {
            this->start(window, version);
            this->addWindow(new SettingWindow());
        }

        inline void update()
        {
        }

        inline void newFrame()
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
            dockSpace();
        }

        inline void render(const GLuint& texture)
        {
            this->show(texture);
            this->showWindows();

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            ImGuiIO& io = ImGui::GetIO(); (void)io;

            if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
            {
                GLFWwindow* backup_current_context = glfwGetCurrentContext();
                ImGui::UpdatePlatformWindows();
                ImGui::RenderPlatformWindowsDefault();
                glfwMakeContextCurrent(backup_current_context);
            }
        }

    private:

        inline void start(GLFWwindow* window, std::string version)
        {

            std::string glsl_version = "#version " + version + "0";

            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO(); (void)io;
            io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
            io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
            io.ConfigFlags |= ImGuiWindowFlags_AlwaysHorizontalScrollbar;

            ImGui::StyleColorsDark();

            _window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground;

            ImGuiStyle& style = ImGui::GetStyle();
            if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
            {
                style.WindowRounding = 0.0f;
                style.Colors[ImGuiCol_WindowBg].w = 1.0f;
            }

            ImGui_ImplGlfw_InitForOpenGL(window, true);
            ImGui_ImplOpenGL3_Init(glsl_version.c_str());

        }

        inline void show(const GLuint& texture)
        {
            ImGui::Begin("Render", NULL);
            ImDrawList* drawList = ImGui::GetWindowDrawList();

            _displayRender = ImGui::GetWindowSize();
            _display = ImGui::GetCursorScreenPos();

            drawList->AddImage(
                (void*)texture, _display,
                ImVec2(_display.x + _displayRender.x - 10, _display.y + _displayRender.y - 30), ImVec2(0, 1), ImVec2(1, 0)
            );

            ImVec2 mousePosition = ImGui::GetMousePos();
            ImVec2 sceenPosition = ImGui::GetCursorScreenPos();
            ImVec2 scroll = ImVec2(ImGui::GetScrollX(), ImGui::GetScrollY());

            _mouse = ImVec2(mousePosition.x - sceenPosition.x - scroll.x, mousePosition.y - sceenPosition.y - scroll.y);

            ImGui::End();
        }

        inline void addWindow(NatureLab::IWindow* window)
        {
            this->_windows.push_back(window);
        }

        inline void showWindows()
        {
            for (NatureLab::IWindow*& inteface : _windows)
            {
                inteface->show();
            }
        }

        void dockSpace()
        {
            ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->Pos);
            ImGui::SetNextWindowSize(viewport->Size);
            ImGui::SetNextWindowViewport(viewport->ID);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

            ImGui::Begin("Dockspace", nullptr, _window_flags);
            {
                ImGuiID dockID = ImGui::GetID("Dockspace");
                ImGui::DockSpace(dockID, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);
            }

            if (ImGui::BeginMenuBar()) {
                if (ImGui::BeginMenu("File")) {
                    if (ImGui::MenuItem("\xef\x85\x9c", "Open Project", "Ctrl + O")) {}
                    if (ImGui::MenuItem("New", "Ctrl+N")) {}
                    if (ImGui::MenuItem("Open", "Ctrl+O")) {}
                    if (ImGui::MenuItem("Save", "Ctrl+S")) {}
                    if (ImGui::MenuItem("Save As..")) {}
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Editor")) {
                    if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
                    if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
                    ImGui::Separator();
                    if (ImGui::MenuItem("Cut", "CTRL+X")) {}
                    if (ImGui::MenuItem("Copy", "CTRL+C")) {}
                    if (ImGui::MenuItem("Paste", "CTRL+V")) {}
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Settings")) {
                    if (ImGui::MenuItem("Customize", "Ctrl+T")) {}
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Help")) {
                    if (ImGui::MenuItem("View Help", "Ctrl+H")) {}
                    if (ImGui::MenuItem("About Soft3D")) {}
                    ImGui::EndMenu();
                }

                ImGui::EndMenuBar();
            }

            ImGui::End();
            ImGui::PopStyleVar(3);
        }

        private:

            ImVec2 _displayRender;
            ImVec2 _display;
            ImVec2 _mouse;

            std::vector<NatureLab::IWindow*> _windows;

            ImGuiWindowFlags _window_flags;

    };

}