
namespace NatureLab
{
	class INature {
	public:
		inline virtual ~INature() = default;
		inline INature() = default;

		virtual void show()
		{
			Texture2D backgroundTexture = SceneAssets::getTexture("background");
			sprite->draw(backgroundTexture, Math::Vector(0.0f, 0.0f), Math::Vector(SceneAssets::SCREEN_WIDTH, SceneAssets::SCREEN_HEIGHT), 0.0f);
		}

	protected:
		
		inline virtual void start() {

			Shader _shader = SceneAssets::getShader("sprite");
			this->sprite = new NatureLab::Sprite(_shader);

			Math::Matrix projection = Math::Matrix();
			projection.identity();
			projection = Math::Matrix::ortho(Math::Matrix::identity(), 0.0f, static_cast<float>(SceneAssets::SCREEN_WIDTH),
				0.0f, static_cast<float>(SceneAssets::SCREEN_HEIGHT), -1.0f, 1.0f);

			SceneAssets::getShader("sprite").Use().SetInteger("image", 0);
			//SceneAssets::getShader("sprite").Use().SetVector3f("spriteColor", Math::Vector(0.5f));
			SceneAssets::getShader("sprite").SetMatrix4("projection", projection);
		}

		inline virtual void update() {

			float currentFrame = glfwGetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;
			time = currentFrame - startFrame;
		}

	protected:

		float deltaTime = 0.0f;
		float lastFrame = 0.0f;
		float time = 0.0f;
		float startFrame = glfwGetTime();

		NatureLab::Sprite* sprite = NULL;

	};
}
