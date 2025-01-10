#include "generationMotion.hpp"
#include <cstdlib>

Motion createMotion() {
    float randomDirX = static_cast<float>(std::rand() % 200 - 100) / 100.0f;
    float randomDirY = static_cast<float>(std::rand() % 200 - 100) / 100.0f;
    Motion motion = {
    .direction_normalized = {randomDirX, randomDirY},
    .speed = 5.0f
    };
    return motion;
}