#include "generationTransform.hpp"
#include <cstdlib>

Transform createTransform(const Transform &window) {
    int randomscenar = static_cast<int>(std::rand() % 4);
    Vector2 minbound = window.get_min_bound();
    Vector2 maxbound = window.get_max_bound();
    Vector2 result;
    switch (randomscenar)
    {
        
    case 0:
        result.x=minbound.x+ static_cast<float>(std::rand() % (int(window.size.x)+1)-1);
        result.y = minbound.y;
        break;
    case 1:
        result.x = minbound.x;
        result.y = maxbound.y-static_cast<float>(std::rand() % (int(window.size.y)+1)-1);
        break;
    case 2:
        result.x = window.size.x;
        result.y = minbound.y;
        break;
    case 3:
        result.x = window.size.x;
        result.y = minbound.y;
        break;
        }

    Transform transform = {
                .position = {result.x, result.y},
                .size={5.0f,5.0f}
    };

    return transform;
}