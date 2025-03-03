#include "gtest/gtest.h"

#define LUMINOUS_MATHS_API __declspec(dllimport)


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
