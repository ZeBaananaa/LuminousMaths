#include "Vector3.hpp"

#include <iostream>

#include "Utils.hpp"

namespace Maths
{
	Vector3 Vector3::Zero = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 Vector3::One = Vector3(1.0f, 1.0f, 1.0f);
	Vector3 Vector3::XAxis = Vector3(1.0f, 0.0f, 0.0f);
	Vector3 Vector3::YAxis = Vector3(0.0f, 1.0f, 0.0f);
	Vector3 Vector3::ZAxis = Vector3(0.0f, 0.0f, 1.0f);

	Vector3::Vector3(const float& a_a, const float& a_b, const float& a_c)
	{
		x = a_a;
		y = a_b;
		z = a_c;
	}

	Vector3 Vector3::Add(const Vector3& a_v) const
	{
		return Vector3(x + a_v.x, y + a_v.y, z + a_v.z);
	}

	Vector3 Vector3::Add(const float& a_a) const
	{
		return Vector3(x + a_a, y + a_a, z + a_a);
	}

	Vector3 Vector3::Subtract(const Vector3& a_v) const
	{
		return Vector3(x - a_v.x, y - a_v.y, z - a_v.z);
	}

	Vector3 Vector3::Subtract(const float& a_a) const
	{
		return Vector3(x - a_a, y - a_a, z - a_a);
	}

	Vector3 Vector3::Product(const Vector3& a_v) const
	{
		return Vector3(x * a_v.x, y * a_v.y, z * a_v.z);
	}

	Vector3 Vector3::Product(const float& a_a) const
	{
		return Vector3(x * a_a, y * a_a, z * a_a);;
	}

	Vector3 Vector3::Invert() const
	{
		return Vector3(1 / x, 1 / y, 1 / z);
	}

	float Vector3::Length() const
	{
		return Maths::Sqrt((x * x) + (y * y) + (z * z));
	}

	Vector3 Vector3::Normalize() const
	{
		return Vector3(x / Length(), y / Length(), z / Length());
	}

	float Vector3::DotProduct(const Vector3& a_v) const
	{
		return ((x * a_v.x) + (y * a_v.y) + (z * a_v.z));
	}

	Vector3 Vector3::CrossProduct(const Vector3& a_v) const
	{
		return (Vector3((y * a_v.z) - (z * a_v.y), (z * a_v.x) - (x * a_v.z), (x * a_v.y) - (y * a_v.x)));
	}

	void Vector3::Print() const
	{
		std::cout << x << ", " << y << ", " << z << '\n';
	}

	Vector3 Vector3::operator+(const float& a_a) const
	{
		return Add(a_a);
	}

	Vector3 Vector3::operator+(const Vector3& a_v) const
	{
		return Add(a_v);
	}

	Vector3 Vector3::operator-(const float& a_a) const
	{
		return Subtract(a_a);
	}

	Vector3 Vector3::operator-(const Vector3& a_v) const
	{
		return Subtract(a_v);
	}

	Vector3 Vector3::operator*(const float& a_a) const
	{
		return Product(a_a);
	}

	Vector3 Vector3::operator*(const Vector3& a_v) const
	{
		return Product(a_v);
	}

	Vector3 Vector3::operator/(const float& a_a) const
	{
		return Product(1 / a_a);
	}

	Vector3 Vector3::operator/(const Vector3& a_v) const
	{
		return Product(a_v.Invert());
	}

	void Vector3::operator+=(const float& a_a)
	{
		x += a_a;
		y += a_a;
		z += a_a;
	}

	void Vector3::operator+=(const Vector3& a_v)
	{
		x += a_v.x;
		y += a_v.y;
		z += a_v.z;
	}

	void Vector3::operator*=(const float& a_a)
	{
		x *= a_a;
		y *= a_a;
		z *= a_a;
	}

	void Vector3::operator*=(const Vector3& a_v)
	{
		x *= a_v.x;
		y *= a_v.y;
		z *= a_v.z;
	}

	void Vector3::operator-=(const float& a_a)
	{
		x -= a_a;
		y -= a_a;
		z -= a_a;
	}

	void Vector3::operator-=(const Vector3& a_v)
	{
		x -= a_v.x;
		y -= a_v.y;
		z -= a_v.z;
	}

	void Vector3::operator/=(const float& a_a)
	{
		x /= a_a;
		y /= a_a;
		z /= a_a;
	}

	void Vector3::operator/=(const Vector3& a_v)
	{
		x /= a_v.x;
		y /= a_v.y;
		z /= a_v.z;
	}

	bool Vector3::operator==(const float& a_a) const
	{
		return x == a_a && y == a_a && z == a_a;
	}

	bool Vector3::operator==(const Vector3& a_v) const
	{
		return x == a_v.x && y == a_v.y && z == a_v.z;
	}

	bool Vector3::operator!=(const float& a_a) const
	{
		return !(x == a_a && y == a_a && z == a_a);
	}

	bool Vector3::operator!=(const Vector3& a_v) const
	{
		return !(x == a_v.x && y == a_v.y && z == a_v.z);
	}

	float Vector3::operator[](const int& a_a) const
	{
		switch (a_a)
		{
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			default:
				return 0.f;
		}
	}
}
