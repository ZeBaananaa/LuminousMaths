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

	Vector2::Vector2(float p_a, float p_b)
	{
		x = p_a;
		y = p_b;
	}

	Vector2 Vector2::Add(Vector2 p_v)
	{
		return Vector2(x + p_v.x, y + p_v.y);
	}

	Vector2 Vector2::Add(float p_a)
	{
		return Vector2(x + p_a, y + p_a);
	}

	Vector2 Vector2::Substract(Vector2 p_v)
	{
		return Vector2(x - p_v.x, y - p_v.y);
	}

	Vector2 Vector2::Substract(float p_a)
	{
		return Vector2(x - p_a, y - p_a);
	}

	Vector2 Vector2::Product(Vector2 p_v)
	{
		return Vector2(x * p_v.x, y * p_v.y);
	}

	Vector2 Vector2::Product(float p_a)
	{
		return Vector2(x * p_a, y * p_a);;
	}

	float Vector2::Length()
	{
		return Math::Sqrt((x * x)+ (y * y));
	}

	Vector2 Vector2::Normalize()
	{
		return Vector2(x / Length(), y / Length());
	}

	float Vector2::DotProduct(Vector2 p_v)
	{
		return ((x * p_v.x) + (y * p_v.y));
	}

	float Vector2::CrossProduct(Vector2 p_v)
	{
		return ((x * p_v.y) - (y * p_v.x));
	}

	void Vector2::Print()
	{
		std::cout << x << ", " << y << '\n';
	}

	Vector2 Vector2::operator+(const float p_a)
	{
		return Add(p_a);
	}

	Vector2 Vector2::operator+(const Vector2& p_v)
	{
		return Add(p_v);
	}

}


