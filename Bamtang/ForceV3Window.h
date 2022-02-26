#pragma once

namespace NatureLab {
    class ForceV3Window : public IWindow {
    public:
        inline ForceV3Window() {
            this->init();
        }

        inline void init() override {
            this->_nature = (ForceV3Nature*&)NatureController::Instance()->getNature(6);
        }

        inline void show() override {

            this->begin("Variables");
            {
                if (ImGui::Button("Reset")) {
                    _nature->start();
                }
            }
            this->end();
        }

    private:

        ForceV3Nature* _nature;


    };
}