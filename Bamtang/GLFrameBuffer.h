
namespace NatureLab
{
    class GLFrameBuffer
    {

    private:

        GLuint _framebuffer;
        GLuint _texture;

    public:

        GLFrameBuffer(const int& WIDTH, const int& HEIGHT)
        {
            bind(WIDTH, HEIGHT);
        }

        void bind(const int& WIDTH, const int& HEIGHT)
        {
            glGenFramebuffers(1, &_framebuffer);
            glBindFramebuffer(GL_FRAMEBUFFER, _framebuffer);

            glGenTextures(1, &_texture);
            glBindTexture(GL_TEXTURE_2D, _texture);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, WIDTH, HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _texture, 0);

            unsigned int rbo;
            glGenRenderbuffers(1, &rbo);
            glBindRenderbuffer(GL_RENDERBUFFER, rbo);
            glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, WIDTH, HEIGHT);
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

            if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
                glBindFramebuffer(GL_FRAMEBUFFER, 0);
        }

        const GLuint& update()
        {
            return _framebuffer;
        }

        const GLuint& show()
        {
            return _texture;
        }

    };



}