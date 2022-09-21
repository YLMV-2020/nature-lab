#pragma once
#include <GL/glew.h>
#include "../../interfaces/IFigure.h"

namespace labx
{
    class GLTriangle2D final : public IFigure
    {
    public:
        GLTriangle2D()
        {
            start();
        }
        
        void start() override
        {
            IFigure::start();

            constexpr float vertices[] = {
                -0.5f, -0.5f, 0.0f, // left  
                0.5f, -0.5f, 0.0f, // right 
                0.0f, 0.5f, 0.0f // top   
            };

            unsigned int vbo;
            glGenVertexArrays(1, &vao);
            glGenBuffers(1, &vbo);
            // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
            glBindVertexArray(vao);

            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);

            // note that this is allowed, the call to glVertexAttribPointer registered vbo as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
            // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor vbos) when it's not directly necessary.
            glBindVertexArray(0);
        }

        void update() override
        {
            IFigure::update();
        }

        void render() override
        {
            IFigure::render();
            glBindVertexArray(vao);
            // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
            glDrawArrays(GL_TRIANGLES, 0, 3);
            // glBindVertexArray(0); // no need to unbind it every time 
        }

    private:
        GLuint vao{};
    };

    static void render_triangle()
    {
        static GLTriangle2D triangle;
        triangle.render();
    }
}
