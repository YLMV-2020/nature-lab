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
			this->nc_ = nature_controller::instance();
			this->wc_ = window_controller::instance();
			this->ac_ = asset_controller::instance();
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

			this->window_ = glfwCreateWindow(ac_->screen_width, ac_->screen_height, "Labsxdev",
				nullptr, nullptr);
			glfwMakeContextCurrent(window_);
			if (GLenum err = glewInit()) return;

			//glfwSwapInterval(0);
			glViewport(0, 0, ac_->screen_width, ac_->screen_height);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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

			glxm::mat4 model = glxm::mat4(1.0f);
			glxm::mat4 view = glxm::mat4(1.0f);
			glxm::mat4 projection = glxm::mat4(1.0f);


			//model = glxm::scale(model, glxm::vec2(0.50f, 0.50f));
			model = glxm::translate(model, glxm::vec2(0.0f, 0.0f));
			// view = glxm::translate(view, glxm::vec2(0.0f, 0.0f));


			projection = glxm::ortho(projection, -4.0f, 4.0f,
				-3.0f, 3.0f, 0.0f, 100.0f);

			// glxm::printf(projection);

			// retrieve the matrix uniform locations
			unsigned int modelLoc = glGetUniformLocation(shader_.id, "model");
			unsigned int viewLoc = glGetUniformLocation(shader_.id, "view");
			unsigned int projectionLoc = glGetUniformLocation(shader_.id, "projection");
			// pass them to the shaders (3 different ways)
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model.val[0]);
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view.val[0]);
			glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projection.val[0]);
			// note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
			// shader_.set_mat4("projection", projection);

			nc_->render();
			wc_->render(0);

			glfwSwapBuffers(window_);
			glfwPollEvents();
		}

		GLFWwindow* window_ = nullptr;
		window_controller* wc_ = nullptr;
		nature_controller* nc_ = nullptr;
		asset_controller* ac_ = nullptr;

		char* version_glsl_ = "33";

		gl_shader shader_;
	};
}
