#pragma once

//#include "IWindow.h"

namespace NatureLab {
    class SettingWindow : public IWindow {
    public:
        inline SettingWindow() = default;

        inline void init() override {

        }

        inline void show() override {
            this->begin("Settings");
            {
                const char* items[] = { "Classic", "Light", "Dark" };
                static int item_current = 2;
                if (ImGui::Combo("Editor Theme", &item_current, items, IM_ARRAYSIZE(items)))
                {
                    switch (item_current)
                    {
                    case 0:
                        ImGui::StyleColorsClassic();
                        break;
                    case 1:
                        ImGui::StyleColorsLight();
                        break;
                    case 2:
                        ImGui::StyleColorsDark();
                        break;
                    default:
                        break;
                    }
                }

                ImGui::Separator();
                const char* GPU = (const char*)glGetString(GL_RENDERER);
                ImGui::Text("OpenGL Version: %s", (const char*)glGetString(GL_VERSION));
                ImGui::Text("GLSL Version: %s", (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
            }
            this->end();
        }




    };
}