#include <iostream>
#include <fstream>

int main()
{
	std::ifstream in("solution.txt");

	int mas[10000];
	for (int i = 0; i < 10000; i++)
		mas[i] = 0;

	int n, sum, x;
	bool f = false;
	in >> n;

	for (int i = 0;i < n; i++)
	{
		in >> mas[i];
		sum = 0; x = mas[i];
		while (x > 0)
		{
			sum = sum + x % 10;
			x = x / 10;
		}
		if (sum == 19)
			f = true;
	}
	if (f == false)
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (mas[i] < mas[j])
					std::swap(mas[i], mas[j]);
	}

	for (int i = 0; i < 10; i++)
		std::cout << mas[i] << " ";
}
		


			
