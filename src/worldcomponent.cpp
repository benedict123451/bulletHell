#include "worldcomponent.hpp"

void update_position(const Motion& motion, Transform& transform, float deltaTime) {
    transform.position.x += motion.direction_normalized.x * motion.speed * deltaTime;
    transform.position.y += motion.direction_normalized.y * motion.speed * deltaTime;
}
