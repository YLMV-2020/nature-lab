#include <vector>
#include "object.h"

namespace glxp
{
    class physics_world
    {
    private:
        std::vector<glxp::object*> m_objects_;
        glxm::vec3 m_gravity = glxm::vec3(0, -9.81f, 0);

    public:
        void add_object(glxp::object* object)
        {
            m_objects_.push_back(object);
        }

        void remove_object(const glxp::object* object)
        {
            for (int i = 0; i < m_objects_.size(); i++)
            {
                if (m_objects_[i] == object)
                    m_objects_.erase(m_objects_.begin() + i);
            }
        }

        void step(const float dt) const
        {
            for (glxp::object* obj : m_objects_)
            {
                obj->force += obj->mass * m_gravity; // apply a force

                obj->velocity += obj->force / obj->mass * dt;
                obj->position += obj->velocity * dt;

                obj->force = glxm::vec3(0, 0, 0); // reset net force at the end
            }
        }
    };
}
