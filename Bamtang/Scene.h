#pragma once

namespace NatureLab {

	class Scene {
	public:
		inline Scene() {

			this->start();

			this->_frame = new GLFrameBuffer(SceneAssets::SCREEN_WIDTH, SceneAssets::SCREEN_HEIGHT);
			this->nc = NatureController::Instance();
			this->_wc = WindowController::Instance();
			this->_wc->start(_window, "33");

		}

		inline ~Scene() {
			
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

			this->_window = glfwCreateWindow(SceneAssets::SCREEN_WIDTH, SceneAssets::SCREEN_HEIGHT, "Nature Lab", nullptr, nullptr);
			glfwMakeContextCurrent(_window);

			if (GLenum err = glewInit()) return;

			//glfwSwapInterval(0);

			glViewport(0, 0, SceneAssets::SCREEN_WIDTH, SceneAssets::SCREEN_HEIGHT);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		
		inline void update() {

			this->indexScene = _wc->newFrame();

			glBindFramebuffer(GL_FRAMEBUFFER, _frame->update());
			{
				glClearColor(0, 1, 0, 0);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				nc->showNature(this->indexScene);
			}
			glBindFramebuffer(GL_FRAMEBUFFER, 0);

			_wc->render(_frame->show(), this->indexScene);

			glfwSwapBuffers(_window);
			glfwPollEvents();
		}
		
	private:


		GLFWwindow* _window = NULL;
		GLFrameBuffer* _frame = NULL;
		WindowController* _wc = NULL;
		NatureController* nc = NULL;

		int indexScene = 0;

	};
}