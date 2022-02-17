#pragma once

namespace NatureLab {
    class VectorV3WD : public IWindow {
    public:
        inline VectorV3WD() = default;

        inline void init() override {

        }

        inline void show() override {
            this->begin("Description");
            {
                ImGui::Text("Magnitud de Vectores");
            }
            this->end();
        }
    };
}