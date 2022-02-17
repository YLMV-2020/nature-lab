#pragma once

namespace NatureLab {
    class VectorV2WD : public IWindow {
    public:
        inline VectorV2WD() = default;

        inline void init() override {

        }

        inline void show() override {
            this->begin("Description");
            {
                ImGui::Text("Resta de Vectores");
            }
            this->end();
        }
    };
}