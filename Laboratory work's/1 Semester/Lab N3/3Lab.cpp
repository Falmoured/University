#include <iostream>

int main()
{
	int n; double x, r; int c = 0; int n1 = 0; int n2 = 0; double mn1 = INT_MAX; double mn2 = INT_MAX;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		c += 1;
		if (x != round(x))
		{
			if (x < mn1)
			{
				n2 = n1;
				n1 = c;
				mn2 = mn1;
				mn1 = x;
			}
			else if (x < mn2)
			{
				mn2 = x;
				n2 = c;
			}
		}
	}
	r = mn1 * mn2;
	std::cout << "Here is your result - " << r << std::endl;
	std::cout << "First - " << n1 << std::endl;
	std::cout << "Second - " << n2 << std::endl;
	return 0;
}

			


				




