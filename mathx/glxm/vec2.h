#pragma once
#include <cmath>

namespace glxm
{
    class vec2
    {
    public:
        float x, y;

        vec2()
        {
            x = y = 0.0f;
        }

        explicit vec2(const float v)
        {
            this->x = this->y = v;
        }

        vec2(float x, float y)
        {
            this->x = x;
            this->y = y;
        }

        friend vec2 operator+(const vec2& v1, const vec2& v2)
        {
            return {v1.x + v2.x, v1.y + v2.y};
        }

        friend vec2 operator+=(const vec2& v1, const vec2& v2)
        {
            return {v1.x + v2.x, v1.y + v2.y};
        }

        friend vec2 operator-(const vec2& v1, const vec2& v2)
        {
            return {v1.x - v2.x, v1.y - v2.y};
        }

        friend vec2 operator*(const vec2& v1, const vec2& v2);

        friend vec2 operator*(const vec2& v1, const float scale)
        {
            return {v1.x * scale, v1.y * scale};
        }

        friend vec2 operator/(vec2 v1, vec2 v2);

        friend vec2 operator/(const vec2& v1, const float& scale)
        {
            return {v1.x / scale, v1.y / scale};
        }

        friend vec2 operator*(float scale, vec2 v1);
        friend bool operator==(vec2 v1, vec2 v2);
        friend bool operator!=(vec2 v1, vec2 v2);

        static float point(const vec2 v1, const vec2 v2)
        {
            return v1.x * v2.x + v1.y * v2.y;
        }

        static float magnitude(const vec2& v1)
        {
            return sqrt(v1.x * v1.x + v1.y * v1.y);
        }

        static float magnitude_quad(const vec2& v1)
        {
            return v1.x * v1.x + v1.y * v1.y;
        }

        static vec2 normalized(const vec2& v1)
        {
            const float m = sqrt(v1.x * v1.x + v1.y * v1.y);
            return {v1.x / m, v1.y / m};
        }

        static float angle(vec2 v1, vec2 v2) { return 0.0f; }
    };
}
