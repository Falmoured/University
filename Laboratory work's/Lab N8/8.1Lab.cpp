#include <iostream>
#include <fstream>

int main()
{
	//std::ifstream in("input.txt");
	//std::ofstream out("output.txt");
	
	int length;
	std::cin >> length;

	int *mas = new int[length](); int *sum = new int[length](); int *first = new int[length]();
	for (int i = 0; i < length; i++)
		mas[i] = 0;


	int f{ 0 }, x{ 0 };

	for (int i = 0; i < length; i++)
	{
		std::cin >> mas[i];

		// поиск первой цифры числа
		f = mas[i];
		while (f > 9)
			f = f / 10;
		first[i] = f;

		// поиск суммы цифр
		x = mas[i];
		while (x > 0)
		{
			sum[i] += x % 10;
			x = x / 10;
		}
	}

	// Сортировка
	for (int i = 0; i < length; i++)
		for (int j = i + 1; j < length; j++)
		{

			if (sum[i] > sum[j])
			{
				std::swap(mas[i], mas[j]);
				std::swap(sum[i], sum[j]);
				std::swap(first[i], first[j]);
			}
			else if (sum[i] == sum[j] && first[i] > first[j])
			{
				std::swap(mas[i], mas[j]);
				std::swap(sum[i], sum[j]);
				std::swap(first[i], first[j]);
			}
			else if (sum[i] == sum[j] && first[i] == first[j] && mas[i] > mas[j])
			{
				std::swap(mas[i], mas[j]);
				std::swap(sum[i], sum[j]);
				std::swap(first[i], first[j]);
			}
		}
	for (int i = 0; i < length; i++)
		std::cout << mas[i] << " ";

	delete[] mas, sum, first;


	return 0;
}