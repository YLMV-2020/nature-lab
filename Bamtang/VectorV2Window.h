#pragma once

namespace NatureLab {
    class VectorV2Window : public IWindow {
    public:
        inline VectorV2Window() {
            this->init();
        }

        inline void init() override {
            this->_nature = (VectorV2Nature*&)NatureController::Instance()->getNature(1);
        }

        inline void show() override {

            this->begin("Vector V2");
            {
                ImGui::Text("Variables");

                
            }
            this->end();
        }

    private:

        VectorV2Nature* _nature;


    };
}