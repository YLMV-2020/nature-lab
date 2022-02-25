#pragma once

namespace NatureLab {
    class ForceV3WD : public IWindow {
    public:
        inline ForceV3WD() = default;

        inline void init() override {

        }

        inline void show() override {
            this->begin("Description");
            {
                ImGui::Text("Resistencia del aire y de fluidos");
            }
            this->end();
        }
    };
}