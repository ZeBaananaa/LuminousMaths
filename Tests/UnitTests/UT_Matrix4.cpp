#include "Matrix4.hpp"
#include "Vector3.hpp"
#include "gtest/gtest.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

#include <glm/glm.hpp>

namespace Maths
{
    bool MatricesAreEqual(const Matrix4& mat1, const glm::mat4& mat2, float tolerance = 1e-6f)
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (std::abs(mat1.mat[i][j] - mat2[i][j]) > tolerance)
                    return false;
        return true;
    }
    void PrintGLM(const glm::mat4& a_mat)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                std::cout << a_mat[i][j] << ", ";
            }
            std::cout << '\n';
        }
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
        EXPECT_TRUE(MatricesAreEqual(mat4, glmMat4));
    }

    TEST(Matrix4, ConstructorWithArray)
    {
        std::array<std::array<float, 4>, 4> array = { {{1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f}, {9.0f, 10.0f, 11.0f, 12.f}, {13.0f, 14.0f, 15.0f, 16.0f}} };
        Matrix4 mat4(array);
        glm::mat4 glmMat4(1.0f);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                glmMat4[i][j] = array[i][j];
        EXPECT_TRUE(MatricesAreEqual(mat4, glmMat4));
    }

    TEST(Matrix4, ConstructorWithVectors)
    {
        std::array<float, 4> col1 = { 1.0f, 2.0f, 3.0f, 4.0f };
        std::array<float, 4> col2 = { 5.0f, 6.0f, 7.0f, 8.0f };
        std::array<float, 4> col3 = { 9.0f, 10.0f, 11.0f, 12.0f };
        std::array<float, 4> col4 = { 13.0f, 14.0f, 15.0f, 16.0f };

        std::array<std::array<float, 4>, 4> matrixData = { col1, col2, col3, col4 };
        Matrix4 mat4(matrixData);

        glm::mat4 glmMat4(1.0f, 2.0f, 3.0f, 4.0f,
            5.0f, 6.0f, 7.0f, 8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            13.0f, 14.0f, 15.0f, 16.0f);

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
        glm::mat4 glmMat4 = glm::mat4(4.0f) - scalar;

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
        Matrix4 mat4({ {{1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f}, {9.0f, 10.0f, 11.0f, 12.0f}, {13.0f, 14.0f, 15.0f, 16.0f}} });
        Matrix4 result = mat4.Transpose();
        glm::mat4 glmMat4(1.0f);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                glmMat4[i][j] = mat4.mat[j][i];
        EXPECT_TRUE(MatricesAreEqual(result, glmMat4));
    }

    TEST(Matrix4, Trace)
    {
        Matrix4 mat4({{{1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 2.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 3.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 4.0f}}});
        float result = mat4.Trace();
        glm::mat4 glmMat(1.0f);
        for (int i = 0; i < 4; ++i)
            glmMat[i][i] = i + 1;
        float glmResult = trace(glmMat);
        EXPECT_FLOAT_EQ(result, glmResult);
    }

    TEST(Matrix4, LookAt)
    {
        glm::vec3 eyeG = { 5.0f,4.0f,2.0f };
        glm::vec3 centerG = { 64.0f,12.2f,7.4f };
        glm::vec3 upG = { 0.0f,0.0f,1.0f };
        glm::mat4 lookG = glm::lookAt(eyeG, centerG, upG);

        Vector3 eyeM = Vector3(5.0f, 4.0f, 2.0f);
        Vector3 centerM = Vector3(64.0f, 12.2f, 7.4f);
        Vector3 upM = Vector3(0.0f, 0.0f, 1.0f);
        Matrix4 lookM = Matrix4::LookAt(eyeM, centerM, upM);

        EXPECT_TRUE(MatricesAreEqual(lookM.Transpose(), lookG));
    }

    TEST(Matrix4, Rotations)
    {
        glm::mat4 matRot = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 1.0f));
        Matrix4 rotatedM = Matrix4::Rotate(Matrix4::identity,90.0f, Vector3(1.0f, 0.0f, 1.0f));
        

        EXPECT_TRUE(MatricesAreEqual(rotatedM, matRot));
    }

    TEST(Matrix4, Perspective)
    {
        
        glm::mat4 perspG = glm::perspective(35.0f,1.0f, 0.1f,100.0f);

        Matrix4 perspM = Matrix4::Perspective(35.0f,1.0f,0.1f,100.0f);

        EXPECT_TRUE(MatricesAreEqual(perspM, perspG));
    }

}
