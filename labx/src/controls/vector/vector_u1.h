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
            }
            end();
        }

    private:
        vector_n1* nature_ = nullptr;
    };
}
