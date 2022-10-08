#pragma once
#include <gl/glew.h>
#include "../../interfaces/interface_shape.h"

namespace shape
{
    class gl_square_2d final : public interface_shape
    {
    public:
        gl_square_2d()
        {
            start();
        }

        void start() override
        {
            interface_shape::start();

            constexpr float vertices[] = {
                50.5f, 50.5f, 0.0f, // top right
                50.5f, -50.5f, 0.0f, // bottom right
                -50.5f, -50.5f, 0.0f, // bottom left
                -50.5f, 50.5f, 0.0f // top left 
            };
            const unsigned int indices[] = {
                // note that we start from 0!
                0, 1, 3, // first Triangle
                1, 2, 3 // second Triangle
            };
            unsigned int vbo, ebo;
            glGenVertexArrays(1, &vao_);
            glGenBuffers(1, &vbo);
            glGenBuffers(1, &ebo);

            glBindVertexArray(vao_);

            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), static_cast<void*>(0));
            glEnableVertexAttribArray(0);

            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
        }

        void update() override
        {
            interface_shape::update();
        }

        void render() override
        {
            interface_shape::render();
            glBindVertexArray(vao_);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        }

    private:
        GLuint vao_{};
    };
}
