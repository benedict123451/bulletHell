#include <gtest/gtest.h>
#include "worldcomponent.hpp"
TEST(BulletHellTest, MovementTest)
{
    // Arrange
    Motion motion = {
        .direction_normalized = {1.f,0.f},
        .speed = 10.0f
    };

    Transform transform = {
        .position = {0.f,0.f}
    };

    // Act
    update_position(motion, transform, 0.016f);
    //Transform.position.x += motion.direction_normalized.x * Motion.speed * deltatime

    // Assert
    //EXPECT_TRUE(0,1 spacePosition.x); std::fabs(a-b)<0.0001f
    //EXPECT_TRUE(0,1 spacePosition.y);
}

// Main function for Google Test
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}