#include <iostream>
#include <Windows.h>

int** CreateMatrix(int, int);
void DeleteMatrix(int**, int);
void DeleteMatrix(int* arr);
void Solve(int**, int, int);

int main()
{
	setlocale(LC_ALL, "Russian");
	HINSTANCE load;
	load = LoadLibrary(L"../../Task2/x64/Debug/DynamicLib.dll");
	typedef bool (*restart) ();
	restart RestartProgramm = (restart)GetProcAddress(load, "RestartProgramm");
	typedef void (*content) ();
	content ContextMenu = (content)GetProcAddress(load, "ContextMenu5");
	typedef int (*inp) ();
	inp Input = (inp)GetProcAddress(load, "Input");
	typedef int (*arrInp) ();
	arrInp ArraySizeInput = (arrInp)GetProcAddress(load, "ArraySizeInput");
	bool restartFlag = RestartProgramm();
	while (restartFlag)
	{
		ContextMenu();
		std::cout << "Количество строк:\n";
		int n = ArraySizeInput();
		std::cout << "Количество столбцов:\n";
		int m = ArraySizeInput();
		int** matrix = CreateMatrix(n, m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				std::cout << "Введите элемент матрицы " << i << j << '\n';
				matrix[i][j] = Input();
			}
		}
		Solve(matrix, n, m);
		restartFlag = RestartProgramm();
	}
	
	FreeLibrary(load);
	return 0;
}

int** CreateMatrix(int n, int m)
{
	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[m] {};
	}
	return matrix;
}

void DeleteMatrix(int** arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;
}

void DeleteMatrix(int* arr)
{
	delete[] arr;
	arr = nullptr;
}

void Solve(int** arr, int n, int m)
{
	int counter = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i % 2 == 0 && arr[j][i] % 2 == 1)
			{
				++counter;
			}
		}
	}
	int* newArray = new int[counter] {};
	double averageSum = 0;
	for (int i = 0, k = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i % 2 == 0 && arr[j][i] % 2 == 1)
			{
				newArray[k] = arr[j][i];
				averageSum += (double(newArray[k])/counter);
				++k;
			}
		}
	}
	
	std::cout << "Новый массив:\n";
	for (int i = 0; i < counter; ++i)
	{
		std::cout << newArray[i] << " ";
	}
	std::cout << "\nСреднее арифмитическое элементов нового массива: " << averageSum << '\n';

	DeleteMatrix(arr, n);
	DeleteMatrix(newArray);
}