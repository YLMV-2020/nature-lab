#pragma once

namespace nature_lab
{
    class gl_shader
    {
    public:
        unsigned int id{};

        gl_shader()
        {
        }

        gl_shader(const std::string& name)
        {
            const std::string vert_path = "assets/shaders/" + name + ".vert";
            const std::string frag_path = "assets/shaders/" + name + ".frag";
            load(vert_path.c_str(), frag_path.c_str());
        }

        void load(const char* vertex_path, const char* fragment_path)
        {
            // 1. retrieve the vertex/fragment source code from filePath
            std::string vertexCode;
            std::string fragmentCode;
            std::ifstream vShaderFile;
            std::ifstream fShaderFile;
            // ensure ifstream objects can throw exceptions:
            vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            try
            {
                // open files
                vShaderFile.open(vertex_path);
                fShaderFile.open(fragment_path);
                std::stringstream vShaderStream, fShaderStream;
                // read file's buffer contents into streams
                vShaderStream << vShaderFile.rdbuf();
                fShaderStream << fShaderFile.rdbuf();
                // close file handlers
                vShaderFile.close();
                fShaderFile.close();
                // convert stream into string
                vertexCode = vShaderStream.str();
                fragmentCode = fShaderStream.str();
            }
            catch (std::ifstream::failure& e)
            {
                std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " << e.what() << std::endl;
            }
            const char* vShaderCode = vertexCode.c_str();
            const char* fShaderCode = fragmentCode.c_str();

            // 2. compile shaders
            unsigned int vertex, fragment;
            // vertex shader
            vertex = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex, 1, &vShaderCode, NULL);
            glCompileShader(vertex);
            check_compile_errors(vertex, "VERTEX");
            // fragment Shader
            fragment = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragment, 1, &fShaderCode, NULL);
            glCompileShader(fragment);
            check_compile_errors(fragment, "FRAGMENT");
            // shader Program
            id = glCreateProgram();
            glAttachShader(id, vertex);
            glAttachShader(id, fragment);
            glLinkProgram(id);
            check_compile_errors(id, "PROGRAM");
            // delete the shaders as they're linked into our program now and no longer necessary
            glDeleteShader(vertex);
            glDeleteShader(fragment);
        }

        // activate the shader
        // ------------------------------------------------------------------------
        void use() const
        {
            glUseProgram(id);
        }

        // utility uniform functions
        // ------------------------------------------------------------------------
        void set_bool(const std::string& name, const bool value) const
        {
            glUniform1i(glGetUniformLocation(id, name.c_str()), static_cast<int>(value));
        }

        // ------------------------------------------------------------------------
        void set_int(const std::string& name, const int value) const
        {
            glUniform1i(glGetUniformLocation(id, name.c_str()), value);
        }

        // ------------------------------------------------------------------------
        void set_float(const std::string& name, const float value) const
        {
            glUniform1f(glGetUniformLocation(id, name.c_str()), value);
        }

        void set_mat4(const std::string& name, const glxm::mat4& mat4) const
        {
            glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, mat4.val[0]);
        }

    private:
        // utility function for checking shader compilation/linking errors.
        // ------------------------------------------------------------------------
        void check_compile_errors(unsigned int shader, std::string type)
        {
            int success;
            char infoLog[1024];
            if (type != "PROGRAM")
            {
                glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
                if (!success)
                {
                    glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                    std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog <<
                        "\n -- --------------------------------------------------- -- " << std::endl;
                }
            }
            else
            {
                glGetProgramiv(shader, GL_LINK_STATUS, &success);
                if (!success)
                {
                    glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                    std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog <<
                        "\n -- --------------------------------------------------- -- " << std::endl;
                }
            }
        }
    };
}
