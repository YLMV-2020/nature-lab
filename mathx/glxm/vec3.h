#pragma once

namespace glxm
{
    class __declspec(dllexport) vec3
    {
    public:
        float x, y, z;

        vec3();
        explicit vec3(float x);
        explicit vec3(float x, float y);
        vec3(float x, float y, float z);

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

        friend vec3 operator*(const vec3& v1, const vec3& v2)
        {
            return {v1.x * v2.x, v1.y * v2.y, v1.z * v2.z};
        }

        friend vec3 operator*(const vec3& v1, const float scale)
        {
            return {v1.x * scale, v1.y * scale, v1.z * scale};
        }

        friend vec3 operator/(const vec3 v1, const vec3 v2)
        {
            return {v1.x / v2.x, v1.y / v2.y, v1.z / v2.z};
        }

        friend vec3 operator/(const vec3& v1, const float& scale)
        {
            return {v1.x / scale, v1.y / scale, v1.z / scale};
        }

        friend vec3 operator*(float scale, vec3 v1);
        friend bool operator==(vec3 v1, vec3 v2);
        friend bool operator!=(vec3 v1, vec3 v2);

        static float point(vec3 v1, vec3 v2);
        static float magnitude(const vec3& v1);
        static float magnitude_quad(vec3 v1);
        static vec3 normalized(const vec3& v1);
        static float angle(vec3 v1, vec3 v2);

        void add(const vec3& v1);
        void normalized();
    };
}
