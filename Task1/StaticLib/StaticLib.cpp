#include <iostream>
#include <cmath>

int** CreateMatrix(int n)
{
	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[n];
	}
	return matrix;
}

void DeleteMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] matrix[i];
		matrix[i] = nullptr;
	}
	delete[] matrix;
	matrix = nullptr;
}

void SolveTask(int** B, int** C, int n)
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

	std::cout << "Ваша матрица A:\n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << A[i][j] << " ";
		}
		std::cout << '\n';
	}

	DeleteMatrix(A, n);
	DeleteMatrix(B, n);
	DeleteMatrix(C, n);
}

int Input()
{
	int a;

	while (!(std::cin >> a) || std::cin.peek() != '\n')
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Некорректный ввод, повторите попытку:\n";
	}

	return a;
}

void ContextMenu()
{
	std::cout << "Программа для вычисления элементов двумерного динамического массива - матрицы A размерностью n × n.\n"
			  << "Значения элементов Aij определяет согласно выражениям:\n"
			  << "Aij =\n"
			  << "Bij, eсли |Bij| > |Cij| ;\n"
			  << "Cij, eсли |Bij| <= |Cij| ,\n\n"

			  << "где i = 0, 1, ..., n, j = 0, 1, ..., n.\n";
}

bool RestartProgramm()
{
	bool a;
	std::cout << "0 - Завершить программу\n"
		      << "1 - Запустить программу\n";
	while (!(std::cin >> a) || std::cin.peek() != '\n')
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Некорректный ввод, повторите попытку:\n";
	}

	return a;
}