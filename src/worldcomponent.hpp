#pragma once

struct Vector2
{
    float x;
    float y;
};

struct Motion
{
    Vector2 direction_normalized;
    float speed;
};

struct Transform
{
    Vector2 position;
    Vector2 size{ .x = 1.0f, .y = 1.0f };

    [[nodiscard]] Vector2 get_min_bound() const
    {
        return position;
    }

    [[nodiscard]] Vector2 get_max_bound() const
    {
        return { .x = position.x + size.x, .y = position.y + size.y };
    }
};

[[nodiscard]] inline bool intersects(const Transform& base, const Transform& other)
{
    return base.get_min_bound().x <= other.get_max_bound().x &&
        base.get_max_bound().x >= other.get_min_bound().x &&
        base.get_min_bound().y <= other.get_max_bound().y &&
        base.get_max_bound().y >= other.get_min_bound().y;
}


void update_position(const Motion& motion, Transform& transform, float deltatime);
