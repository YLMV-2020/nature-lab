#pragma once
namespace nature_lab
{
    class interface_gui
    {
    public:
        virtual ~interface_gui() = default;
        interface_gui() = default;

        virtual void start()
        {
        }

        virtual void update()
        {
        }

        virtual void render()
        {
        }
        
    protected:
        void begin(const char* title, const ImGuiWindowFlags flags = 0)
        {
            ImGui::Begin(title, NULL, flags);
        }
        
        void end()
        {
            ImGui::End();
        }
    };
}
