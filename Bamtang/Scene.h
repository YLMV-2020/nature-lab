#pragma once

namespace NatureLab {

	class Scene {
	public:
		inline Scene() {

			this->start();

			this->_frame = new GLFrameBuffer(SCREEN_WIDTH, SCREEN_HEIGHT);
			this->_wc = new WindowController(_window, "33");
			this->nc = new NatureController();

		}

		inline ~Scene() {
			
			glfwTerminate();
			spdlog::info("~Scene() destroyed!");
		}

		inline void run()
		{
			while (!glfwWindowShouldClose(_window))
			{
				this->update();
			}
		}

	private:

		inline void start()
		{
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			glfwWindowHint(GLFW_RESIZABLE, false);

			this->_window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Nature Lab", nullptr, nullptr);
			glfwMakeContextCurrent(_window);

			if (GLenum err = glewInit()) return;

			//glfwSwapInterval(0);

			glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		
		inline void update() {

			_wc->newFrame();

			glBindFramebuffer(GL_FRAMEBUFFER, _frame->update());
			{
				glClearColor(0, 1, 0, 0);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				nc->showNature();
			}
			glBindFramebuffer(GL_FRAMEBUFFER, 0);

			_wc->render(_frame->show());

			glfwSwapBuffers(_window);
			glfwPollEvents();
		}

	public:

		const unsigned int SCREEN_WIDTH = 1080;
		const unsigned int SCREEN_HEIGHT = 720;
		
	private:


		GLFWwindow* _window = NULL;
		GLFrameBuffer* _frame = NULL;
		WindowController* _wc = NULL;
		NatureController* nc = NULL;

	};
}