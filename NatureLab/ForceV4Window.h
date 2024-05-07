#pragma once

namespace NatureLab {
    class ForceV4Window : public IWindow {
    public:
        inline ForceV4Window() {
            this->init();
        }

        inline void init() override {
            this->_nature = (ForceV4Nature*&)NatureController::Instance()->getNature(7);
        }

        inline void show() override {

            this->begin("Variables");
            {

            }
            this->end();
        }

    private:

        ForceV4Nature* _nature;


    };
}