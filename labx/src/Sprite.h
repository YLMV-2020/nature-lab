#include "glxm/Math.h"

namespace NatureLab
{
	class Sprite
	{
	public:
		Sprite(Shader& shader)
		{
			this->_shader = shader;
			this->init_render_data();
		}

		~Sprite()
		{
			glDeleteVertexArrays(1, &this->quadVAO);
		}

		void draw(const Texture2D& texture, const glxm::vec2 position, const glxm::vec2 size = glxm::vec2(10.0f, 10.0f), float rotate = 0.0f, glxm::vec2 color = glxm::vec2(1.0f))
		{
			this->_shader.Use();
			glxm::mat4 model = glxm::mat4(1.0f);

			const glxm::mat4 a = glxm::mat4::translate(model, position);
			const glxm::mat4 b = glxm::mat4::translate(model, glxm::vec2(0.5f * size.x, 0.5f * size.y));
			const glxm::mat4 c = glxm::mat4::rotation_around_z(model, glxm::radians(rotate));
			const glxm::mat4 d = glxm::mat4::translate(model, glxm::vec2(-0.5f * size.x, -0.5f * size.y));
			glxm::mat4 e = glxm::mat4::scale(model, glxm::vec2(size));

			model = e * d * c * b * a;

			this->_shader.SetMatrix4("model", model);

			glActiveTexture(GL_TEXTURE0);
			texture.Bind();

			glBindVertexArray(this->quadVAO);
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);
		}

		void init_render_data()
		{
			unsigned int VBO;
			constexpr float vertices[] = {
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
			glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), static_cast<void*>(0));
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
	private:

		Shader _shader;
		unsigned int quadVAO;
	};
}
