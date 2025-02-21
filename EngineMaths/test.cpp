#include "pch.h"
#include "Vector2.h"
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
	
	(v / v2).Print();

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