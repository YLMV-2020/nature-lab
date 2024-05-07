#pragma once

namespace NatureLab {
    class ForceV2Window : public IWindow {
    public:
        inline ForceV2Window() {
            this->init();
        }

        inline void init() override {
            this->_nature = (ForceV2Nature*&)NatureController::Instance()->getNature(5);
        }

        inline void show() override {

            this->begin("Variables");
            {

            }
            this->end();
        }

    private:

        ForceV2Nature* _nature;


    };
}