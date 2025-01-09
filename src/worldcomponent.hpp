#pragma once
struct Vec2
{
    float x;
    float y;
};

struct Motion
{
    Vec2 direction_normalized;
    float speed;
};

struct Transform
{
    Vec2 position;
    float heightRadius;
    float widthRadius;
};

void update_position(const Motion& motion, Transform& transform, float deltatime);
