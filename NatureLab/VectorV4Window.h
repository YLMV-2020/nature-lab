#pragma once

namespace NatureLab {
    class VectorV4Window : public IWindow, public IMouseEventWindow {
    public:
        inline VectorV4Window() {
            this->init();
        }

        inline void init() override {
            this->_nature = (VectorV4Nature*&)NatureController::Instance()->getNature(3);
        }

        inline void show() override {

            IWindow::show();
            IMouseEventWindow::show();

            this->begin("Variables");
            {
                ImGui::Text("Velocity limit");
                ImGui::DragFloat("1", &_nature->_limitVelocity, 0.01f, 0, 1000.0f);

                _nature->setMouse(_mouse.x, _mouse.y);
            }
            this->end();
        }

    private:

        VectorV4Nature* _nature;
    };
}