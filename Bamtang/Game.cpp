#include "Game.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include <iostream>

// Game-related State data
SpriteRenderer* Renderer;



Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
    delete Renderer;
}

void Game::Init()
{
    // load shaders
    ResourceManager::LoadShader("Assets/Shaders/sprite.vert", "Assets/Shaders/sprite.frag", nullptr, "sprite");
    // configure shaders
    Math::Matrix projection = Math::Matrix();
    projection.identity();
    projection = Math::Matrix::ortho(Math::Matrix::identity(),0.0f, static_cast<float>(this->Width),
        0.0f, static_cast<float>(this->Height), -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Shader myShader = ResourceManager::GetShader("sprite");
    Renderer = new SpriteRenderer(myShader);
    // load textures
    ResourceManager::LoadTexture("Assets/Sprites/background.jpg", false, "background");
    ResourceManager::LoadTexture("Assets/Sprites/ball.png", true, "ball");
    ResourceManager::LoadTexture("Assets/Sprites/paddle.png", true, "paddle");
    // configure game objects


}

void Game::Update(float dt)
{

}

void Game::ProcessInput(float dt)
{

}

void Game::Render()
{

    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    time = currentFrame - startFrame;



    if (this->State == GAME_ACTIVE)
    {
        // draw background
        Texture2D myTexture = ResourceManager::GetTexture("background");
        Renderer->DrawSprite(myTexture, Math::Vector(0.0f, 0.0f), Math::Vector(this->Width, this->Height), 0.0f);

    }
}