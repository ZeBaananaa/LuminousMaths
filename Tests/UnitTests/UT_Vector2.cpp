#include "Vector2.hpp"
#include "gtest/gtest.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

#include <glm/glm.hpp>

namespace Maths
{
    class Vector2;

    bool VectorsAreEqual(Vector2& vec1, glm::vec2& vec2)
    {
        if (vec1.x != vec2.x || vec1.y != vec2.y)
            return false;

        return true;
    }

    float trace(glm::vec2& vec)
    {
        return vec.x + vec.y;
    }

    TEST(Vector2, ConstructorOneFloat)
    {
        float scalar = 3.0f;
        Vector2 vec1(scalar);
        glm::vec2 vec2(scalar);

        EXPECT_TRUE(VectorsAreEqual(vec1, vec2));
    }

    TEST(Vector2, ConstructorTwoFloats)
    {
        float val1 = 3.0f;
        float val2 = 8.0f;
        Vector2 vec1(val1, val2);
        glm::vec2 vec2(val1, val2);

        EXPECT_TRUE(VectorsAreEqual(vec1, vec2));
    }

    TEST(Vector2, AddScalarOperator)
    {
        float scalar = 1.0f;
        Vector2 vec1(1.0f);
        Vector2 result = vec1 + scalar;
        glm::vec2 vec2 = glm::vec2(1.0f) + scalar;

        EXPECT_TRUE(VectorsAreEqual(result, vec2));
    }

    TEST(Vector2, AddVectorOperator)
    {
        Vector2 vec1(1.0f);
        Vector2 vec2(2.0f);
        Vector2 result = vec1 + vec2;

        glm::vec2 vec3 = glm::vec2(1.0f);
        glm::vec2 vec4 = glm::vec2(2.0f);
        glm::vec2 gResult = vec3 + vec4;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector2, AddScalarFunc)
    {
        float scalar = 1.0f;
        Vector2 vec1(1.0f);
        Vector2 result = vec1.Add(scalar);
        glm::vec2 vec2 = glm::vec2(1.0f) + scalar;

        EXPECT_TRUE(VectorsAreEqual(result, vec2));
    }

    TEST(Vector2, AddVectorFunc)
    {
        Vector2 vec1(1.0f);
        Vector2 vec2(2.0f);
        Vector2 result = vec1.Add(vec2);

        glm::vec2 vec3 = glm::vec2(1.0f);
        glm::vec2 vec4 = glm::vec2(2.0f);
        glm::vec2 gResult = vec3 + vec4;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector2, SubtractScalarOperator)
    {
        float scalar = 1.f;
        Vector2 vec1(3.0f);
        Vector2 result = vec1 - scalar;

        glm::vec2 vec3 = glm::vec2(3.0f);
        glm::vec2 gResult = vec3 - scalar;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector2, SubtractScalarFunc)
    {
        float scalar = 1.f;
        Vector2 vec1(3.0f);
        Vector2 result = vec1.Subtract(scalar);

        glm::vec2 vec3 = glm::vec2(3.0f);
        glm::vec2 gResult = vec3 - scalar;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector2, SubtractVectorOperator)
    {
        Vector2 vec1(3.0f);
        Vector2 vec2(5.0f);
        Vector2 result = vec1 - vec2;

        glm::vec2 vec3 = glm::vec2(3.0f);
        glm::vec2 vec4 = glm::vec2(5.0f);
        glm::vec2 gResult = vec3 - vec4;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector2, SubtractVectorFunc)
    {
        Vector2 vec1(3.0f);
        Vector2 vec2(5.0f);
        Vector2 result = vec1.Subtract(vec2);

        glm::vec2 vec3 = glm::vec2(3.0f);
        glm::vec2 vec4 = glm::vec2(5.0f);
        glm::vec2 gResult = vec3 - vec4;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector2, ProductScalarOperator)
    {
        float scalar = 3.f;;
        Vector2 vec1(5.0f);
        Vector2 result = vec1 * scalar;

        glm::vec2 vec2 = glm::vec2(5.0f);
        glm::vec2 gResult = vec2 * scalar;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector2, ProductScalarFunc)
    {
        float scalar = 3.f;;
        Vector2 vec1(5.0f);
        Vector2 result = vec1.Product(scalar);

        glm::vec2 vec2 = glm::vec2(5.0f);
        glm::vec2 gResult = vec2 * scalar;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector2, ProductVectorOperator)
    {
        Vector2 vec1(3.0f);
        Vector2 vec2(5.0f);
        Vector2 result = vec1 * vec2;

        glm::vec2 vec3 = glm::vec2(3.0f);
        glm::vec2 vec4 = glm::vec2(5.0f);
        glm::vec2 gResult = vec3 * vec4;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector2, ProductVectorFunc)
    {
        Vector2 vec1(3.0f);
        Vector2 vec2(5.0f);
        Vector2 result = vec1.Product(vec2);

        glm::vec2 vec3 = glm::vec2(3.0f);
        glm::vec2 vec4 = glm::vec2(5.0f);
        glm::vec2 gResult = vec3 * vec4;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector2, InvertOperator)
    {
        Vector2 vec1(2.0f, 5.0f);
        Vector2 result = Vector2(1.0f / vec1.x, 1.0f / vec1.y);

        glm::vec2 glmVec1 = glm::vec2(2.0f, 5.0f);
        glm::vec2 gResult = 1.0f / glmVec1;


        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector2, InvertFunc)
    {
        Vector2 vec1(2.0f, 5.0f);
        Vector2 result = vec1.Invert();

        glm::vec2 glmVec1 = glm::vec2(2.0f, 5.0f);
        glm::vec2 gResult = 1.0f / glmVec1;


        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector2, Normalize)
    {
        Vector2 vec1(4.0f);
        Vector2 vec2(3.0f);
        Vector2 result = vec1 * vec2;
        result = result.Normalize();

        glm::vec2 v3 = glm::vec2(4.0f);
        glm::vec2 v4 = glm::vec2(3.0f);
        glm::vec2 gResult = v3 * v4;
        gResult = normalize(gResult);

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector2, Length)
    {
        Vector2 vec1(4.0f, 4.0f);
        float result = vec1.Length();

        glm::vec2 vec2 = glm::vec2(4.0f, 4.0f);
        float gResult = length(vec2);

        EXPECT_FLOAT_EQ(result, gResult);
    }

    TEST(Vector2, DotProduct)
    {
        Vector2 vec1(3.0f);
        Vector2 vec2(7.0f);
        float result = vec1.DotProduct(vec2);

        glm::vec2 vec3 = glm::vec2(3.0);
        glm::vec2 vec4 = glm::vec2(7.0);
        float gResult = dot(vec3, vec4);

        EXPECT_FLOAT_EQ(result, gResult);
    }

    TEST(Vector2, Zero)
    {
        Vector2 vec1 = Vector2::Zero;
        glm::vec2 vec2 = glm::vec2(0.f);

        EXPECT_TRUE(VectorsAreEqual(vec1, vec2));
    }

    TEST(Vector2, One)
    {
        Vector2 vec1 = Vector2::One;
        glm::vec2 vec2 = glm::vec2(1.f);

        EXPECT_TRUE(VectorsAreEqual(vec1, vec2));
    }

    TEST(Vector2, xAxis)
    {
        Vector2 vec1 = Vector2::XAxis;
        glm::vec2 vec2 = glm::vec2(1.0f, 0.0f);

        EXPECT_TRUE(VectorsAreEqual(vec1, vec2));
    }

    TEST(Vector2, yAxis)
    {
        Vector2 vec1 = Vector2::YAxis;
        glm::vec2 vec2 = glm::vec2(0.0f, 1.0f);

        EXPECT_TRUE(VectorsAreEqual(vec1, vec2));
    }
}
