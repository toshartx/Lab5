#include <iostream>

extern "C" bool __declspec(dllexport) Recursive(int* arr, int n, int i)
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

extern "C" void __declspec(dllexport) SolveTask(int* arr, int n)
{
	if (Recursive(arr, n, n - 1) == 1 || Recursive(arr, n, 0) == 1)
	{
		std::cout << "Существует\n";
	}
	else
	{
		std::cout << "Не существует\n";
	}
}

extern "C" void __declspec(dllexport) ContextMenu2()
{
	std::cout << "Программа проверяет существование в одномерном массиве A элемента A[i], который удовлетворяет условию A[i] <= i*i\n"
		      << "Вариант 13\n";
}

extern "C" void __declspec(dllexport) ContextMenu3()
{
	std::cout << "----------------------------------------------------------------------------------------------------------\n"
		<< "Программа составляет одномерный массив, состоящий из чётных элементов главной диагонали матрицы.\n"
		<< "----------------------------------------------------------------------------------------------------------\n";
}

extern "C" void __declspec(dllexport) ContextMenu4()
{
	std::cout << "----------------------------------------------------------------------------------------------------------\n"
		<< "Программа выводит двумерный массив в обратном порядке, а также выводит количество нулевых элементов в массиве и их индексы.\n"
		<< "----------------------------------------------------------------------------------------------------------\n";
}

extern "C" void __declspec(dllexport) ContextMenu5()
{
	std::cout << "----------------------------------------------------------------------------------------------------------\n"
		<< "Программа создаёт массив из чисел, находящиеся в чётных столбцах, и являющиеся нечётными.\n"
		<< "----------------------------------------------------------------------------------------------------------\n";
}

extern "C" bool __declspec(dllexport) RestartProgramm()
{
	bool a;
	std::cout << "0 - завершить программу\n"
			  << "1 - запустить программу\n";
	while (!(std::cin >> a) || std::cin.peek() != '\n')
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Некорректный ввод. Повторите попытку\n";
	}
	return a;
}

extern "C" int __declspec(dllexport) Input()
{
	int a;
	while (!(std::cin >> a) || std::cin.peek() != '\n')
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Некорректный ввод. Повторите попытку\n";
	}
	return a;
}

extern "C" double __declspec(dllexport) DoubleInput()
{
	double a;
	while (!(std::cin >> a) || std::cin.peek() != '\n')
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Некорректный ввод. Повторите попытку\n";
	}
	return a;
}

extern "C" int __declspec(dllexport) ArraySizeInput()
{
	int a;
	while (!(std::cin >> a) || std::cin.peek() != '\n' || a <= 0)
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Некорректный ввод. Повторите попытку\n";
	}
	return a;
}

