#pragma once
#include "time.h"
#include "../controls/vector/vector_u1.h"
#include "../controls/vector/vector_u2.h"

#include "../lab/vector/vector_n1.h"
#include "../lab/vector/vector_n2.h"

namespace nature_lab
{
    class scene
    {
    public:
        scene()
        {
            this->resource_ = resource::instance();
            this->time_ = time::instance();

            this->nc_ = nature_controller::instance();
            this->wc_ = window_controller::instance();
            this->gc_ = gui_controller::instance();

            this->start();
        }

        ~scene()
        {
            glfwTerminate();
            std::cout << "~Scene() destroyed!";
        }

        void start() const
        {
            this->nc_->start();
            this->wc_->start();
            this->gc_->start();

            gc_->link_window(wc_->get_window());
            load();
        }

        void update() const
        {
            time_->update();

            wc_->update(time_->get_delta_time());
            gc_->update(time_->get_delta_time());
            nc_->update(time_->get_delta_time());
        }

        void render() const
        {
            nc_->render();
            gc_->render();
            wc_->render();
        }

        void load() const
        {
            gc_->load_gui();
        }

        void add_lab(laboratory name_controls, interface_nature* nature, interface_gui* control) const
        {
            nc_->add_nature(name_controls, nature);
            gc_->add_control(name_controls, control);
        }

        void bind_lab(const laboratory name_lab) const
        {
            interface_nature* nature = nullptr;
            interface_gui* control = nullptr;

            switch (name_lab)
            {
            case laboratory::vector_n1:
                nature = new vector_n1();
                control = new vector_u1();
                break;
            case laboratory::vector_n2:
                nature = new vector_n2();
                control = new vector_u2();
                break;
            default: ;
            }
            add_lab(name_lab, nature, control);
        }

        int run(const laboratory name_lab) const
        {
            bind_lab(name_lab);
            nc_->bind_nature(name_lab);
            gc_->bind_control(name_lab);

            while (wc_->is_run())
            {
                glClearColor(0, 0, 0, 0);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                update();
                render();
            }
            return 0;
        }

    private:
        window_controller* wc_ = nullptr;
        nature_controller* nc_ = nullptr;
        gui_controller* gc_ = nullptr;

        resource* resource_ = nullptr;
        time* time_ = nullptr;
    };
}
