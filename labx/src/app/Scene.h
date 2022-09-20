#pragma once

namespace NatureLab
{
    class Scene
    {
    public:
        inline Scene()
        {
            this->start();

            this->nc = NatureController::Instance();
            this->_wc = WindowController::Instance();
            this->_wc->start(_window, "33");
        }

        inline ~Scene()
        {
            glfwTerminate();
            spdlog::info("~Scene() destroyed!");
        }

        inline int run()
        {
            while (!glfwWindowShouldClose(_window))
            {
                this->update();
            }
            return 0;
        }

    private:
        inline void start()
        {
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            glfwWindowHint(GLFW_RESIZABLE, false);

            this->_window = glfwCreateWindow(800, 600, "Nature Lab",
                                             nullptr, nullptr);
            glfwMakeContextCurrent(_window);

            if (GLenum err = glewInit()) return;

            //glfwSwapInterval(0);

            glViewport(0, 0, 800, 600);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        }


        inline void update()
        {
            _wc->newFrame();
            
            glClearColor(0, 1, 0, 0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            nc->showNature();
            _wc->render(0);

            glfwSwapBuffers(_window);
            glfwPollEvents();
        }

    private:
        GLFWwindow* _window = NULL;
        WindowController* _wc = NULL;
        NatureController* nc = NULL;
        
    };
}
