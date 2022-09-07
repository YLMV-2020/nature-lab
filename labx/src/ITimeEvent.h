#include <GLFW\glfw3.h>

namespace NatureLab
{
	class ITimeEvent {
	public:
		inline virtual ~ITimeEvent() = default;
		inline ITimeEvent() = default;

		virtual void show() = 0;

	protected:

		inline virtual void update() {
			float currentFrame = glfwGetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;
			time = currentFrame - startFrame;
		}

		float deltaTime = 0.0f;
		float lastFrame = 0.0f;
		float time = 0.0f;
		float startFrame = glfwGetTime();

	};
}
