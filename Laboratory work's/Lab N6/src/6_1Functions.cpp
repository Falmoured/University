#include <iostream>
#define N 100
#include "6_1Functions.h"
namespace fal
{
	void Read(int& n, int** mas)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				std::cin >> mas[i][j];
	}

	bool containsThreeOrFive(int x)
	{
		int ost;
		while (x > 0)
		{
			ost = x % 10;
			x = x / 10;
			if ((ost == 3) || (ost == 5))
				return 1;
		}
		return 0;
	}

	int diagonalCheck(int n,int** mas)
	{
		int c{ 0 };
		for (int i = 0; i < n; i++)
		{
			int j{ i };
			if ((mas[i][j] > 0) && (fal::containsThreeOrFive(mas[i][j])) == 1)
				c += 1;
		}
		return c;
	}

	void changeMatrix(int n, int** mas)
	{
		for (int i = 0; i < n; i++)
		{
			int mn{ INT_MAX };
			int mni{ 0 }, mnj{ 0 };
			int doubleSum{ 0 };

			for (int j = 0; j < n; j++)
			{
				if (mas[j][i] < mn)
				{
					mn = mas[j][i];
					mni = i;
					mnj = j;
				}
				doubleSum = doubleSum + mas[j][i] * mas[j][i];
			}

			mas[mnj][mni] = doubleSum - mn * mn;
		}
		for (int i = 0; i < n; i++)
		{
			std::cout << "\n";
			for (int j = 0; j < n; j++)
				std::cout << mas[i][j] << " ";
		}
	}
}