#include "pch.h"
#include <limits>

bool Recursive(int* arr, int n, int i)
{
	bool checkFlag = 0;
	if (i == n / 2)
	{
		if (arr[i] <= i * i)
			checkFlag = 1;
		return checkFlag;
	}
	if (arr[i] <= i * i)
	{
		checkFlag = 1;
		return checkFlag;
	}

	if (i <= n / 2)
		return Recursive(arr, n, i + 1);
	else
		return Recursive(arr, n, i - 1);
}

TEST(Tests, Test1) {
	int n = 3;
	int* arr = new int[n];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 5;
	ASSERT_FALSE(Recursive(arr, n, 0));
	ASSERT_FALSE(Recursive(arr, n, n - 1));
	delete[] arr;
	arr = nullptr;
}

TEST(Tests, Test2) {
	int n = 10000;
	int* arr = new int[n] {};
	for (int i = 0; i < n; ++i)
	{
		arr[i] = INT_MAX;
	}
	arr[n/2] = 0;
	ASSERT_TRUE(Recursive(arr, n, 0));
	ASSERT_TRUE(Recursive(arr, n, n - 1));
	delete[] arr;
	arr = nullptr;
}

TEST(Tests, Test3) {
	int n = 1;
	int* arr = new int[n];
	arr[0] = INT_MIN;
	ASSERT_TRUE(Recursive(arr, n, 0));
	ASSERT_TRUE(Recursive(arr, n, n - 1));
	delete[] arr;
	arr = nullptr;
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

