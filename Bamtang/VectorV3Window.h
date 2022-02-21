#pragma once

namespace NatureLab {
    class VectorV3Window : public IWindow, public IMouseEventWindow {
    public:
        inline VectorV3Window() {
            this->init();
        }

        inline void init() override {
            this->_nature = (VectorV3Nature*&)NatureController::Instance()->getNature(2);
        }

        inline void show() override {

            IWindow::show();
            IMouseEventWindow::show();

            this->begin("Variables");
            {
                if (ImGui::ColorEdit3("Color", _nature->_colorxyz)){
                    _nature->setColor(_nature->_colorxyz[0], _nature->_colorxyz[1], _nature->_colorxyz[2]);
                }

                _nature->setMouse(_mouse.x, _mouse.y);
            }
            this->end();
        }

    private:

        VectorV3Nature* _nature;
    };
}