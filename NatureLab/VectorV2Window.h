#pragma once

namespace NatureLab {
    class VectorV2Window : public IWindow, public IMouseEventWindow {
    public:
        inline VectorV2Window() {
            this->init();
        }

        inline void init() override {
            this->_nature = (VectorV2Nature*&)NatureController::Instance()->getNature(1);
        }

        inline void show() override {

            IWindow::show();
            IMouseEventWindow::show();

            this->begin("Variables");
            {
                //ImGui::Text("Variables");

                if (ImGui::ColorEdit3("Color", _nature->_colorxyz))
                {
                    _nature->setColor(_nature->_colorxyz[0], _nature->_colorxyz[1], _nature->_colorxyz[2]);
                }

                _nature->setMouse(_mouse.x, _mouse.y);               
            }
            this->end();
        }

    private:

        VectorV2Nature* _nature;
    };
}