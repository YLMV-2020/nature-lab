/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <GL/glew.h>
#include "../Math/Math.h"
#include "../Math/Vector.h"
#include "../Math/Matrix.h"
#include "../Math/transformation.h"

#include "Texture2D.h"
#include "SpriteRenderer.h"


// Container object for holding all state relevant for a single
// game object entity. Each object in the game likely needs the
// minimal of state as described within GameObject.
class GameObject
{
public:
    // object state
    Math::Vector Position, Size, Velocity;
    Math::Vector   Color;
    float       Rotation;
    bool        IsSolid;
    bool        Destroyed;
    // render state
    Texture2D   Sprite;
    // constructor(s)
    GameObject();
    GameObject(Math::Vector pos, Math::Vector size, Texture2D sprite, Math::Vector color = Math::Vector(1.0f), Math::Vector velocity = Math::Vector(0.0f));
    // draw sprite
    virtual void Draw(SpriteRenderer& renderer);
};

#endif