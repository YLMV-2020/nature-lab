#pragma once

namespace NatureLab {
    class VectorV1WD : public IWindow {
    public:
        inline VectorV1WD() = default;

        inline void init() override {

        }

        inline void show() override {
            this->begin("Description");
            {
                ImGui::Text("Suma de Vectores");
            }
            this->end();
        }
    };
}