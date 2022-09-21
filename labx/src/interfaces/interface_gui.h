namespace nature_lab
{
    class interface_gui
    {
    public:
        inline virtual ~interface_gui() = default;
        inline interface_gui() = default;

        virtual void show()
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

        virtual void init()
        {
        }
    };
}
