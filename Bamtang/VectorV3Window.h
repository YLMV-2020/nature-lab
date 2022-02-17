#pragma once

namespace NatureLab {
    class VectorV3Window : public IWindow {
    public:
        inline VectorV3Window() {
            this->init();
        }

        inline void init() override {
            this->_nature = (VectorV3Nature*&)NatureController::Instance()->getNature(2);
        }

        inline void show() override {

            this->begin("Variables");
            {
              
            }
            this->end();
        }

    private:

        VectorV3Nature* _nature;
    };
}