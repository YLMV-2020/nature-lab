#include <glxm\vec2.h>
#include <glxm\vec3.h>
#include <gl\glew.h>

#include "SceneAssets.h"

namespace NatureLab
{
	class Line
	{
	public:

		inline Line() { }

		inline void draw(glxm::vec2 start, glxm::vec2 end, glxm::vec3 color = glxm::vec3(1.0)) {

			this->update(start, end, color);

			glUseProgram(this->shaderProgram);
			glUniform3fv(glGetUniformLocation(this->shaderProgram, "color"),
				1, &this->lineColor.x);

			glBindVertexArray(this->VAO);
			glDrawArrays(GL_LINES, 0, 2);
		}

	private:

		inline void update(glxm::vec2  start, glxm::vec2  end, glxm::vec3 color = glxm::vec3(1.0)) {
			float x1 = start.x;
			float y1 = start.y;
			float x2 = end.x;
			float y2 = end.y;
			float w = SceneAssets::SCREEN_WIDTH;
			float h = SceneAssets::SCREEN_HEIGHT;

			// convert 3d world space position 2d screen space position
			x1 = 2 * x1 / w - 1;
			y1 = 2 * y1 / h - 1;

			x2 = 2 * x2 / w - 1;
			y2 = 2 * y2 / h - 1;

			start.x = x1;
			start.y = y1;
			end.x = x2;
			end.y = y2;

			this->startPoint = start;
			this->endPoint = end;
			this->lineColor = color;

			const char* vertexShaderSource = "#version 330 core\n"
				"layout (location = 0) in vec3 aPos;\n"
				"void main()\n"
				"{\n"
				"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
				"}\0";
			const char* fragmentShaderSource = "#version 330 core\n"
				"out vec4 FragColor;\n"
				"uniform vec3 color;\n"
				"void main()\n"
				"{\n"
				"   FragColor = vec4(color, 1.0f);\n"
				"}\n\0";

			// vertex shader
			int vertexShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
			glCompileShader(vertexShader);

			// fragment shader
			int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
			glCompileShader(fragmentShader);

			// link shaders
			this->shaderProgram = glCreateProgram();
			glAttachShader(this->shaderProgram, vertexShader);
			glAttachShader(this->shaderProgram, fragmentShader);
			glLinkProgram(this->shaderProgram);

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			// setting vertex data
			this->vertices = (float*)(malloc(sizeof(float) * 6));
			this->vertices[0] = start.x;
			this->vertices[1] = start.y;
			this->vertices[2] = end.x;
			this->vertices[3] = end.y;

			glGenVertexArrays(1, &this->VAO);
			glGenBuffers(1, &this->VBO);
			glBindVertexArray(this->VAO);

			glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices) * 4,
				&this->vertices[0],
				GL_STATIC_DRAW);

			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
				2 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}

	private:

		int shaderProgram;
		unsigned int VBO, VAO;
		float* vertices;
		glxm::vec2 startPoint;
		glxm::vec2 endPoint;
		glxm::vec3 lineColor;
	};

}