namespace NatureLab
{
    class Sprite
    {
    public:
        Sprite(Shader& shader)
        {
            this->_shader = shader;
            this->initRenderData();
        }

        ~Sprite()
        {
            glDeleteVertexArrays(1, &this->quadVAO);
        }

        void draw(Texture2D& texture, Math::Vector position, Math::Vector size = Math::Vector(10.0f, 10.0f), float rotate = 0.0f, Math::Vector color = Math::Vector(1.0f))
        {
            this->_shader.Use();
            Math::Matrix model = Math::Matrix();
            model.identity();

            Math::Matrix a = Math::Matrix::translate(Math::Matrix::identity(), position);  
            Math::Matrix b = Math::Matrix::translate(Math::Matrix::identity(), Math::Vector(0.5f * size.x, 0.5f * size.y, 0.0f)); 
            
            Math::Matrix c = Math::Matrix::rotationAroundZ(Math::Matrix::identity(), Math::radians(rotate)); 
            Math::Matrix d = Math::Matrix::translate(Math::Matrix::identity(), Math::Vector(-0.5f * size.x, -0.5f * size.y, 0.0f)); 

            Math::Matrix e = Math::Matrix::scale(Math::Matrix::identity(), Math::Vector(size)); // last scale

            model = e * d * c * b * a;

          /*  model =
                Math::Matrix::translate(Math::Matrix::identity(), position) *
                Math::Matrix::translate(Math::Matrix::identity(), Math::Vector(0.5f * size.x, 0.5f * size.y, 0.0f)) *
                Math::Matrix::rotationAroundZ(Math::Matrix::identity(), Math::radians(rotate)) *
                Math::Matrix::translate(Math::Matrix::identity(), Math::Vector(-0.5f * size.x, -0.5f * size.y, 0.0f)) *
                Math::Matrix::scale(Math::Matrix::identity(), Math::Vector(size));*/

            this->_shader.SetMatrix4("model", model);
            this->_shader.SetVector3f("spriteColor", color);

            glActiveTexture(GL_TEXTURE0);
            texture.Bind();

            glBindVertexArray(this->quadVAO);
            glDrawArrays(GL_TRIANGLES, 0, 6);
            glBindVertexArray(0);
        }

        void initRenderData()
        {
            unsigned int VBO;
            float vertices[] = {
                // pos      // tex
                0.0f, 1.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 0.0f,

                0.0f, 1.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 0.0f, 1.0f, 0.0f
            };

            glGenVertexArrays(1, &this->quadVAO);
            glGenBuffers(1, &VBO);

            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            glBindVertexArray(this->quadVAO);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
        }
    private:

        Shader _shader;
        unsigned int quadVAO;
    };
}