#pragma once

namespace glxm
{
    class __declspec(dllexport) vec2
    {
    public:
        float x, y;

        vec2();
        explicit vec2(float x);
        vec2(float x, float y);

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

        static float point(vec2 v1, vec2 v2);
        static float magnitude(const vec2& v1);
        static float magnitudeQuad(vec2 v1);
        static vec2 normalized(const vec2& v1);
        static float angle(vec2 v1, vec2 v2);

        void add(const vec2& v1);
        void normalized();
    };
}
