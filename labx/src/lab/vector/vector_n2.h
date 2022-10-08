#pragma once
#include "../../interfaces/interface_nature.h"
#include "../../opengl/shapes//gl_square_2d.h"
#include "opengl/shapes/gl_triangle_2d.h"
#include "opengl/shapes/gl_circle_2d.h"

namespace nature_lab
{
    class vector_n2 final : public interface_nature
    {
    public:
        vector_n2()
        {
            this->start();
        }

        void start() override
        {
            interface_nature::start();
            shape = new shape::gl_square_2d();

            this->position = glxm::vec2(100, 100);
            this->velocity = glxm::vec2(velocity_x, velocity_y);

            this->width_ = resource::screen_width;
            this->height_ = resource::screen_height;
        }

        void update(const float& delta_time) override
        {
            interface_nature::update(delta_time);
            shape->update();

            position = position + velocity;
            rotation = glfwGetTime() * 10.0f;
            
            // if (rotation > 360.0f) rotation = 0.0f;
            check_screen();

            shape->set_position(position);
            shape->set_rotation(rotation);
        }

        void render() override
        {
            interface_nature::render();
            shape->render();
        }

    private:
        void check_screen()
        {
            if (position.x > width_ || position.x < 0)
            {
                velocity.x = velocity.x * -1;
            }
            if (position.y > height_ || position.y < 0)
            {
                velocity.y = velocity.y * -1;
            }
        }

    public:
        glxm::vec2 position;
        glxm::vec2 velocity;

        float velocity_x = 2;
        float velocity_y = 5;

        float rotation = 0.0f;

    private:
        int width_{}, height_{};
    };
}
