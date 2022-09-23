#pragma once
#include "../../interfaces/interface_gui.h"
#include "../../lab/vector/vector_n1.h"

namespace nature_lab
{
    class vector_u1 final : public interface_gui
    {
    public:
        vector_u1()
        {
        }

        void start() override
        {
            this->nature_ = reinterpret_cast<vector_n1*&>(nature_controller::instance()->get_nature(0));
        }

        void update() override
        {
        }

        void render() override
        {
            begin("data");
            {
                ImGui::Text("position: (%f,%f)", nature_->position.x, nature_->position.y);
                ImGui::Text("rotation: %f", nature_->rotation);
                
                if (ImGui::SliderFloat("velocity x", &this->nature_->velocity_x, 0, 20))
                {
                    if (nature_->velocity.x > 0) nature_->velocity.x = nature_->velocity_x;
                    else nature_->velocity.x = nature_->velocity_x * -1;
                }

                if (ImGui::SliderFloat("velocity y", &this->nature_->velocity_y, 0, 20))
                {
                    if (nature_->velocity.y > 0) nature_->velocity.y = nature_->velocity_y;
                    else nature_->velocity.y = nature_->velocity_y * -1;
                }
            }
            end();
        }

    private:
        vector_n1* nature_ = nullptr;
    };
}
