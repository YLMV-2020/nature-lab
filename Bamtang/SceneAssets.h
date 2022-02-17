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

        static Shader    loadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name);
        static Shader    getShader(std::string name);
        static Texture2D loadTexture(const char* file, bool alpha, std::string name);
        static Texture2D getTexture(std::string name);
        static void      clear();

        const static unsigned int SCREEN_WIDTH = 1080;
        const static unsigned int SCREEN_HEIGHT = 720;

    private:

        SceneAssets() { }

        static Shader    loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);
        static Texture2D loadTextureFromFile(const char* file, bool alpha);
    };

}