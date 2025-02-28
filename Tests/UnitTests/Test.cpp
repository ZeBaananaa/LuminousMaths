#include "Test.hpp"
#include "gtest/gtest.h"

// Définition de la fonction add
int add(int a, int b)
{
    return a + b;
}

// Test unitaire de la fonction add
TEST(AddTest, PositiveNumbers)
{
    EXPECT_EQ(add(1, 2), 3); // Teste l'addition de 1 et 2
}

TEST(AddTest, NegativeNumbers)
{
    EXPECT_EQ(add(-1, -2), -3); // Teste l'addition de -1 et -2
}

TEST(AddTest, MixedNumbers)
{
    EXPECT_EQ(add(-1, 2), 1); // Teste l'addition de -1 et 2
}

TEST(AddTest, Zero)
{
    EXPECT_EQ(add(0, 0), 0); // Teste l'addition de 0 et 0
}
