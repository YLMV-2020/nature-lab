
namespace NatureLab
{
	class INature {
	public:
		virtual ~INature() = default;
		 INature() = default;

		virtual void show()
		{
			// const Texture2D background_texture = SceneAssets::get_texture("background");
			// sprite->draw(background_texture, glxm::vec2(-600.0f, 0.0f), glxm::vec2(2900, 600), 0.0f);
		}

	protected:
		virtual void start() {

			// Shader shader = SceneAssets::get_shader("sprite");
			// this->sprite = new NatureLab::Sprite(shader);
			//
			// glxm::mat4 projection = glxm::mat4(1.0f);
			// projection = glxm::mat4::ortho(glxm::mat4::identity(), 0.0f, static_cast<float>(SceneAssets::SCREEN_WIDTH),
			// 	0.0f, static_cast<float>(SceneAssets::SCREEN_HEIGHT), -1.0f, 1.0f);
			//
			// SceneAssets::get_shader("sprite").Use().SetInteger("image", 0);
			// //SceneAssets::getShader("sprite").Use().SetVector3f("spriteColor", Math::Vector(0.5f));
			// SceneAssets::get_shader("sprite").SetMatrix4("projection", projection);
		}

		virtual void update() {


		}

	protected:
		// Sprite* sprite = NULL;
	};
}
