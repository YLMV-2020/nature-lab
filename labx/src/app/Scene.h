#pragma once
#include "../lab/vector/vector_n1.h"
#include "../opengl/gl_shader.h"

namespace nature_lab
{
    class scene
    {
    public:
        scene()
        {
            this->start();
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

            this->window_ = glfwCreateWindow(widht, height, "Labsxdev",
                                             nullptr, nullptr);
            glfwMakeContextCurrent(window_);
            if (GLenum err = glewInit()) return;

            //glfwSwapInterval(0);
            glViewport(0, 0, widht, height);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            // triangle = new GLTriangle2D();
            

            shader_ = asset_controller::instance()->get_shader("figure");
        }

        void update() const
        {
            wc_->new_frame();

            glClearColor(0, 0, 0, 0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            ImGui::Begin("Init");
            ImGui::Text("Hello World");
            ImGui::End();

            shader_.use();

            nc_->render();
            wc_->render(0);

            glfwSwapBuffers(window_);
            glfwPollEvents();
        }

        GLFWwindow* window_ = nullptr;
        window_controller* wc_ = nullptr;
        nature_controller* nc_ = nullptr;

        constexpr static int widht = 1080;
        constexpr static int height = 720;

        char* version_glsl_ = "33";

        gl_shader shader_;
    };
}
