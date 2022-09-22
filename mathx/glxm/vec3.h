#pragma once
#include <cmath>

namespace glxm
{
    class vec3
    {
    public:
        float x, y, z;

        vec3()
        {
            x = y = z = 0.0f;
        }

        explicit vec3(const float v)
        {
            this->x = this->y = this->z = v;
        }

        vec3(const float x, const float y, const float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        friend vec3 operator+(const vec3& v1, const vec3& v2)
        {
            return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
        }

        friend vec3 operator+=(const vec3& v1, const vec3& v2)
        {
            return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
        }

        friend vec3 operator-(const vec3& v1, const vec3& v2)
        {
            return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
        }

        friend vec3 operator*(const vec3& v1, const vec3& v2);

        friend vec3 operator*(const vec3& v1, const float scale)
        {
            return {v1.x * scale, v1.y * scale, v1.z * scale};
        }

        friend vec3 operator/(vec3 v1, vec3 v2);

        friend vec3 operator/(const vec3& v1, const float& scale)
        {
            return {v1.x / scale, v1.y / scale, v1.z / scale};
        }

        friend vec3 operator*(float scale, vec3 v1);
        friend bool operator==(vec3 v1, vec3 v2);
        friend bool operator!=(vec3 v1, vec3 v2);

        static float point(const vec3 v1, const vec3 v2)
        {
            return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
        }

        static float magnitude(const vec3& v1)
        {
            return sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
        }

        static float magnitude_quad(const vec3& v1)
        {
            return v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
        }

        static vec3 normalized(const vec3& v1)
        {
            const float m = magnitude(v1);
            return {v1.x / m, v1.y / m, v1.z / m};
        }

        static float angle(vec3 v1, vec3 v2) { return 0.0f; }
    };
}
