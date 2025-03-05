#include "Matrix4.hpp"
#include "Vector3.hpp"
#include "gtest/gtest.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

#include <glm/glm.hpp>

namespace Maths
{
    bool MatricesAreEqual(Matrix4& mat1, glm::mat4& mat2, float tolerance = 1e-6f)
    {
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				if (std::abs(mat1.mat[i][j] - mat2[i][j]) > tolerance)
					return false;
		return true;
    }

    float trace(glm::mat4& mat)
    {
        return mat[0][0] + mat[1][1] + mat[2][2] + mat[3][3];
    }

    TEST(Matrix4, ConstructorWithScalar)
    {
        float scalar = 4.0f;
        Matrix4 mat4(scalar);
        glm::mat4 glmMat4(scalar);

        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                EXPECT_FLOAT_EQ(mat4.mat[i][j], glmMat4[i][j]);
            }
        }
    }

    TEST(Matrix4, ConstructorWithArray)
    {
        std::array<std::array<float, 4>, 4> array = {{{1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f}, {9.0f, 10.0f, 11.0f, 12.f}, {13.0f, 14.0f, 15.0f, 16.0f}}};
        Matrix4 mat4(array);
        glm::mat4 glmMat4 = glm::mat4(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.f, 13.0f, 14.0f, 15.0f, 16.0f);

        EXPECT_TRUE(MatricesAreEqual(mat4, glmMat4));
    }

    TEST(Matrix4, ConstructorWithVectors)
    {
        Vector4 v1(1.0f, 2.0f, 3.0f, 4.0f);
        Vector4 v2(5.0f, 6.0f, 7.0f, 8.0f);
        Vector4 v3(9.0f, 10.0f, 11.0f, 12.f);
        Vector4 v4(13.0f, 14.0f, 15.0f, 16.0f);
        Matrix4 mat4(v1, v2, v3, v4);
        glm::mat4 glmMat4(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.f, 13.0f, 14.0f, 15.0f, 16.0f);

        EXPECT_TRUE(MatricesAreEqual(mat4, glmMat4));
    }

    TEST(Matrix4, AddScalar)
    {
        float scalar = 1.0f;
        Matrix4 mat4(1.0f);
        Matrix4 result = mat4 + scalar;
        glm::mat4 glmMat4 = glm::mat4(1.0f) + scalar;

        EXPECT_TRUE(MatricesAreEqual(result, glmMat4));
    }

    TEST(Matrix4, AddMatrix)
    {
        Matrix4 mat1(1.0f);
        Matrix4 mat2(2.0f);
        Matrix4 result = mat1 + mat2;
        glm::mat4 glmMat4 = glm::mat4(3.0f);

        EXPECT_TRUE(MatricesAreEqual(result, glmMat4));
    }

    TEST(Matrix4, SubtractScalar)
    {
        float scalar = 1.0f;
        Matrix4 mat4(4.0f);
        Matrix4 result = mat4 - scalar;
        glm::mat4 glmMat4 = glm::mat4(3.0f) - scalar;

        EXPECT_TRUE(MatricesAreEqual(result, glmMat4));
    }

    TEST(Matrix4, SubtractMatrix)
    {
        Matrix4 mat1(3.0f);
        Matrix4 mat2(1.0f);
        Matrix4 result = mat1 - mat2;
        glm::mat4 glmMat4 = glm::mat4(2.0f);

        EXPECT_TRUE(MatricesAreEqual(result, glmMat4));
    }

    TEST(Matrix4, MultiplyScalar)
    {
        float scalar = 2.0f;
        Matrix4 mat4(1.0f);
        Matrix4 result = mat4 * scalar;
        glm::mat4 glmMat4 = glm::mat4(2.0f);

        EXPECT_TRUE(MatricesAreEqual(result, glmMat4));
    }

    TEST(Matrix4, MultiplyMatrix)
    {
        Matrix4 mat1(1.0f);
        Matrix4 mat2(2.0f);
        Matrix4 result = mat1 * mat2;

        glm::mat4 glmMat1 = glm::mat4(1.0f);
        glm::mat4 glmMat2 = glm::mat4(2.0f);
        glm::mat4 glmResult = glmMat1 * glmMat2;

        EXPECT_TRUE(MatricesAreEqual(result, glmResult));
    }

    TEST(Matrix4, DivideScalar)
    {
        float scalar = 2.0f;
        Matrix4 mat4(4.0f);
        Matrix4 result = mat4 / scalar;
        glm::mat4 glmMat4 = glm::mat4(2.0f);

        EXPECT_TRUE(MatricesAreEqual(result, glmMat4));
    }

    TEST(Matrix4, Opposite)
    {
        Matrix4 mat4(1.0f);
        Matrix4 result = mat4.Opposite();
        glm::mat4 glmMat4 = glm::mat4(-1.0f);

        EXPECT_TRUE(MatricesAreEqual(result, glmMat4));
    }

    TEST(Matrix4, Transpose)
    {
        Matrix4 mat4(Vector4(1.0f, 2.0f, 3.0f, 4.0f), Vector4(5.0f, 6.0f, 7.0f, 8.0f), Vector4(9.0f, 10.0f, 11.0f, 12.0f), Vector4(13.0f, 14.0f, 15.0f, 16.0f));
        Matrix4 result = mat4.Transpose();
        glm::mat4 glmMat4 = transpose(glm::mat4(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f));

        EXPECT_TRUE(MatricesAreEqual(result, glmMat4));
    }

    TEST(Matrix4, Trace)
    {
        Matrix4 mat4(Vector4(1.0f, 2.0f, 3.0f, 4.0f), Vector4(5.0f, 6.0f, 7.0f, 8.0f), Vector4(9.0f, 10.0f, 11.0f, 12.0f), Vector4(13.0f, 14.0f, 15.0f, 16.0f));
        float result = mat4.Trace();

        glm::mat4 glmMat = glm::mat4(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.f, 13.0f, 14.0f, 15.0f, 16.0f);

        float glmResult = trace(glmMat);

        EXPECT_FLOAT_EQ(result, glmResult);
    }
}
