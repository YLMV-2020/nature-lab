
namespace NatureLab
{
	class IWindow {
	public:
		inline virtual ~IWindow() = default;
		inline IWindow() = default;
		virtual void show() = 0;

	protected:
		inline void begin(const char* title, ImGuiWindowFlags flags = 0) {
			ImGui::Begin(title, NULL, flags);
		}

		inline void end() {
			ImGui::End();
		}

		inline virtual void init() {}

	};
}
