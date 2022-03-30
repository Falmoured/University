#include <iostream>
#define N 10
#define d 10


void ShellSort(int mas[N], int n)
	{
	int h{ 1 };
	while (h < n / d) 
		h = 3 * h + 1;

	while (h > 0)
	{
		for (int k = 0; k < h; k += h)
		{
			int i = k + h;
			while (i <= n)
			{
				int y = mas[i];
				int j = i - h;
				while ((j > -1) && (mas[j] > y))
				{
					mas[j + h] = mas[j];
					j = j - h;
				}
				mas[j + h] = y;
				i = i + h;
			}
		}
		h = h / 3;
	}
}

int main()
{
	srand(time(0));
	int mas[N];

	for (int i = 0; i < N; i++) 
		mas[i] = rand() % 100;

	for (int i = 0; i < N; i++)
		std::cout << mas[i] << std::endl;

	ShellSort(mas, N - 1);
	std::cout << "After sort:" << std::endl;

	for (int i = 0; i < N; i++)
		std::cout << mas[i] << std::endl;
}
