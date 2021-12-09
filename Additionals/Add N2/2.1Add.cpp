#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		int d, m, y;
		std::cin >> d >> m >> y;

		int c{ 0 };
		bool f{ 0 };

		for (int j = y + 1; j < 2100; j++)
		{
			if ((j - 2000) % 4 == 0)
				c += 2;
			else
				c += 1;

			if (c % 7 == 0)
			{
				std::cout << j << std::endl;
				f = 1;
			}
			if (f == 1)
				break;
		}
	}

	return 0;
}