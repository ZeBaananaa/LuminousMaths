#include "gtest/gtest.h"

#define LUMINOUS_MATHS_API __declspec(dllimport)


int main(int argc, char** argv)
{
    //testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();

    Maths::Vector3 vec3 = Maths::Vector3(5, 5, 5);
    (vec3+vec3).Print();



    Maths::Quaternion q1 = Maths::Quaternion(0.0f, 0.0f, 0.707f, 0.707f);
    Maths::Quaternion q2 = Maths::Quaternion(0.707f, 0.0f, 0.0f, 0.707f);
    q1.ToEulerAngles().Print();
    Maths::Quaternion q3 = Maths::Quaternion::FromEulerAngles(Maths::Vector3(90, 10, 2));
    //q3.Print();

    Maths::Quaternion q5 = Maths::Quaternion::Slerp(q1, q2, 1.0f);
    q5.Print();

    return 0;
}
