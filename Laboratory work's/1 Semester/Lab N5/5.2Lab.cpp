ы#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#define W 10

int main()
{
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);

	int n;
	in >> n;

	std::string w[W];
	for (int i = 0; i < W; i++)
		w[i] = '/0';

	std::string s;
	while (!in.eof())
	{
		bool f{ 0 };
		in >> s;
		// Проверка на одинаковые букавы
		for (int i = 0; i < int(s.length()); i++)
			for (int j = i + 1; j < int(s.length()); j++)
			{
				if (s[i] == s[j])
				{
					f = 1;
					break;
				}
			}
		if (f == 0)
		{
			int i{ 0 };
			while (s.length() < w[i].length())
				i = i + 1;
			if (s.length() >= w[i].length())
			{
				for (int j = i+1; j < W - 1; j++)
					w[j + 1] = w[j];
				w[i+1] = w[i];
				w[i] = s;
			}
		}

	}
	for (int j = 0; j < n; j++)
		std::cout << w[j] << std::endl;
	return 0;
}