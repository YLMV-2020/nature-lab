#pragma once

namespace NatureLab {
    class ForceV1Window : public IWindow {
    public:
        inline ForceV1Window() {
            this->init();
        }

        inline void init() override {
            this->_nature = (ForceV1Nature*&)NatureController::Instance()->getNature(0);
        }

        inline void show() override {

            this->begin("Variables");
            {
               
            }
            this->end();
        }

    private:

        ForceV1Nature* _nature;


    };
}