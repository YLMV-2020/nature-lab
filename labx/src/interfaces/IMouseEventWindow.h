
namespace labx
{
	class IMouseEventWindow{
	public:
		inline virtual ~IMouseEventWindow() = default;
		inline IMouseEventWindow() = default;

		virtual void show() {
			updateMouse();
		}

	protected:

		inline void updateMouse() {

			ImGui::Begin("Render");

			ImVec2 _displayRender = ImGui::GetWindowSize();
			ImVec2 _display = ImGui::GetCursorScreenPos();

			ImVec2 mousePosition = ImGui::GetMousePos();
			ImVec2 sceenPosition = ImGui::GetCursorScreenPos();
			ImVec2 scroll = ImVec2(ImGui::GetScrollX(), ImGui::GetScrollY());

			_mouse = ImVec2(mousePosition.x - sceenPosition.x - scroll.x, mousePosition.y - sceenPosition.y - scroll.y);
			// _mouse.x = (_mouse.x * SceneAssets::SCREEN_WIDTH) / _displayRender.x;
			// _mouse.y = SceneAssets::SCREEN_HEIGHT - SceneAssets::LIMIT_HEIGHT - (_mouse.y * SceneAssets::SCREEN_HEIGHT) / _displayRender.y;

			ImGui::End();
		}

		ImVec2 _mouse;

	};
}
