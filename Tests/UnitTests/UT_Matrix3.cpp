#include "Matrix3.hpp"
#include "Vector3.hpp"
#include "gtest/gtest.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

#include <glm/glm.hpp>

namespace Maths
{
    bool MatricesAreEqual(Matrix3& mat1, glm::mat3& mat2, float tolerance = 1e-6f)
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (std::abs(mat1.mat[i][j] - mat2[i][j]) > tolerance)
                    return false;
        return true;
    }

    float trace(glm::mat3& mat)
    {
        return mat[0][0] + mat[1][1] + mat[2][2];
    }

    TEST(Matrix3, ConstructorWithScalar)
    {
        float scalar = 3.0f;
        Matrix3 mat3(scalar);
        glm::mat3 glmMat3(scalar);

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                EXPECT_FLOAT_EQ(mat3.mat[i][j], glmMat3[i][j]);
            }
        }
    }

    TEST(Matrix3, ConstructorWithArray)
    {
        std::array<std::array<float, 3>, 3> array = {{{1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}, {7.0f, 8.0f, 9.0f}}};
        Matrix3 mat3(array);
        glm::mat3 glmMat3 = glm::mat3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);

        EXPECT_TRUE(MatricesAreEqual(mat3, glmMat3));
    }

    TEST(Matrix3, ConstructorWithVectors)
    {
        Vector3 v1(1.0f, 2.0f, 3.0f);
        Vector3 v2(4.0f, 5.0f, 6.0f);
        Vector3 v3(7.0f, 8.0f, 9.0f);
        Matrix3 mat3(v1, v2, v3);
        glm::mat3 glmMat3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);

        EXPECT_TRUE(MatricesAreEqual(mat3, glmMat3));
    }

    TEST(Matrix3, AddScalar)
    {
        float scalar = 1.0f;
        Matrix3 mat3(1.0f);
        Matrix3 result = mat3 + scalar;
        glm::mat3 glmMat3 = glm::mat3(1.0f) + scalar;

        EXPECT_TRUE(MatricesAreEqual(result, glmMat3));
    }

    TEST(Matrix3, AddMatrix)
    {
        Matrix3 mat1(1.0f);
        Matrix3 mat2(2.0f);
        Matrix3 result = mat1 + mat2;
        glm::mat3 glmMat3 = glm::mat3(3.0f);

        EXPECT_TRUE(MatricesAreEqual(result, glmMat3));
    }

    TEST(Matrix3, SubtractScalar)
    {
        float scalar = 1.0f;
        Matrix3 mat3(3.0f);
        Matrix3 result = mat3 - scalar;
        glm::mat3 glmMat3 = glm::mat3(3.0f) - scalar;

        EXPECT_TRUE(MatricesAreEqual(result, glmMat3));
    }

    TEST(Matrix3, SubtractMatrix)
    {
        Matrix3 mat1(3.0f);
        Matrix3 mat2(1.0f);
        Matrix3 result = mat1 - mat2;
        glm::mat3 glmMat3 = glm::mat3(2.0f);

        EXPECT_TRUE(MatricesAreEqual(result, glmMat3));
    }

    TEST(Matrix3, MultiplyScalar)
    {
        float scalar = 2.0f;
        Matrix3 mat3(1.0f);
        Matrix3 result = mat3 * scalar;
        glm::mat3 glmMat3 = glm::mat3(2.0f);

        EXPECT_TRUE(MatricesAreEqual(result, glmMat3));
    }

    TEST(Matrix3, MultiplyMatrix)
    {
        Matrix3 mat1(1.0f);
        Matrix3 mat2(2.0f);
        Matrix3 result = mat1 * mat2;

        glm::mat3 glmMat1 = glm::mat3(1.0f);
        glm::mat3 glmMat2 = glm::mat3(2.0f);
        glm::mat3 glmResult = glmMat1 * glmMat2;

        EXPECT_TRUE(MatricesAreEqual(result, glmResult));
    }

    TEST(Matrix3, DivideScalar)
    {
        float scalar = 2.0f;
        Matrix3 mat3(4.0f);
        Matrix3 result = mat3 / scalar;
        glm::mat3 glmMat3 = glm::mat3(2.0f);

        EXPECT_TRUE(MatricesAreEqual(result, glmMat3));
    }

    TEST(Matrix3, Opposite)
    {
        Matrix3 mat3(1.0f);
        Matrix3 result = mat3.Opposite();
        glm::mat3 glmMat3 = glm::mat3(-1.0f);

        EXPECT_TRUE(MatricesAreEqual(result, glmMat3));
    }

    TEST(Matrix3, Transpose)
    {
        Matrix3 mat3(Vector3(1.0f, 2.0f, 3.0f), Vector3(4.0f, 5.0f, 6.0f), Vector3(7.0f, 8.0f, 9.0f));
        Matrix3 result = mat3.Transpose();
        glm::mat3 glmMat3 = transpose(glm::mat3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f));

        EXPECT_TRUE(MatricesAreEqual(result, glmMat3));
    }

    TEST(Matrix3, Trace)
    {
        Matrix3 mat3(Vector3(1.0f, 2.0f, 3.0f), Vector3(4.0f, 5.0f, 6.0f), Vector3(7.0f, 8.0f, 9.0f));
        float result = mat3.Trace();

        glm::mat3 glmMat = glm::mat3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);

        float glmResult = trace(glmMat);

        EXPECT_FLOAT_EQ(result, glmResult);
    }
}
