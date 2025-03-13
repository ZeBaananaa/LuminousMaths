#pragma once

#include "MathsExport.hpp"

namespace Maths
{
    class Vector3;

    class LUMINOUS_MATHS_API Quaternion
    {
    public:
        float  w{ 1.0f }, x{ 0.0f }, y{ 0.0f }, z{ 0.0f };

        explicit Quaternion() = default;
        ~Quaternion() = default;

        explicit Quaternion(const float& a_x, const float& a_y, const float& a_z, const float& a_w);
        explicit Quaternion(const Vector3& a_v);

        [[nodiscard]] Quaternion Add(const Quaternion& a_q) const;
        [[nodiscard]] Quaternion Subtract(const Quaternion& a_q) const;
        [[nodiscard]] Quaternion Product(const Quaternion& a_q) const;
        [[nodiscard]] Quaternion Product(float a_a) const;
        [[nodiscard]] Quaternion Normalize() const;
        [[nodiscard]] Quaternion Conjugate() const;
        [[nodiscard]] Quaternion Opposite() const;
        [[nodiscard]] Vector3 ToEulerAngles(bool a_toDeg) const;

        [[nodiscard]] float Length() const;
        void Print() const;

        static Quaternion FromEulerAngles(const Vector3& a_v);
        static Quaternion Slerp(const Quaternion& a_q1, const Quaternion& a_q2, float a_t);
        static Quaternion Identity;
        static Quaternion Zero;
        static Quaternion One;

        Quaternion operator+(const Quaternion& a_q) const;
        Quaternion operator-(const Quaternion& a_q) const;
        Quaternion operator*(const float& a_a) const;
        Quaternion operator*(const Quaternion& a_q) const;

        void operator+=(const Quaternion& a_v);
        void operator*=(const float& a_a);
        void operator*=(const Quaternion& a_v);
        void operator-=(const Quaternion& a_v);

        bool operator==(const Quaternion& a_q) const;
        bool operator!=(const Quaternion& a_q) const;

    };

}
