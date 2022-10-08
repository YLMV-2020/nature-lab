#pragma once
#include "../../interfaces/interface_gui.h"
#include "../../lab/vector/vector_n2.h"

namespace nature_lab
{
    class vector_u2 final : public interface_gui
    {
    public:
        vector_u2()
        {
        }

        void start() override
        {
            this->nature_ = reinterpret_cast<vector_n2*>(nature_controller::instance()->get_nature(laboratory::vector_n2));
        }

        void update() override
        {
        }

        void render() override
        {
            begin("data");
            {
                ImGui::Text("F");
            }
            end();
        }

    private:
        vector_n2* nature_ = nullptr;
    };
}
