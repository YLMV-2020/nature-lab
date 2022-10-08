#pragma once
#include <gl/glew.h>
#include "../../interfaces/interface_shape.h"

namespace shape
{
    class gl_circle_2d final : public interface_shape
    {
    public:
        gl_circle_2d()
        {
            start();
        }

        void start() override
        {
            interface_shape::start();

            constexpr float vertices[] = {
                0, 0, 0,
                0, 50, 0,
                20, 40, 0,
                40, 20, 0,
                50, 0, 0,
                40, -20, 0,
                20, -40, 0,
                0, -50, 0,
                -20, -40, 0,
                -40, -20, 0,
                -50, 0, 0,
                -40, 20, 0,
                -20, 40, 0
            };
            const unsigned int indices[] = {
                0, 1, 2,
                0, 2, 3,
                0, 3, 4,
                0, 4, 5,
                0, 5, 6,
                0, 6, 7,
                0, 7, 8,
                0, 8, 9,
                0, 9, 10,
                0, 10, 11,
                0, 11, 12,
                0, 1, 12
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
            glDrawElements(GL_TRIANGLES, 3 * 12, GL_UNSIGNED_INT, 0);
        }

    private:
        GLuint vao_{};
    };
}
