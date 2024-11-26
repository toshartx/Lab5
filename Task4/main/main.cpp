#include <iostream>
#include <Windows.h>

void printArray(double** arr, int n, int m);
double** createMatrix(int, int);
void DeleteMatrix(double**, int);
int ZeroCounter(double**, int, int);
void ReverseMatrix(double**, int, int);

int main()
{
	setlocale(LC_ALL, "Russian");
	HINSTANCE load;
	load = LoadLibrary(L"../../Task2/x64/Debug/DynamicLib.dll");
	typedef bool (*restart) ();
	restart RestartProgramm = (restart)GetProcAddress(load, "RestartProgramm");
	typedef void (*content) ();
	content ContextMenu = (content)GetProcAddress(load, "ContextMenu4");
	typedef double (*inp) ();
	inp Input = (inp)GetProcAddress(load, "DoubleInput");
	typedef int (*arrInp) ();
	arrInp ArraySizeInput = (arrInp)GetProcAddress(load, "ArraySizeInput");

	bool restartFlag = RestartProgramm();
	while (restartFlag)
	{
		ContextMenu();
		std::cout << "Введите количество строк матрицы: ";
		int n = ArraySizeInput();
		std::cout << "Введите количество столбцов матрицы: ";
		int m = ArraySizeInput();
		double** matrix = createMatrix(n, m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				std::cout << "Введите элемент матрицы " << i << j << '\n';
				matrix[i][j] = Input();
			}
		}

		std::cout << "Количество нулевых элементов: " << ZeroCounter(matrix, n, m) << '\n';
		ReverseMatrix(matrix, n, m);
		std::cout << "Массив в обратном порядке:\n";
		printArray(matrix, n, m);
 		
		DeleteMatrix(matrix, n);
		restartFlag = RestartProgramm();
	}

	FreeLibrary(load);
	return 0;
}

void printArray(double** arr, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << '\n';
	}
}

double** createMatrix(int n, int m)
{
	double** matrix = new double* [n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new double[m] {};
	}
	return matrix;
}

void DeleteMatrix(double** arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;
}

int ZeroCounter(double** matrix, int n, int m)
{
	int zeroCounter = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (matrix[i][j] == 0)
			{
				std::cout << "Нулевой элемент найден на позиции " << i << j << '\n';
				++zeroCounter;
			}
		}
	}
	return zeroCounter;
}
void ReverseMatrix(double** matrix, int n, int m)
{
	for (int i = 0; i < n / 2; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			double temp = matrix[n - 1 - i][m - 1 - j];
			matrix[n - 1 - i][m - 1 - j] = matrix[i][j];
			matrix[i][j] = temp;
		}
	}
}