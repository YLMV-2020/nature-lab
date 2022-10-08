#pragma once
#include <GLFW/glfw3.h>

namespace nature_lab
{
    class time
    {
    public:
        static time* instance()
        {
            static time instance;
            return &instance;
        }

        void update()
        {
            const float current_frame = glfwGetTime();
            delta_time = current_frame - last_frame;
            last_frame = current_frame;
            seconds = current_frame - start_frame;
        }

        inline const float& get_delta_time() const
        {
            return *&delta_time;
        }

    private:
        float delta_time = 0.0f;
        float last_frame = 0.0f;
        float seconds = 0.0f;
        float start_frame = glfwGetTime();
    };
}
