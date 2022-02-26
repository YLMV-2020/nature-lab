#pragma once

namespace NatureLab {
    class ForceV4WD : public IWindow {
    public:
        inline ForceV4WD() = default;

        inline void init() override {

        }

        inline void show() override {
            this->begin("Description");
            {
                ImGui::Text("Atracción gravitacional");
            }
            this->end();
        }
    };
}