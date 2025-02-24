#include "pch.h"
#include "Vector2.h"
#include <iostream>
#include "Utils.h"

namespace Math
{

	Vector2 Vector2::zero = Vector2(0.0f, 0.0f);
	Vector2 Vector2::one = Vector2(1.0f, 1.0f);
	Vector2 Vector2::xAxis = Vector2(1.0f, 0.0f);
	Vector2 Vector2::yAxis = Vector2(0.0f, 1.0f);

	Vector2::Vector2(float a_a, float a_b)
	{
		x = a_a;
		y = a_b;
	}

	Vector2 Vector2::Add(Vector2 a_v)
	{
		return Vector2(x + a_v.x, y + a_v.y);
	}

	Vector2 Vector2::Add(float a_a)
	{
		return Vector2(x + a_a, y + a_a);
	}

	Vector2 Vector2::Substract(Vector2 a_v)
	{
		return Vector2(x - a_v.x, y - a_v.y);
	}

	Vector2 Vector2::Substract(float a_a)
	{
		return Vector2(x - a_a, y - a_a);
	}

	Vector2 Vector2::Product(Vector2 a_v)
	{
		return Vector2(x * a_v.x, y * a_v.y);
	}

	Vector2 Vector2::Product(float a_a)
	{
		return Vector2(x * a_a, y * a_a);;
	}

	Vector2 Vector2::Invert()
	{
		return Vector2(1 / x,1 / y);
	}

	float Vector2::Length()
	{
		return Math::Sqrt((x * x)+ (y * y));
	}

	Vector2 Vector2::Normalize()
	{
		return Vector2(x / Length(), y / Length());
	}

	float Vector2::DotProduct(Vector2 a_v)
	{
		return ((x * a_v.x) + (y * a_v.y));
	}

	void Vector2::Print()
	{
		std::cout << x << ", " << y << '\n';
	}

	Vector2 Vector2::operator+(const float a_a)
	{
		return Add(a_a);
	}

	Vector2 Vector2::operator+(const Vector2& a_v)
	{
		return Add(a_v);
	}

	Vector2 Vector2::operator-(const float a_a)
	{
		return Substract(a_a);
	}

	Vector2 Vector2::operator-(Vector2& a_v)
	{
		return Substract(a_v);
	}

	Vector2 Vector2::operator*(const float a_a)
	{
		return Product(a_a);
	}

	Vector2 Vector2::operator*(const Vector2& a_v)
	{
		return Product(a_v);
	}

	Vector2 Vector2::operator/(const float a_a)
	{
		return Product(1/a_a);
	}

	Vector2 Vector2::operator/(Vector2& a_v)
	{
		return Product(a_v.Invert());
	}

	void Vector2::operator+=(const float a_a)
	{
		x += a_a;
		y += a_a;
	}

	void Vector2::operator+=(const Vector2& a_v)
	{
		x += a_v.x;
		y += a_v.y;
	}

	void Vector2::operator*=(const float a_a)
	{
		x *= a_a;
		y *= a_a;
	}

	void Vector2::operator*=(const Vector2& a_v)
	{
		x *= a_v.x;
		y *= a_v.y;
	}

	void Vector2::operator-=(const float a_a)
	{
		x -= a_a;
		y -= a_a;
	}

	void Vector2::operator-=(const Vector2& a_v)
	{
		x -= a_v.x;
		y -= a_v.y;
	}

	void Vector2::operator/=(const float a_a)
	{
		x /= a_a;
		y /= a_a;
	}

	void Vector2::operator/=(const Vector2& a_v)
	{
		x /= a_v.x;
		y /= a_v.y;
	}

	bool Vector2::operator==(const float a_a)
	{
		return (x == a_a && y == a_a);
	}

	bool Vector2::operator==(const Vector2 a_v)
	{
		return (x == a_v.x && y == a_v.y);
	}

	bool Vector2::operator!=(const float a_a)
	{
		return !(x == a_a && y == a_a);
	}

	bool Vector2::operator!=(const Vector2 a_v)
	{
		return !(x == a_v.x && y == a_v.y);
	}

}


