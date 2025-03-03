#include <glm/glm.hpp>
#include "gtest/gtest.h"
#include "Matrix3.hpp"
#include "Vector3.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

namespace Maths
{
    float trace(const glm::mat3& mat)
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

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                EXPECT_FLOAT_EQ(mat3.mat[i][j], glmMat3[i][j]);
            }
        }
    }

    TEST(Matrix3, ConstructorWithVectors)
    {
        Vector3 v1(1.0f, 2.0f, 3.0f);
        Vector3 v2(4.0f, 5.0f, 6.0f);
        Vector3 v3(7.0f, 8.0f, 9.0f);
        Matrix3 mat3(v1, v2, v3);
        glm::mat3 glmMat3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                EXPECT_FLOAT_EQ(mat3.mat[i][j], glmMat3[i][j]);
            }
        }
    }

    TEST(Matrix3, AddScalar)
    {
        float scalar = 1.0f;
        Matrix3 mat3(1.0f);
        Matrix3 result = mat3 + scalar;
        glm::mat3 glmMat3 = glm::mat3(1.0f) + scalar;

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                EXPECT_FLOAT_EQ(result.mat[i][j], glmMat3[i][j]);
            }
        }
    }

    TEST(Matrix3, AddMatrix)
    {
        Matrix3 mat1(1.0f);
        Matrix3 mat2(2.0f);
        Matrix3 result = mat1 + mat2;
        glm::mat3 glmMat3 = glm::mat3(3.0f);

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                EXPECT_FLOAT_EQ(result.mat[i][j], glmMat3[i][j]);
            }
        }
    }

    TEST(Matrix3, SubtractScalar)
    {
        float scalar = 1.0f;
        Matrix3 mat3(3.0f);
        Matrix3 result = mat3 - scalar;
        glm::mat3 glmMat3 = glm::mat3(3.0f) - scalar;

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                EXPECT_FLOAT_EQ(result.mat[i][j], glmMat3[i][j]);
            }
        }
    }

    TEST(Matrix3, SubtractMatrix)
    {
        Matrix3 mat1(3.0f);
        Matrix3 mat2(1.0f);
        Matrix3 result = mat1 - mat2;
        glm::mat3 glmMat3 = glm::mat3(2.0f);

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                EXPECT_FLOAT_EQ(result.mat[i][j], glmMat3[i][j]);
            }
        }
    }

    TEST(Matrix3, MultiplyScalar)
    {
        float scalar = 2.0f;
        Matrix3 mat3(1.0f);
        Matrix3 result = mat3 * scalar;
        glm::mat3 glmMat3 = glm::mat3(2.0f);

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                EXPECT_FLOAT_EQ(result.mat[i][j], glmMat3[i][j]);
            }
        }
    }

    TEST(Matrix3, MultiplyMatrix)
    {
        Matrix3 mat1(1.0f);
        Matrix3 mat2(2.0f);
        Matrix3 result = mat1 * mat2;

        glm::mat3 glmMat1 = glm::mat3(1.0f);
        glm::mat3 glmMat2 = glm::mat3(2.0f);
        glm::mat3 glmResult = glmMat1 * glmMat2;

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                EXPECT_FLOAT_EQ(result.mat[i][j], glmResult[i][j]);
            }
        }
    }

    TEST(Matrix3, DivideScalar)
    {
        float scalar = 2.0f;
        Matrix3 mat3(4.0f);
        Matrix3 result = mat3 / scalar;
        glm::mat3 glmMat3 = glm::mat3(2.0f);

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                EXPECT_FLOAT_EQ(result.mat[i][j], glmMat3[i][j]);
            }
        }
    }

    TEST(Matrix3, Opposite)
    {
        Matrix3 mat3(1.0f);
        Matrix3 result = mat3.Opposite();
        glm::mat3 glmMat3 = glm::mat3(-1.0f);

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                EXPECT_FLOAT_EQ(result.mat[i][j], glmMat3[i][j]);
            }
        }
    }

    TEST(Matrix3, Transpose)
    {
        Matrix3 mat3(Vector3(1.0f, 2.0f, 3.0f), Vector3(4.0f, 5.0f, 6.0f), Vector3(7.0f, 8.0f, 9.0f));
        Matrix3 result = mat3.Transpose();
        glm::mat3 glmMat3 = transpose(glm::mat3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f));

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                EXPECT_FLOAT_EQ(result.mat[i][j], glmMat3[i][j]);
            }
        }
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
