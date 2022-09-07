#include "vec3.h"

#include <cmath>

namespace glxm
{
    vec3::vec3()
    {
        x = y = z = 0.0f;
    }

    vec3::vec3(float x)
    {
        this->x = this->y = this->z = x;
    }

    vec3::vec3(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    vec3::vec3(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }


    float vec3::point(vec3 v1, vec3 v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    float vec3::magnitude(const vec3& v1)
    {
        return sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
    }

    float vec3::magnitude_quad(vec3 v1)
    {
        return v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
    }

    vec3 vec3::normalized(const vec3& v1)
    {
        const float m = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
        return {v1.x / m, v1.y / m, v1.z / m};
    }

    float vec3::angle(vec3 v1, vec3 v2)
    {
        return 0.0f;
    }

    void vec3::add(const vec3& v1)
    {
        this->x += v1.x;
        this->y += v1.y;
        this->z += v1.z;
    }

    void vec3::normalized()
    {
        const float m = sqrt(x * x + y * y + z * z);
        x /= m;
        y /= m;
        z /= m;
    }
}
