#include "pch.h"
#include "Vector3.h"
#include "Utils.h"

namespace Math
{

	Vector3 Vector3::zero = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 Vector3::one = Vector3(1.0f, 1.0f, 1.0f);
	Vector3 Vector3::xAxis = Vector3(1.0f, 0.0f, 0.0f);
	Vector3 Vector3::yAxis = Vector3(0.0f, 1.0f, 0.0f);
	Vector3 Vector3::zAxis = Vector3(0.0f, 0.0f, 1.0f);

	Vector3::Vector3(float a_a, float a_b, float a_c)
	{
		x = a_a;
		y = a_b;
		z = a_c;
	}

	Vector3 Vector3::Add(Vector3 a_v)
	{
		return Vector3(x + a_v.x, y + a_v.y, z + a_v.z);
	}

	Vector3 Vector3::Add(float a_a)
	{
		return Vector3(x + a_a, y + a_a, z + a_a);
	}

	Vector3 Vector3::Substract(Vector3 a_v)
	{
		return Vector3(x - a_v.x, y - a_v.y, z - a_v.z);
	}

	Vector3 Vector3::Substract(float a_a)
	{
		return Vector3(x - a_a, y - a_a, z - a_a);
	}

	Vector3 Vector3::Product(Vector3 a_v)
	{
		return Vector3(x * a_v.x, y * a_v.y, z * a_v.z);
	}

	Vector3 Vector3::Product(float a_a)
	{
		return Vector3(x * a_a, y * a_a, z * a_a);;
	}

	Vector3 Vector3::Invert()
	{
		return Vector3(1 / x, 1 / y, 1 / z);
	}

	float Vector3::Length()
	{
		return Math::Sqrt((x * x) + (y * y) + (z * z));
	}

	Vector3 Vector3::Normalize()
	{
		return Vector3(x / Length(), y / Length(), z / Length());
	}

	float Vector3::DotProduct(Vector3 a_v)
	{
		return ((x * a_v.x) + (y * a_v.y) + (z * a_v.z));
	}

	Vector3 Vector3::CrossProduct(Vector3 a_v)
	{
		return (Vector3((y*a_v.z) - (z * a_v.y), (z * a_v.x) - (x * a_v.z), (x * a_v.y) - (y * a_v.x)));
	}

	void Vector3::Print()
	{
		std::cout << x << ", " << y << ", " << z << '\n';
	}

	Vector3 Vector3::operator+(const float a_a)
	{
		return Add(a_a);
	}

	Vector3 Vector3::operator+(const Vector3& a_v)
	{
		return Add(a_v);
	}

	Vector3 Vector3::operator-(const float a_a)
	{
		return Substract(a_a);
	}

	Vector3 Vector3::operator-(Vector3& a_v)
	{
		return Substract(a_v);
	}

	Vector3 Vector3::operator*(const float a_a)
	{
		return Product(a_a);
	}

	Vector3 Vector3::operator*(const Vector3& a_v)
	{
		return Product(a_v);
	}

	Vector3 Vector3::operator/(const float a_a)
	{
		return Product(1 / a_a);
	}

	Vector3 Vector3::operator/(Vector3& a_v)
	{
		return Product(a_v.Invert());
	}

	void Vector3::operator+=(const float a_a)
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

	void Vector3::operator*=(const float a_a)
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

	void Vector3::operator-=(const float a_a)
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

	void Vector3::operator/=(const float a_a)
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

	bool Vector3::operator==(const float a_a)
	{
		return (x == a_a && y == a_a && z == a_a);
	}

	bool Vector3::operator==(const Vector3 a_v)
	{
		return (x == a_v.x && y == a_v.y && z == a_v.z);
	}

	bool Vector3::operator!=(const float a_a)
	{
		return !(x == a_a && y == a_a && z == a_a);
	}

	bool Vector3::operator!=(const Vector3 a_v)
	{
		return !(x == a_v.x && y == a_v.y && z == a_v.z);
	}

	float Vector3::operator[](const int a_a)
	{
		switch(a_a)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			break;
		}

	}

}