#pragma once

namespace NatureLab {
    class VectorV1Nature : public INature {
    public:
        inline VectorV1Nature() {
            this->start();
        }

        inline void start() {
            SceneAssets::loadShader("Assets/Shaders/sprite.vert", "Assets/Shaders/sprite.frag", nullptr, "sprite");

            glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(1080),
                0.0f, static_cast<float>(720), -1.0f, 1.0f);

            SceneAssets::getShader("sprite").Use().SetInteger("image", 0);
            SceneAssets::getShader("sprite").SetMatrix4("projection", projection);

            Shader myShader = SceneAssets::getShader("sprite");
            this->sprite = new NatureLab::Sprite(myShader);


            SceneAssets::loadTexture("Assets/Sprites/background.jpg", false, "background");
            SceneAssets::loadTexture("Assets/Sprites/ball.png", true, "ball");
            SceneAssets::loadTexture("Assets/Sprites/paddle.png", true, "paddle");
        }

        inline void update() {

            float currentFrame = glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;
            time = currentFrame - startFrame;

        }

        inline void show()
        {
            Texture2D myTexture = SceneAssets::getTexture("background");
            sprite->draw(myTexture, glm::vec2(0.0f, 0.0f), glm::vec2(1080, 720), 0.0f);

            Texture2D myTexture2 = SceneAssets::getTexture("ball");
            sprite->draw(myTexture2, glm::vec2(0.0f, 0.0f), glm::vec2(50, 50), 0.0f);
        }

    private:

        NatureLab::Sprite* sprite;
        float deltaTime = 0.0f;
        float lastFrame = 0.0f;
        float time = 0.0f;
        float startFrame = glfwGetTime();

    };
}