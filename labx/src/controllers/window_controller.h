#include "../interfaces/interface_gui.h"

namespace nature_lab
{
    class window_controller final : public interface_controller
    {
    public:
        static window_controller* instance()
        {
            static window_controller instance;
            return &instance;
        }

        window_controller()
        {
        }

        void start() override
        {
            interface_controller::start();

            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            glfwWindowHint(GLFW_RESIZABLE, false);

            this->window_ = glfwCreateWindow(resource::instance()->screen_width, resource::instance()->screen_height,
                                             "Labsxdev",
                                             nullptr, nullptr);
            glfwMakeContextCurrent(window_);
            if (GLenum err = glewInit()) return;

            //glfwSwapInterval(0);
            glViewport(0, 0, resource::instance()->screen_width, resource::instance()->screen_height);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        }

        void update() override
        {
            interface_controller::update();
        }

        void render() override
        {
            interface_controller::render();
            glfwSwapBuffers(window_);
            glfwPollEvents();
        }

        bool is_run() const
        {
            return !glfwWindowShouldClose(window_);
        }

        GLFWwindow* get_window() const
        {
            return window_;
        }

    private:
        GLFWwindow* window_ = nullptr;
    };
}
