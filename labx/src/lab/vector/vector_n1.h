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

            // this->_position = Math::Vector(100, 100);
            // this->_velocity = Math::Vector(velocity_x, velocity_y);

            // this->width_ = scene::widht;
            // this->height_ = scene::height;
        }

        void update() override
        {
            interface_nature::update();

            // _position = _position + _velocity;
            //
            // if ((_position.x > width_) || (_position.x < 0)) {               
            //     _velocity.x = _velocity.x * -1;
            // }
            // if ((_position.y > height_) || (_position.y < 0)) {
            //     _velocity.y = _velocity.y * -1;
            // }
        }

        void render() override
        {
            interface_nature::render();
            figure::render_triangle();
        }

    private:
        int width_{}, height_{};

    public:
        // Math::Vector _position;
        // Math::Vector _velocity;

        float velocity_x = 2;
        float velocity_y = 5;
    };
}
