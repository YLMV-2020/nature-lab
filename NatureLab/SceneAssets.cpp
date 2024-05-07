#include "SceneAssets.h"

#include <iostream>
#include <sstream>
#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace NatureLab {

    std::map<std::string, Texture2D>    SceneAssets::_textures;
    std::map<std::string, Shader>       SceneAssets::_shaders;

    Shader SceneAssets::loadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name)
    {
        _shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
        return _shaders[name];
    }

    Shader SceneAssets::getShader(std::string name)
    {
        return _shaders[name];
    }

    Texture2D SceneAssets::loadTexture(const char* file, bool alpha, std::string name)
    {
        _textures[name] = loadTextureFromFile(file, alpha);
        return _textures[name];
    }

    Texture2D SceneAssets::getTexture(std::string name)
    {
        return _textures[name];
    }

    void SceneAssets::clear()
    {
        for (auto iter : _shaders)
            glDeleteProgram(iter.second.ID);
        for (auto iter : _textures)
            glDeleteTextures(1, &iter.second.ID);
    }

    Shader SceneAssets::loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile)
    {

        std::string vertexCode;
        std::string fragmentCode;
        std::string geometryCode;
        try
        {

            std::ifstream vertexShaderFile(vShaderFile);
            std::ifstream fragmentShaderFile(fShaderFile);
            std::stringstream vShaderStream, fShaderStream;

            vShaderStream << vertexShaderFile.rdbuf();
            fShaderStream << fragmentShaderFile.rdbuf();

            vertexShaderFile.close();
            fragmentShaderFile.close();

            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();

            if (gShaderFile != nullptr)
            {
                std::ifstream geometryShaderFile(gShaderFile);
                std::stringstream gShaderStream;
                gShaderStream << geometryShaderFile.rdbuf();
                geometryShaderFile.close();
                geometryCode = gShaderStream.str();
            }
        }
        catch (std::exception e)
        {
            std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
        }
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();
        const char* gShaderCode = geometryCode.c_str();

        Shader shader;
        shader.Compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
        return shader;
    }

    Texture2D SceneAssets::loadTextureFromFile(const char* file, bool alpha)
    {
        // create texture object
        Texture2D texture;
        if (alpha)
        {
            texture.Internal_Format = GL_RGBA;
            texture.Image_Format = GL_RGBA;
        }
        // load image
        int width, height, nrChannels;
        unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);
        // now generate texture
        texture.Generate(width, height, data);
        // and finally free image data
        stbi_image_free(data);
        return texture;
    }
}