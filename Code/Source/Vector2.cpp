#include "Vector2.hpp"

#include "Utils.hpp"

#include <iostream>

namespace Maths
{
	Vector2 Vector2::Zero = Vector2(0.0f, 0.0f);
	Vector2 Vector2::One = Vector2(1.0f, 1.0f);
	Vector2 Vector2::XAxis = Vector2(1.0f, 0.0f);
	Vector2 Vector2::YAxis = Vector2(0.0f, 1.0f);

	Vector2::Vector2(const float& a_a, const float& a_b)
	{
		x = a_a;
		y = a_b;
	}

	Vector2 Vector2::Add(const Vector2& a_v) const
	{
		return Vector2(x + a_v.x, y + a_v.y);
	}

	Vector2 Vector2::Add(const float& a_a) const
	{
		return Vector2(x + a_a, y + a_a);
	}

	Vector2 Vector2::Subtract(const Vector2& a_v) const
	{
		return Vector2(x - a_v.x, y - a_v.y);
	}

	Vector2 Vector2::Subtract(const float& a_a) const
	{
		return Vector2(x - a_a, y - a_a);
	}

	Vector2 Vector2::Product(const Vector2& a_v) const
	{
		return Vector2(x * a_v.x, y * a_v.y);
	}

	Vector2 Vector2::Product(const float& a_a) const
	{
		return Vector2(x * a_a, y * a_a);;
	}

	Vector2 Vector2::Invert() const
	{
		return Vector2(1 / x, 1 / y);
	}

	float Vector2::Length() const
	{
		return Sqrt((x * x) + (y * y));
	}

	Vector2 Vector2::Normalize() const
	{
		return Vector2(x / Length(), y / Length());
	}

	float Vector2::DotProduct(const Vector2& a_v) const
	{
		return x * a_v.x + y * a_v.y;
	}

	void Vector2::Print() const
	{
		std::cout << x << ", " << y << '\n';
	}

	Vector2 Vector2::operator+(const float& a_a) const
	{
		return Add(a_a);
	}

	Vector2 Vector2::operator+(const Vector2& a_v) const
	{
		return Add(a_v);
	}

	Vector2 Vector2::operator-(const float& a_a) const
	{
		return Subtract(a_a);
	}

	Vector2 Vector2::operator-(const Vector2& a_v) const
	{
		return Subtract(a_v);
	}

	Vector2 Vector2::operator*(const float& a_a) const
	{
		return Product(a_a);
	}

	Vector2 Vector2::operator*(const Vector2& a_v) const
	{
		return Product(a_v);
	}

	Vector2 Vector2::operator/(const float& a_a) const
	{
		return Product(1 / a_a);
	}

	Vector2 Vector2::operator/(const Vector2& a_v) const
	{
		return Product(a_v.Invert());
	}

	void Vector2::operator+=(const float& a_a)
	{
		x += a_a;
		y += a_a;
	}

	void Vector2::operator+=(const Vector2& a_v)
	{
		x += a_v.x;
		y += a_v.y;
	}

	void Vector2::operator*=(const float& a_a)
	{
		x *= a_a;
		y *= a_a;
	}

	void Vector2::operator*=(const Vector2& a_v)
	{
		x *= a_v.x;
		y *= a_v.y;
	}

	void Vector2::operator-=(const float& a_a)
	{
		x -= a_a;
		y -= a_a;
	}

	void Vector2::operator-=(const Vector2& a_v)
	{
		x -= a_v.x;
		y -= a_v.y;
	}

	void Vector2::operator/=(const float& a_a)
	{
		x /= a_a;
		y /= a_a;
	}

	void Vector2::operator/=(const Vector2& a_v)
	{
		x /= a_v.x;
		y /= a_v.y;
	}

	bool Vector2::operator==(const float& a_a) const
	{
		return x == a_a && y == a_a;
	}

	bool Vector2::operator==(const Vector2& a_v) const
	{
		return x == a_v.x && y == a_v.y;
	}

	bool Vector2::operator!=(const float& a_a) const
	{
		return !(x == a_a && y == a_a);
	}

	bool Vector2::operator!=(const Vector2& a_v) const
	{
		return !(x == a_v.x && y == a_v.y);
	}

	float Vector2::operator[](const int& a_a) const
	{
		switch (a_a)
		{
		case 0:
			return x;
		case 1:
			return y;
		default:
			return 0.f;
		}
	}
}