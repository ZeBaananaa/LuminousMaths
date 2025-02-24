#include "pch.h"
#include "Vectors.h"
#include "Utils.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

int main()
{
	Math::Vector2 v = Math::Vector2(5.0f, 4.0f);
	Math::Vector2 v2 = Math::Vector2(15.0f, 8.0f);

	Math::Vector2 v3 = Math::Vector2::zero;

	//v2 = v2.Normalize();

	Math::Vector3 v3d = Math::Vector3(5.0f, 6.0f, 3.0f);
	Math::Vector3 v3d2 = Math::Vector3(2.0f, 8.0f, 14.0f);
	
	std::cout << v3d.DotProduct(v3d2) << '\n';
	(v3d.CrossProduct(v3d2)).Print();
	(v3d - v3d2).Print();
	(v3d * v3d2).Print();
	(v3d / v3d2).Print();

	if (v != v2) 
	{
		std::cout << "EQUALLLLL" << '\n';
	}else
	{
		std::cout << "NOT EQUALLLLL" << '\n';
	}

	//std::cout << v.CrossProduct(v2) << '\n';

	return 0;
}