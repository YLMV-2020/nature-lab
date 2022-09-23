#pragma once
#include <gl/glew.h>
#include "../../interfaces/interface_figure.h"

namespace figure
{
    class gl_triangle_2d final : public interface_figure
    {
    public:
        
        gl_triangle_2d()
        {
            start();
        }

        void start() override
        {
            interface_figure::start();

            constexpr float vertices[] = {
                -0.5f, -0.5f, 0.0f, // left  
                0.5f, -0.5f, 0.0f, // right 
                0.0f, 0.5f, 0.0f // top   
            };

            unsigned int vbo;
            glGenVertexArrays(1, &vao_);
            glGenBuffers(1, &vbo);
            glBindVertexArray(vao_);

            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), static_cast<void*>(0));
            glEnableVertexAttribArray(0);

            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
        }

        void update() override
        {
            interface_figure::update();
        }

        void render() override
        {
            interface_figure::render();
            glBindVertexArray(vao_);
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }

    private:
        GLuint vao_{};
    };

    static void render_triangle()
    {
        static gl_triangle_2d triangle;
        triangle.render();
    }
}
