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
		std::cout << "����������\n";
	}
	else
	{
		std::cout << "�� ����������\n";
	}
}

extern "C" void __declspec(dllexport) ContextMenu2()
{
	std::cout << "��������� ��������� ������������� � ���������� ������� A �������� A[i], ������� ������������� ������� A[i] <= i*i\n"
		      << "������� 13\n";
}

extern "C" void __declspec(dllexport) ContextMenu3()
{
	std::cout << "----------------------------------------------------------------------------------------------------------\n"
		<< "��������� ���������� ���������� ������, ��������� �� ������ ��������� ������� ��������� �������.\n"
		<< "----------------------------------------------------------------------------------------------------------\n";
}

extern "C" void __declspec(dllexport) ContextMenu4()
{
	std::cout << "----------------------------------------------------------------------------------------------------------\n"
		<< "��������� ������� ��������� ������ � �������� �������, � ����� ������� ���������� ������� ��������� � ������� � �� �������.\n"
		<< "----------------------------------------------------------------------------------------------------------\n";
}

extern "C" void __declspec(dllexport) ContextMenu5()
{
	std::cout << "----------------------------------------------------------------------------------------------------------\n"
		<< "��������� ������ ������ �� �����, ����������� � ������ ��������, � ���������� ���������.\n"
		<< "----------------------------------------------------------------------------------------------------------\n";
}

extern "C" bool __declspec(dllexport) RestartProgramm()
{
	bool a;
	std::cout << "0 - ��������� ���������\n"
			  << "1 - ��������� ���������\n";
	while (!(std::cin >> a) || std::cin.peek() != '\n')
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "������������ ����. ��������� �������\n";
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
		std::cout << "������������ ����. ��������� �������\n";
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
		std::cout << "������������ ����. ��������� �������\n";
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
		std::cout << "������������ ����. ��������� �������\n";
	}
	return a;
}

