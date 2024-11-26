#include <iostream>
#include <Windows.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	HINSTANCE load;
	load = LoadLibrary(L"DynamicLib.dll");
	typedef bool (*rec) (int*, int, int);
	rec Recursive = (rec)GetProcAddress(load, "Recursive");
	typedef void (*solve) (int*, int);
	solve SolveTask = (solve)GetProcAddress(load, "SolveTask");
	typedef void (*content) ();
	content ContextMenu = (content)GetProcAddress(load, "ContextMenu2");
	typedef bool (*restart) ();
	restart RestartProgramm = (restart)GetProcAddress(load, "RestartProgramm");
	typedef int (*input) ();
	input Input = (input)GetProcAddress(load, "Input");
	typedef int (*arrSize) ();
	arrSize ArraySizeInput = (input)GetProcAddress(load, "ArraySizeInput");
	
	bool restartFlag = RestartProgramm();
	while (restartFlag)
	{
		ContextMenu();
		std::cout << "¬ведите размер массива:\n";
		int n = ArraySizeInput();
		int* arr = new int[n];
		for (int i = 0; i < n; ++i)
		{
			std::cout << "¬ведите " << i << " элемент массива:\n";
			arr[i] = Input();
		}

		SolveTask(arr, n);


		delete[] arr;
		arr = nullptr;

		restartFlag = RestartProgramm();
	}
	

	FreeLibrary(load);
	return 0;
}