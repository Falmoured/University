#include <iostream>
#include <fstream>

int main()
{
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int symbols[256];
	for (int i = 0; i < 256; i++)
		symbols[i] = 0;

	char c;
	while (in >> c)
		symbols[c]++;

	int max{ INT_MIN };
	char maxchar;
	
	for (int i = 97; i < 123; i++)
		if (symbols[i] > max)
		{
			max = symbols[i];
			maxchar = char(i);
		}

	std::cout << maxchar << " - " << max << std::endl;
	return 0;
}
	