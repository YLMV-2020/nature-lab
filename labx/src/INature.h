#include "Texture2D.h"
#include "SceneAssets.h"
#include "Sprite.h"

namespace NatureLab
{
	class INature {
	public:
		inline virtual ~INature() = default;
		inline INature() = default;

		virtual void show()
		{
			Texture2D backgroundTexture = SceneAssets::getTexture("background");
			sprite->draw(backgroundTexture, glxm::vec2(0.0f, 0.0f), glxm::vec2(SceneAssets::SCREEN_WIDTH, SceneAssets::SCREEN_HEIGHT), 0.0f);
		}

	protected:

		inline virtual void start() {

			Shader _shader = SceneAssets::getShader("sprite");
			this->sprite = new NatureLab::Sprite(_shader);

			glxm::mat4 projection = glxm::mat4();
			projection.identity();
			projection = glxm::mat4::ortho(glxm::mat4::identity(), 0.0f, static_cast<float>(SceneAssets::SCREEN_WIDTH),
				0.0f, static_cast<float>(SceneAssets::SCREEN_HEIGHT), -1.0f, 1.0f);

			SceneAssets::getShader("sprite").Use().SetInteger("image", 0);
			//SceneAssets::getShader("sprite").Use().SetVector3f("spriteColor", Math::Vector(0.5f));
			SceneAssets::getShader("sprite").SetMatrix4("projection", projection);
		}

		inline virtual void update() {


		}

	protected:

		NatureLab::Sprite* sprite = NULL;
	};
}
