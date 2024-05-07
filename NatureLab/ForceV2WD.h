#pragma once

namespace NatureLab {
    class ForceV2WD : public IWindow {
    public:
        inline ForceV2WD() = default;

        inline void init() override {

        }

        inline void show() override {
            this->begin("Description");
            {
                ImGui::Text("Modelar gravedad y fricción");
            }
            this->end();
        }
    };
}