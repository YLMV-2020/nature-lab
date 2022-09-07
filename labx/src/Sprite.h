#include "Shader.h"
#include "Texture2D.h"
#include <glxm\vec2.h>
#include <glxm\mat4.h>
#include <glxm\Math.h>
namespace NatureLab
{
	class Sprite
	{
	public:
		Sprite(Shader& shader)
		{
			this->_shader = shader;
			this->initRenderData();
		}

		~Sprite()
		{
			glDeleteVertexArrays(1, &this->quadVAO);
		}

		void draw(Texture2D& texture, glxm::vec2 position, glxm::vec2 size = glxm::vec2(10.0f, 10.0f), float rotate = 0.0f, glxm::vec2 color = glxm::vec2(1.0f))
		{
			this->_shader.Use();
			glxm::mat4 model = glxm::mat4(1.0f);

			glxm::mat4 a = glxm::mat4::translate(glxm::mat4::identity(), position);
			glxm::mat4 b = glxm::mat4::translate(glxm::mat4::identity(), glxm::vec2(0.5f * size.x, 0.5f * size.y));
			glxm::mat4 c = glxm::mat4::rotation_around_z(glxm::mat4::identity(), glxm::radians(rotate));
			glxm::mat4 d = glxm::mat4::translate(glxm::mat4::identity(), glxm::vec2(-0.5f * size.x, -0.5f * size.y));
			glxm::mat4 e = glxm::mat4::scale(glxm::mat4::identity(), glxm::vec2(size));

			model = e * d * c * b * a;

			this->_shader.SetMatrix4("model", model);

			glActiveTexture(GL_TEXTURE0);
			texture.Bind();

			glBindVertexArray(this->quadVAO);
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);
		}

		void initRenderData()
		{
			unsigned int VBO;
			float vertices[] = {
				// pos      // tex
				0.0f, 1.0f, 0.0f, 1.0f,
				1.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,

				0.0f, 1.0f, 0.0f, 1.0f,
				1.0f, 1.0f, 1.0f, 1.0f,
				1.0f, 0.0f, 1.0f, 0.0f
			};

			glGenVertexArrays(1, &this->quadVAO);
			glGenBuffers(1, &VBO);

			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glBindVertexArray(this->quadVAO);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
	private:

		Shader _shader;
		unsigned int quadVAO;
	};
}