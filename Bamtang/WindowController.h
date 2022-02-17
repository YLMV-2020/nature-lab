#include "IWindow.h"
#include "IMouseEventWindow.h"

#include "SettingWindow.h"

#include "VectorV1Window.h"
#include "VectorV2Window.h"
#include "VectorV3Window.h"

#include "VectorV1WD.h"
#include "VectorV2WD.h"
#include "VectorV3WD.h"

namespace NatureLab
{
    class WindowController
    {

    public:

        static WindowController* Instance() {
            static WindowController instance;
            return &instance;
        }

        inline WindowController()
        {
            this->addWindow(new VectorV1Window(), new VectorV1WD());
            this->addWindow(new VectorV2Window(), new VectorV2WD());
            this->addWindow(new VectorV3Window(), new VectorV3WD());
        }

        inline void update()
        {
        }

        inline int newFrame()
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
            return dockSpace();
        }

        inline void render(const GLuint& texture, int indexScene)
        {
            this->show(texture);
            this->showWindows(indexScene);

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

    private:

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

            ImGui::End();
        }

        inline void addWindow(NatureLab::IWindow* control, NatureLab::IWindow* description)
        {
            this->addControl(control);
            this->addDescription(description);
        }

        inline void addControl(NatureLab::IWindow* control)
        {
            this->_controls.push_back(control);
        }

        inline void addDescription(NatureLab::IWindow* window)
        {
            this->_descriptions.push_back(window);
        }

        inline void showWindows()
        {
            for (NatureLab::IWindow*& inteface : _controls)
                inteface->show();
            for (NatureLab::IWindow*& inteface : _descriptions)
                inteface->show();
        }

        inline void showWindows(int indexScene)
        {
            _controls[indexScene]->show();
            _descriptions[indexScene]->show();
        }

        int dockSpace()
        {
            static int indexScene = 0;
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
                
                if (ImGui::BeginMenu("Vectors")) {

                    if (ImGui::MenuItem("V1", "Suma")) { indexScene = 0; }
                    if (ImGui::MenuItem("V2", "Resta")) { indexScene = 1; }
                    if (ImGui::MenuItem("V3", "Magnitud")) { indexScene = 2; }

                    ImGui::EndMenu();
                }

                if (ImGui::BeginMenu("Forces")) {

                    if (ImGui::MenuItem("V1", "Suma")) { indexScene = 0; }
                    if (ImGui::MenuItem("V2", "Resta")) { indexScene = 1; }
                    if (ImGui::MenuItem("V3", "Magnitud")) { indexScene = 2; }

                    ImGui::EndMenu();
                }


                ImGui::EndMenuBar();
            }

            ImGui::End();
            ImGui::PopStyleVar(3);

            return indexScene;
        }

        private:

            ImVec2 _displayRender;
            ImVec2 _display;

            std::vector<NatureLab::IWindow*> _controls;
            std::vector<NatureLab::IWindow*> _descriptions;

            ImGuiWindowFlags _window_flags;
    };

}