#pragma once
#include "../../interfaces/interface_nature.h"
#include "opengl/figures/gl_triangle_2d.h"

namespace nature_lab
{
    class vector_n1 final : public interface_nature
    {
    public:
        vector_n1()
        {
            this->start();
        }

        void start() override
        {
            interface_nature::start();
            triangle_ = new figure::gl_triangle_2d();

            this->position = glxm::vec2(100, 100);
            this->velocity = glxm::vec2(velocity_x, velocity_y);

            this->width_ = resource::screen_width;
            this->height_ = resource::screen_height;
        }

        void update() override
        {
            interface_nature::update();
            triangle_->update();
            // position = glxm::vec2(540,360);
            position = position + velocity;

            check_screen();
            triangle_->set_position(position);

            // float rot = 90.0f;
            const float rotation = 10.0f * glfwGetTime();
            triangle_->set_rotation(rotation);

            ImGui::Begin("vector n1");
            ImGui::Text("position: (%f,%f)", position.x, position.y);
            ImGui::Text("rotation: %f", rotation);
            ImGui::End();
        }

        void render() override
        {
            interface_nature::render();
            triangle_->render();
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

    private:
        int width_{}, height_{};
        figure::gl_triangle_2d* triangle_;
    };
}
