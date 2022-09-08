#include <map>
#include <string>

#include "Texture2D.h"
#include "Shader.h"

namespace NatureLab {

    class SceneAssets
    {
    public:
        static std::map<std::string, Shader>    _shaders;
        static std::map<std::string, Texture2D> _textures;

        static Shader    load_shader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name);
        static Shader    get_shader(std::string name);
        static Texture2D load_texture(const char* file, bool alpha, std::string name);
        static Texture2D get_texture(std::string name);
        static void      clear();

        const static unsigned int SCREEN_WIDTH = 1080;
        const static unsigned int SCREEN_HEIGHT = 720;

        const static unsigned int LIMIT_WIDTH = 50;
        const static unsigned int LIMIT_HEIGHT = 50;
    private:

        SceneAssets() { }

        static Shader    loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);
        static Texture2D loadTextureFromFile(const char* file, bool alpha);
    };

}