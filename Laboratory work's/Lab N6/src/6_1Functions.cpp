#include <iostream>
#define N 100
#include "6_1Functions.h"
namespace fal
{
	void Read(int& n, int mas[N][N])
	{
		std::cin >> n;
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
}