#pragma once

namespace NatureLab {
    class VectorV1Window : public IWindow {
    public:
        inline VectorV1Window(){
            this->init();
        }

        inline void init() override {
            this->_nature = (VectorV1Nature*&)NatureController::Instance()->getNature(0);
        }

        inline void show() override {

            this->begin("Variables");
            {   
                //ImGui::Text("Variables");

                if (ImGui::SliderFloat("Velocity X", &this->_nature->_velocityX, 0, 1000))
                {
                    if (_nature->_velocity.x > 0) _nature->_velocity.x = _nature->_velocityX;
                    else _nature->_velocity.x = _nature->_velocityX * -1;
                }

                if (ImGui::SliderFloat("Velocity Y", &this->_nature->_velocityY, 0, 1000))
                {
                    if (_nature->_velocity.y > 0) _nature->_velocity.y = _nature->_velocityY;
                    else _nature->_velocity.y = _nature->_velocityY * -1;
                }
            }
            this->end();
        }

    private:

        VectorV1Nature* _nature;


    };
}