#include "MathUtils.hpp"
#include "Quaternion.hpp"
#include "Vector3.hpp"
#include "glm/glm.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"
#include "gtest/gtest.h"

namespace Maths
{
    bool QuaternionsEqual(Quaternion quat1, glm::fquat quat2, float tolerance = 1e-5f)
    {
        return ((abs(quat1.x - quat2.x) < tolerance) && (abs(quat1.y - quat2.y) < tolerance) && (
                    abs(quat1.z - quat2.z) < tolerance) && (abs(quat1.w - quat2.w) < tolerance));
    }

    bool VectorsEqual(Vector3 quat1, glm::fvec3 quat2, float tolerance = 1e-5f)
    {
        return ((abs(quat1.x - quat2.x) < tolerance) && (abs(quat1.y - quat2.y) < tolerance) && (
                    abs(quat1.z - quat2.z) < tolerance));
    }

    void PrintGLMVec3(const glm::fvec3& quat, const bool todeg = false)
    {
        if (todeg)
        {
            std::cout << RadToDeg(quat.x) << ", " << RadToDeg(quat.y) << ", " << RadToDeg(quat.z) << '\n';
        } else
        {
            std::cout << quat.x << ", " << quat.y << ", " << quat.z << '\n';
        }
    }

    void PrintGLMQuat(glm::fquat& quat)
    {
        std::cout << quat.w << ", " << quat.x << ", " << quat.y << ", " << quat.z << '\n';
    }

    TEST(Quaternion, FirstTest)
    {
        Quaternion q1 = Quaternion(5.0f, 4.0f, 3.0f, 1.0f);

        glm::fquat q2 = glm::fquat(1.0f, 5.0f, 4.0f, 3.0f);

        EXPECT_TRUE(QuaternionsEqual(q1, q2));
    }

    TEST(Quaternion, Add)
    {
        Quaternion lq1 = Quaternion(5.4f, 4.22f, -3.13f, 1.48f);
        Quaternion lq2 = Quaternion(1.254f, 7.15f, 4.1554f, -1.235f);
        lq1 = lq1 + lq2;

        glm::fquat gq2 = glm::fquat(1.48f, 5.4f, 4.22f, -3.13f);
        glm::fquat gq3 = glm::fquat(-1.235f, 1.254f, 7.15f, 4.1554f);
        gq2 = gq2 + gq3;

        EXPECT_TRUE(QuaternionsEqual(lq1, gq2));
    }

    TEST(Quaternion, Substract)
    {
        Quaternion lq1 = Quaternion(5.4f, 4.22f, -3.13f, 1.48f);
        Quaternion lq2 = Quaternion(1.254f, 7.15f, 4.1554f, -1.235f);
        lq1 = lq1 - lq2;

        glm::fquat gq2 = glm::fquat(1.48f, 5.4f, 4.22f, -3.13f);
        glm::fquat gq3 = glm::fquat(-1.235f, 1.254f, 7.15f, 4.1554f);
        gq2 = gq2 - gq3;

        EXPECT_TRUE(QuaternionsEqual(lq1, gq2));
    }

    TEST(Quaternion, ProductQ)
    {
        Quaternion lq1 = Quaternion(5.4f, 4.22f, -3.13f, 1.48f);
        Quaternion lq2 = Quaternion(1.25f, 7.15f, 4.15f, -1.23f);
        lq1 = lq1 * lq2;

        glm::fquat gq2 = glm::fquat(1.48f, 5.4f, 4.22f, -3.13f);
        glm::fquat gq3 = glm::fquat(-1.23f, 1.25f, 7.15f, 4.15f);
        gq2 = gq2 * gq3;

        EXPECT_TRUE(QuaternionsEqual(lq1, gq2));
    }


    TEST(Quaternion, ProductF)
    {
        Quaternion lq1 = Quaternion(5.4f, 4.22f, -3.13f, 1.48f);
        lq1 = lq1 * 2.0f;

        glm::fquat gq2 = glm::fquat(1.48f, 5.4f, 4.22f, -3.13f);
        gq2 = gq2 * 2.0f;

        EXPECT_TRUE(QuaternionsEqual(lq1, gq2));
    }

    TEST(Quaternion, Length)
    {
        Quaternion lq1 = Quaternion(5.4f, 4.22f, -3.13f, 1.48f);
        glm::fquat gq2 = glm::fquat(1.48f, 5.4f, 4.22f, -3.13f);

        EXPECT_FLOAT_EQ(lq1.Length(), glm::length(gq2));
    }

    TEST(Quaternion, Normalize)
    {
        Quaternion lq1 = Quaternion(5.4f, 4.22f, -3.13f, 1.48f);
        glm::fquat gq2 = glm::fquat(1.48f, 5.4f, 4.22f, -3.13f);

        EXPECT_TRUE(QuaternionsEqual(lq1.Normalize(), glm::normalize(gq2)));
    }

    TEST(Quaternion, Conjugate)
    {
        Quaternion lq1 = Quaternion(5.4f, 4.22f, -3.13f, 1.48f);
        glm::fquat gq2 = glm::fquat(1.48f, 5.4f, 4.22f, -3.13f);

        EXPECT_TRUE(QuaternionsEqual(lq1.Conjugate(), glm::conjugate(gq2)));
    }

    TEST(Quaternion, Opposite)
    {
        Quaternion lq1 = Quaternion(5.4f, 4.22f, -3.13f, 1.48f);
        glm::fquat gq2 = glm::fquat(1.48f, 5.4f, 4.22f, -3.13f);

        EXPECT_TRUE(QuaternionsEqual(lq1.Opposite(), -gq2));
    }

    TEST(Quaternion, ToEulerAngles)
    {
        Quaternion lq1 = Quaternion(5.4f, 4.6f, -3.13f, 1.48f).Normalize();
        glm::fquat gq2 = glm::fquat(1.48f, 5.4f, 4.6f, -3.13f);

        EXPECT_TRUE(VectorsEqual(lq1.ToEulerAngles(false), glm::eulerAngles(glm::normalize(gq2))));
    }

    TEST(Quaternion, FromEulerAngles)
    {
        Quaternion lq2 = Quaternion::FromEulerAngles(Vector3(16.5f, 15, 150));
        glm::fquat q = glm::fquat(glm::vec3(DegToRad(16.5f), DegToRad(15), DegToRad(150)));
        EXPECT_TRUE(QuaternionsEqual(lq2, q));
    }


    TEST(Quaternion, Slerp)
    {
        Quaternion lq1 = Quaternion(5.4f, 4.22f, -3.13f, 1.48f);
        Quaternion lq2 = Quaternion(1.25f, 7.15f, 4.15f, -1.23f);
        Quaternion q3 = Quaternion::Slerp(lq1.Normalize(), lq2.Normalize(), 0.5f);

        glm::fquat gq2 = glm::fquat(1.48f, 5.4f, 4.22f, -3.13f);
        glm::fquat gq3 = glm::fquat(-1.23f, 1.25f, 7.15f, 4.15f);
        glm::fquat gq4 = slerp(normalize(gq2), normalize(gq3), 0.5f);

        EXPECT_TRUE(QuaternionsEqual(q3, gq4));
    }
}
