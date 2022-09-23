#pragma once
#include "../lab/vector/vector_n1.h"
#include "../opengl/gl_shader.h"
#include "glxm/mat4.h"

namespace nature_lab
{
    class scene
    {
    public:
        scene()
        {
            this->start();
            this->resource = resource::instance();
            this->nc_ = nature_controller::instance();
            this->wc_ = window_controller::instance();
            this->wc_->start(window_, version_glsl_);

            vector_n1* vector = new vector_n1();

            nc_->add_nature(vector);
        }

        ~scene()
        {
            glfwTerminate();
            spdlog::info("~Scene() destroyed!");
        }

        int run() const
        {
            while (!glfwWindowShouldClose(window_))
            {
                this->update();
            }
            return 0;
        }

    private:
        void start()
        {
            const int r = atoi(version_glsl_);

            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, r / 10);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, r % 10);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            glfwWindowHint(GLFW_RESIZABLE, false);

            this->window_ = glfwCreateWindow(resource->screen_width, resource->screen_height, "Labsxdev",
                                             nullptr, nullptr);
            glfwMakeContextCurrent(window_);
            if (GLenum err = glewInit()) return;

            //glfwSwapInterval(0);
            glViewport(0, 0, resource->screen_width, resource->screen_height);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        }

        void update() const
        {
            wc_->new_frame();

            glClearColor(0, 0, 0, 0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            nc_->update();
            wc_->update();

            nc_->render();
            wc_->render();

            wc_->end_frame();

            glfwSwapBuffers(window_);
            glfwPollEvents();
        }

        GLFWwindow* window_ = nullptr;
        window_controller* wc_ = nullptr;
        nature_controller* nc_ = nullptr;
        resource* resource = nullptr;

        std::vector<interface_controller*> controllers_;

        char* version_glsl_ = "33";
    };
}
