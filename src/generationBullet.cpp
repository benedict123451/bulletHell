#include "generationBullet.hpp"
#include "generationMotion.hpp"
#include "generationTransform.hpp"

Bullet createBullet(const Transform &windo){
    Bullet bullet = {
            .transform = createTransform(windo),
            .motion = createMotion()
    };
    return bullet;
}