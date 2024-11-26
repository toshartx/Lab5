#include "../StaticLib/Task1.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	bool restartFlag = RestartProgramm();
	while (restartFlag) {
		ContextMenu();

		std::cout << "������� ������ �������: ";
		int n = Input();

		int** B = CreateMatrix(n);
		int** C = CreateMatrix(n);

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << "������� �������[" << i << "] [" << j << "]������� B: ";
				B[i][j] = Input();
				std::cout << "������� �������[" << i << "] [" << j << "]������� C: ";
				C[i][j] = Input();
			}
		}
		SolveTask(B, C, n);

		restartFlag = RestartProgramm();
	}
	return 0;
}