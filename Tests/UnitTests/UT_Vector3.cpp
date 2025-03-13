#include "Vector3.hpp"
#include "gtest/gtest.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

#include <glm/glm.hpp>

namespace Maths
{
   class Vector3;

    bool VectorsAreEqual(Vector3& vec1, glm::vec3& vec2)
    {
        if (vec1.x != vec2.x || vec1.y != vec2.y || vec1.z != vec2.z)
            return false;

        return true;
    }

    float trace(glm::vec3& vec)
    {
        return vec.x + vec.y + vec.z;
    }

    TEST(Vector3, ConstructorOneFloat)
    {
        float scalar = 3.0f;
        Vector3 vec1(scalar);
        glm::vec3 vec2(scalar);

        EXPECT_TRUE(VectorsAreEqual(vec1, vec2));
    }

    TEST(Vector3, ConstructorThreeFloats)
    {
        float val1 = 3.0f;
        float val2 = 8.0f;
        float val3 = 5.0f;
        Vector3 vec1(val1, val2, val3);
        glm::vec3 vec2(val1, val2, val3);

        EXPECT_TRUE(VectorsAreEqual(vec1, vec2));
    }

    TEST(Vector3, AddScalarOperator)
    {
        float scalar = 1.0f;
        Vector3 vec1(1.0f);
        Vector3 result = vec1 + scalar;
        glm::vec3 vec2 = glm::vec3(1.0f) + scalar;

        EXPECT_TRUE(VectorsAreEqual(result, vec2));
    }

    TEST(Vector3, AddVectorOperator)
    {
        Vector3 vec1(1.0f);
        Vector3 vec2(2.0f);
        Vector3 result = vec1 + vec2;

        glm::vec3 vec3 = glm::vec3(1.0f);
        glm::vec3 vec4 = glm::vec3(2.0f);
        glm::vec3 gResult = vec3 + vec4;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector3, AddScalarFunc)
    {
        float scalar = 1.0f;
        Vector3 vec1(1.0f);
        Vector3 result = vec1.Add(scalar);
        glm::vec3 vec2 = glm::vec3(1.0f) + scalar;

        EXPECT_TRUE(VectorsAreEqual(result, vec2));
    }

    TEST(Vector3, AddVectorFunc)
    {
        Vector3 vec1(1.0f);
        Vector3 vec2(2.0f);
        Vector3 result = vec1.Add(vec2);

        glm::vec3 vec3 = glm::vec3(1.0f);
        glm::vec3 vec4 = glm::vec3(2.0f);
        glm::vec3 gResult = vec3 + vec4;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector3, SubtractScalarOperator)
    {
        float scalar = 1.f;
        Vector3 vec1(3.0f);
        Vector3 result = vec1 - scalar;

        glm::vec3 vec3 = glm::vec3(3.0f);
        glm::vec3 gResult = vec3 - scalar;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector3, SubtractScalarFunc)
    {
        float scalar = 1.f;
        Vector3 vec1(3.0f);
        Vector3 result = vec1.Subtract(scalar);

        glm::vec3 vec3 = glm::vec3(3.0f);
        glm::vec3 gResult = vec3 - scalar;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector3, SubtractVectorOperator)
    {
        Vector3 vec1(3.0f);
        Vector3 vec2(5.0f);
        Vector3 result = vec1 - vec2;

        glm::vec3 vec3 = glm::vec3(3.0f);
        glm::vec3 vec4 = glm::vec3(5.0f);
        glm::vec3 gResult = vec3 - vec4;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector3, SubtractVectorFunc)
    {
        Vector3 vec1(3.0f);
        Vector3 vec2(5.0f);
        Vector3 result = vec1.Subtract(vec2);

        glm::vec3 vec3 = glm::vec3(3.0f);
        glm::vec3 vec4 = glm::vec3(5.0f);
        glm::vec3 gResult = vec3 - vec4;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector3, ProductScalarOperator)
    {
        float scalar = 3.f;;
        Vector3 vec1(5.0f);
        Vector3 result = vec1 * scalar;

        glm::vec3 vec2 = glm::vec3(5.0f);
        glm::vec3 gResult = vec2 * scalar;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector3, ProductScalarFunc)
    {
        float scalar = 3.f;;
        Vector3 vec1(5.0f);
        Vector3 result = vec1.Product(scalar);

        glm::vec3 vec2 = glm::vec3(5.0f);
        glm::vec3 gResult = vec2 * scalar;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector3, ProductVectorOperator)
    {
        Vector3 vec1(3.0f);
        Vector3 vec2(5.0f);
        Vector3 result = vec1 * vec2;

        glm::vec3 vec3 = glm::vec3(3.0f);
        glm::vec3 vec4 = glm::vec3(5.0f);
        glm::vec3 gResult = vec3 * vec4;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector3, ProductVectorFunc)
    {
        Vector3 vec1(3.0f);
        Vector3 vec2(5.0f);
        Vector3 result = vec1.Product(vec2);

        glm::vec3 vec3 = glm::vec3(3.0f);
        glm::vec3 vec4 = glm::vec3(5.0f);
        glm::vec3 gResult = vec3 * vec4;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector3, InvertOperator)
    {
        Vector3 vec1(2.0f, 5.0f, 7.0f);
        Vector3 result = Vector3(1.0f / vec1.x, 1.0f / vec1.y, 1.0f / vec1.z);

        glm::vec3 glmVec1 = glm::vec3(2.0f, 5.0f, 7.0f);
        glm::vec3 gResult = 1.0f / glmVec1;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector3, InvertFunc)
    {
        Vector3 vec1(2.0f, 5.0f, 7.0f);
        Vector3 result = vec1.Invert();

        glm::vec3 glmVec1 = glm::vec3(2.0f, 5.0f, 7.0f);
        glm::vec3 gResult = 1.0f / glmVec1;

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector3, Normalize)
    {
        Vector3 vec1(4.0f);
        Vector3 vec2(3.0f);
        Vector3 result = vec1 * vec2;
        result = result.Normalize();

        glm::vec3 v3 = glm::vec3(4.0f);
        glm::vec3 v4 = glm::vec3(3.0f);
        glm::vec3 gResult = v3 * v4;
        gResult = normalize(gResult);

        EXPECT_TRUE(VectorsAreEqual(result, gResult));
    }

    TEST(Vector3, Length)
    {
        Vector3 vec1(4.0f, 4.0f, 4.0f);
        float result = vec1.Length();

        glm::vec3 vec2 = glm::vec3(4.0f, 4.0f, 4.0f);
        float gResult = length(vec2);

        EXPECT_FLOAT_EQ(result, gResult);
    }

    TEST(Vector3, DotProduct)
    {
        Vector3 vec1(3.0f);
        Vector3 vec2(7.0f);
        float result = vec1.DotProduct(vec2);

        glm::vec3 vec3 = glm::vec3(3.0);
        glm::vec3 vec4 = glm::vec3(7.0);
        float gResult = dot(vec3, vec4);

        EXPECT_FLOAT_EQ(result, gResult);
    }

    TEST(Vector3, Zero)
    {
        Vector3 vec1 = Vector3::Zero;
        glm::vec3 vec2 = glm::vec3(0.f);

        EXPECT_TRUE(VectorsAreEqual(vec1, vec2));
    }

    TEST(Vector3, One)
    {
        Vector3 vec1 = Vector3::One;
        glm::vec3 vec2 = glm::vec3(1.f);

        EXPECT_TRUE(VectorsAreEqual(vec1, vec2));
    }

    TEST(Vector3, xAxis)
    {
        Vector3 vec1 = Vector3::XAxis;
        glm::vec3 vec2 = glm::vec3(1.0f, 0.0f, 0.0f);

        EXPECT_TRUE(VectorsAreEqual(vec1, vec2));
    }

    TEST(Vector3, yAxis)
    {
        Vector3 vec1 = Vector3::YAxis;
        glm::vec3 vec2 = glm::vec3(0.0f, 1.0f, 0.0f);

        EXPECT_TRUE(VectorsAreEqual(vec1, vec2));
    }

    TEST(Vector3, zAxis)
    {
        Vector3 vec1 = Vector3::ZAxis;
        glm::vec3 vec2 = glm::vec3(0.0f, 0.0f, 1.0f);

        EXPECT_TRUE(VectorsAreEqual(vec1, vec2));
    }
}
