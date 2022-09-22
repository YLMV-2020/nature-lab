#pragma once
#include "glxm/vec3.h"

namespace glxp
{
    struct object
    {
        glxm::vec3 position;
        glxm::vec3 velocity;
        glxm::vec3 force;
        float mass;
    };
}
