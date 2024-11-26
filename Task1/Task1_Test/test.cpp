#include "pch.h"
#include <limits>
#include <string>
#include "../StaticLib/Task1.h"

std::string SolveTask1(int** B, int** C, int n)
{
	int** A = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		A[i] = new int[n];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (std::abs(B[i][j]) > std::abs(C[i][j]))
			{
				A[i][j] = B[i][j];
			}
			else
			{
				A[i][j] = C[i][j];
			}
		}
	}

	std::string result;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			result += (std::to_string(A[i][j]) + " ");
		}
		result += '\n';
	}

	DeleteMatrix(A, n);
	DeleteMatrix(B, n);
	DeleteMatrix(C, n);
	return result;
}

TEST(Tests, Test1) {
	int n = 2;
	int** B = CreateMatrix(n);
	int** C = CreateMatrix(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			B[i][j] = i * n + j;
			C[i][j] = i * n - j;
		}
	}

	ASSERT_EQ(SolveTask1(B, C, n), "0 -1 \n2 3 \n");
}

TEST(SilnieTesti, Test2) {
	int n = 2;
	int** B = CreateMatrix(n);
	int** C = CreateMatrix(n);
	B[0][0] = INT_MAX;
	C[0][0] = INT_MIN + 1;
	B[0][1] = 1;
	C[0][1] = -1;
	B[1][0] = CHAR_MAX + 1;
	C[1][0] = CHAR_MIN;
	B[1][1] = 4;
	C[1][1] = -4;

	ASSERT_EQ(SolveTask1(B, C, n), "-2147483647 -1 \n-128 -4 \n");
}

TEST(SilnieTesti, Test3) {
	int n = 2;
	int** B = CreateMatrix(n);
	int** C = CreateMatrix(n);
	B[0][0] = 0;
	C[0][0] = -0;
	B[0][1] = 1;
	C[0][1] = -1;
	B[1][0] = -3;
	C[1][0] = 3;
	B[1][1] = 2;
	C[1][1] = -2;

	ASSERT_EQ(SolveTask1(B, C, n), "0 -1 \n3 -2 \n");
}

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}