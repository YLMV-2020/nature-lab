#pragma once

namespace NatureLab {
    class ForceV1WD : public IWindow {
    public:
        inline ForceV1WD() = default;

        inline void init() override {

        }

        inline void show() override {
            this->begin("Description");
            {
                ImGui::Text("Las leyes del movimiento de Newton");
            }
            this->end();
        }
    };
}