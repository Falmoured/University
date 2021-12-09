#include <iostream>
#include <fstream>

int main()
{
	//std::ifstream in("solution.txt");
	//std::ofstream out("result.txt");

	int length1,length2, maxs{ -10 };
	std::cin >> length1 >> length2;

	// Ввод мэссива
	int** mas = new int* [length1];
	for (int i = 0; i < length1; i++)
		mas[i] = new int[length2];



	for (int i = 0; i < length1; i++)
		for (int j = 0; j < length2; j++)
			mas[i][j] = 0;


	// Нахождение строки с самой большой суммой элементов
	int sumstr{ 0 }, numstr{ 0 };
	for (int i = 0; i < length1; i++)
	{
		sumstr = 0;
		for (int j = 0; j < length2; j++)
		{
			std::cin >> mas[i][j];
			sumstr = sumstr + mas[i][j];
			if (sumstr > maxs)
			{
				maxs = sumstr;
				numstr = i;
			}
		}
	}

	for (int i = numstr; i <= numstr; i++)
		for (int j = 0; j < length2;j++)
			mas[i][j] = 999;

	// Вывод массива
	for (int i = 0; i < length1; i++)
	{
		for (int j = 0; j < length2; j++)
			std::cout << mas[i][j] << " ";
		std::cout << std::endl;
	}

	for (int i = 0; i < length2; i++)
		delete[] mas[i];
	delete[] mas;

	return 0;
}