namespace Maths
{
    class Vector3;

    class Quaternion
    {
    public:

        float  w{ 1.0f }, x{ 0.0f }, y{ 0.0f }, z{ 0.0f };

        explicit Quaternion() = default;
        explicit Quaternion(float a_x, float a_y, float a_z, float a_w);
        explicit Quaternion(Vector3 a_v);

        Quaternion Add(const Quaternion& a_q) const;
        Quaternion Substract(const Quaternion& a_q) const;
        Quaternion Product(const Quaternion& a_q) const;
        Quaternion Product(const float a_a) const;
        Quaternion Normalize() const;
        Quaternion Conjugate() const;
        Quaternion Opposite() const;
        Vector3 ToEulerAngles() const;

        float Length() const;
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