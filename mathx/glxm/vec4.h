#pragma once

namespace glxm
{
    class __declspec(dllexport) vec4
    {
    public:
        float x, y, z, w;

        vec4();
        explicit vec4(float x);
        vec4(float x, float y, float z);
        vec4(float x, float y, float z, float w);

        friend vec4 operator+(const vec4& v1, const vec4& v2)
        {
            return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
        }

        friend vec4 operator+=(const vec4& v1, const vec4& v2)
        {
            return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
        }

        friend vec4 operator-(const vec4& v1, const vec4& v2)
        {
            return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
        }

        friend vec4 operator*(const vec4& v1, const vec4& v2)
        {
            return {v1.x * v2.x, v1.y * v2.y, v1.z * v2.z};
        }

        friend vec4 operator*(const vec4& v1, const float scale)
        {
            return {v1.x * scale, v1.y * scale, v1.z * scale};
        }

        friend vec4 operator/(const vec4 v1, const vec4 v2)
        {
            return {v1.x / v2.x, v1.y / v2.y, v1.z / v2.z};
        }

        friend vec4 operator/(const vec4& v1, const float& scale)
        {
            return {v1.x / scale, v1.y / scale, v1.z / scale};
        }

        friend vec4 operator*(float scale, vec4 v1);
        friend bool operator==(vec4 v1, vec4 v2);
        friend bool operator!=(vec4 v1, vec4 v2);

        static float point(vec4 v1, vec4 v2);
        static float magnitude(const vec4& v1);
        static float magnitude_quad(vec4 v1);
        static vec4 normalized(const vec4& v1);
        static float angle(vec4 v1, vec4 v2);

        void add(const vec4& v1);
        void normalized();
    };
}
