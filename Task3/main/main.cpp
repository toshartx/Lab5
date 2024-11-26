#include <iostream>
#include <Windows.h>

int* CreateArray(int);
int** CreateMatrix(int);
int* CreateModifiedArray(int**, int, int&);
void DeleteArray(int*);
void DeleteMatrix(int**, int);

int main()
{
	setlocale(LC_ALL, "Russian");
	HINSTANCE load;
	load = LoadLibrary(L"../../Task2/x64/Debug/DynamicLib.dll");
	typedef bool (*restart) ();
	restart RestartProgramm = (restart)GetProcAddress(load, "RestartProgramm");
	typedef void (*content) ();
	content ContextMenu = (content)GetProcAddress(load, "ContextMenu3");
	typedef int (*inp) ();
	inp Input = (inp)GetProcAddress(load, "Input");
	typedef int (*arrInp) ();
	arrInp ArraySizeInput = (inp)GetProcAddress(load, "ArraySizeInput");

	bool restartFlag = RestartProgramm();
	while (restartFlag)
	{
		ContextMenu();
		std::cout << "Введите размер квадратной матрицы:\n";
		int n = ArraySizeInput();
		int** matrix = CreateMatrix(n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << "Введите элемент матрицы " << i << j << '\n';
				matrix[i][j] = Input();
			}
		}

		int sizeOfModifiedArray = 0;
		int* modifiedArray = CreateModifiedArray(matrix, n, sizeOfModifiedArray);
		int multiplication = 1;
		std::cout << "Новый массив:\n";
		for (int i = 0; i < sizeOfModifiedArray; ++i)
		{
			std::cout << modifiedArray[i] << " ";
			multiplication *= modifiedArray[i];
		}
		std::cout << "\nПроизведение элементов нового массива: " << multiplication << '\n';

		DeleteArray(modifiedArray);
		DeleteMatrix(matrix, n);
		restartFlag = RestartProgramm();
	}

	FreeLibrary(load);
	return 0;
}

int* CreateModifiedArray (int** arr, int n, int& size)
{
	for (int i = 0, j = 0; i < n; ++i, ++j)
	{
		if (arr[i][j] % 2 == 0)
		{
			++size;
		}
	}

	int* newArray = CreateArray(size);
	for (int i = 0, j = 0, k = 0; i < n; ++i, ++j)
	{
		if (arr[i][j] % 2 == 0)
		{
			newArray[k] = arr[i][j];
			++k;
		}
	}
	return newArray;
}

int* CreateArray(int n)
{
	int* arr = new int[n];
	return arr;
}

int** CreateMatrix(int n)
{
	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[n];
	}
	return matrix;
}

void DeleteArray(int* arr)
{
	delete[] arr;
	arr = nullptr;
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