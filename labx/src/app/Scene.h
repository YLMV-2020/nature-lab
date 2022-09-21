#pragma once
#include "../opengl/gl_shader.h"
#include "../opengl/figures/gl_triangle_2d.h"

namespace nature_lab
{
    class Scene
    {
    public:
        Scene()
        {
            this->start();
            this->nc_ = NatureController::Instance();
            this->wc_ = WindowController::Instance();
            this->wc_->start(window_, version_glsl_);
        }

        ~Scene()
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
            //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
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

            shader = GLShader("assets//shaders//sprite.vert", "assets//shaders//sprite.frag");
        }

        void update() const
        {
            wc_->new_frame();

            glClearColor(0, 0, 0, 0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            //shader.use();

            nc_->showNature();

            ImGui::Begin("Init");
            ImGui::Text("Hello World");
            ImGui::End();

            glUseProgram(shader.id);

            // shader.use();


            // triangle->render();


            figure::render_triangle();

            wc_->render(0);

            glfwSwapBuffers(window_);
            glfwPollEvents();
        }

        GLFWwindow* window_ = nullptr;
        WindowController* wc_ = nullptr;
        NatureController* nc_ = nullptr;

        constexpr static int widht = 1080;
        constexpr static int height = 720;

        char* version_glsl_ = "33";

        GLShader shader;
        // GLTriangle2D* triangle;
    };
}
