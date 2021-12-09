#include <iostream>
#include "6_1Functions.h"
#define N 100

int main()
{
	int n, c{ 0 };
	int mas[N][N];

	fal::Read(n, mas);

	for (int i = 0; i < n; i++)
	{
		int j{ i };
		if ((mas[i][j] > 0) && (fal::containsThreeOrFive(mas[i][j])) == 1)
			c += 1;
	}

	if (c == n)
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
	else
		std::cout << "The elemnts do not match the conditions" << std::endl;

	return 0;
}