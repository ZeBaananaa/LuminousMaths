#pragma once

namespace Maths
{
	class Vector3
	{
	public:
		float x{0.0f}, y{0.0f}, z{0.0f};

		explicit Vector3() = default;
		explicit Vector3(const float& a_a, const float& a_b, const float& a_c);
		explicit Vector3(const float& a_a);

		Vector3 Add(const Vector3& a_v) const;
		Vector3 Add(const float& a_a) const;
		Vector3 Subtract(const Vector3& a_v) const;
		Vector3 Subtract(const float& a_a) const;
		Vector3 Product(const Vector3& a_v) const;
		Vector3 Product(const float& a_a) const;
		Vector3 Invert() const;
		Vector3 Normalize() const;
		Vector3 CrossProduct(const Vector3& a_v) const;

		float Length() const;
		float DotProduct(const Vector3& a_v) const;

		void Print() const;

		static Vector3 Zero;
		static Vector3 One;
		static Vector3 XAxis;
		static Vector3 YAxis;
		static Vector3 ZAxis;

		Vector3 operator+(const float& a_a) const;
		Vector3 operator+(const Vector3& a_v) const;
		Vector3 operator-(const float& a_a) const;
		Vector3 operator-(const Vector3& a_v) const;
		Vector3 operator*(const float& a_a) const;
		Vector3 operator*(const Vector3& a_v) const;
		Vector3 operator/(const float& a_a) const;
		Vector3 operator/(const Vector3& a_v) const;

		void operator+=(const float& a_a);
		void operator+=(const Vector3& a_v);
		void operator*=(const float& a_a);
		void operator*=(const Vector3& a_v);
		void operator-=(const float& a_a);
		void operator-=(const Vector3& a_v);
		void operator/=(const float& a_a);
		void operator/=(const Vector3& a_v);

		bool operator==(const float& a_a) const;
		bool operator==(const Vector3& a_v) const;
		bool operator!=(const float& a_a) const;
		bool operator!=(const Vector3& a_v) const;

		float operator[](const int& a_a) const;
	};
}
