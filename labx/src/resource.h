#pragma once
#include <string>
#include <GL/glew.h>

#include "opengl/gl_shader.h"

namespace nature_lab
{
    class resource
    {
    public:
        static resource* instance()
        {
            static resource instance;
            return &instance;
        }

        gl_shader get_shader(const std::string& name)
        {
            if (shaders.find(name) != shaders.end())
                return shaders[name];
            return shaders[name] = gl_shader(name);
        }

        static float get_aspect_viewport()
        {
            return static_cast<float>(screen_width) / static_cast<float>(screen_height);
        }

        void clear() const
        {
            for (const auto& iter : shaders)
                glDeleteProgram(iter.second.id);
        }

        constexpr static unsigned int screen_width = 1080;
        constexpr static unsigned int screen_height = 720;

        std::map<std::string, gl_shader> shaders;
    };
}
