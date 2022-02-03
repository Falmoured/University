#include <iostream>
#include <fstream>
#define N 100

int main()
{
	std::ifstream in("solution.txt");
	std::ofstream out("result.txt");

	int n, m, maxs{-10};
	in >> n >> m;

	// Ввод, Обнуление массива
	int mas[N][N];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mas[i][j] = 0;


	// Нахождение строки с самой большой суммой элементов
	int sumstr{ 0 }, numstr{ 0 };
	for (int i = 0; i < n; i++)
	{
		sumstr = 0;
		for (int j = 0; j < m; j++)
		{
			in >> mas[i][j];
			sumstr = sumstr + mas[i][j];
			if (sumstr > maxs)
			{
				maxs = sumstr;
				numstr = i;
			}
		}
	}

	for (int i = numstr; i <= numstr; i++)
		for (int j = 0; j < m;j++)
			mas[i][j] = 999;

	// Вывод массива
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			out << mas[i][j] << " ";
		out << std::endl;
	}


	return 0;
}
			

				


	
