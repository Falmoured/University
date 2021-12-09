#include <iostream>
#include <fstream>
#define N 1000

int main()
{
	std::ifstream in("solution.txt");
	std::ofstream out("result.txt");

	int mas[N]; int sum[N]; int first[N];
	for (int i = 0; i < N; i++)
		mas[i] = 0;


	int n, f{ 0 }, x{ 0 };
	in >> n;
	for (int i = 0; i < n; i++)
	{
		in >> mas[i];

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
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
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
	for (int i = 0; i < n; i++)
		out << mas[i] << " ";
	return 0;
}