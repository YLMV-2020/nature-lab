#pragma once

#include "glxm/mat4.h"

namespace figure
{
    class interface_figure
    {
    protected:
        virtual ~interface_figure() = default;
    public:
        virtual void start()
        {
            const auto asset_controller = nature_lab::resource::instance();
            shader = asset_controller->get_shader("figure");
            projection = glxm::ortho(projection, 0.0f, nature_lab::resource::screen_width,
                                     0.0f, nature_lab::resource::screen_height, -0.01f, 1.0f);
        }

        virtual void update()
        {
            shader.use();
            model = glxm::mat4(1.0f);

            model = glxm::translate(model, position);
            model = glxm::scale(model, scale);

            // recomend use product dot -> investigation (operator *)
            // https://stackoverflow.com/questions/59222806/how-does-glm-handle-translation?
            model = glxm::rotate_z(glxm::mat4(1.0f), glxm::radians(rotation)) * model;

            shader.set_vec3("color", color);
            shader.set_mat4("model", model);
            shader.set_mat4("projection", projection);
        }

        virtual void render()
        {
        }

        void set_position(const glxm::vec2& position)
        {
            this->position = position;
        }

        void set_scale(const glxm::vec2& scale)
        {
            this->scale = scale;
        }

        void set_rotation(const float rotation)
        {
            this->rotation = rotation;
        }

        void set_color(const glxm::vec3& color)
        {
            this->color = color;
        }

    protected:
        glxm::mat4 projection = glxm::mat4(1.0f);
        glxm::mat4 model = glxm::mat4(1.0f);

        glxm::vec2 position = glxm::vec2(0.0f, 0.0f);
        glxm::vec2 scale = glxm::vec2(1.0f, 1.0f);
        float rotation = 90.0f;

        glxm::vec3 color = glxm::vec3(0.0f, 1.0f, 0.0f);
        nature_lab::gl_shader shader;
    };
}
