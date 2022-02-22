#pragma once

namespace NatureLab {
    class VectorV4WD : public IWindow {
    public:
        inline VectorV4WD() = default;

        inline void init() override {

        }

        inline void show() override {
            this->begin("Description");
            {
                ImGui::Text("Movimiento interactivo de vectores");
            }
            this->end();
        }
    };
}