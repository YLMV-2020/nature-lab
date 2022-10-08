#pragma once
#include "../interfaces/interface_nature.h"

namespace nature_lab
{
    class nature_controller final : public interface_controller
    {
    public:
        static nature_controller* instance()
        {
            static nature_controller instance;
            return &instance;
        }

        void start() override
        {
            interface_controller::start();
        }

        void update(const float& delta_time) override
        {
            interface_controller::update(delta_time);
            // for (const auto& it : nature_lab_)
            //     it.second->update(delta_time);
            nature_current->update(delta_time);
        }

        void render() override
        {
            interface_controller::render();
            // for (const auto& it : nature_lab_)
            //     it.second->render();
            nature_current->render();
        }

        interface_nature* get_nature(laboratory name_nature)
        {
            const auto it = nature_lab_.find(name_nature);
            if (it != nature_lab_.end())
                return it->second;
            return nullptr;
        }

        void add_nature(laboratory& name_nature, interface_nature* nature)
        {
            nature_lab_.insert(std::pair<laboratory, interface_nature*>(name_nature, nature));
        }

        void bind_nature(laboratory name_nature)
        {
            nature_current = get_nature(name_nature);
        }

    private:
        std::map<laboratory, interface_nature*> nature_lab_;
        interface_nature* nature_current = nullptr;
    };
}
