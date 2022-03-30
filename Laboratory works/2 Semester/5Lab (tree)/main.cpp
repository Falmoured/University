#include <tree.hpp>
#include <fstream>

using namespace fal;

int main()
{
	std::fstream in("input.txt");
	std::ofstream out("output.txt");
	int x;
	char c;

	Elem* root = nullptr;
	
	while (!in.eof())
	{
		in >> c;
		// ДобавОчка
		if (c == '+')
		{
			in >> x;
			ADD(x, root);
		}
		// Удаление
		if (c == '-')
		{
			in >> x;
			DELETE(x, root);
		}
		// Поиск
		if (c == '?')
		{
			in >> x;
			SEARCHPOS(x, root, 1);
		}	
		// tHe eNd
		if (c == 'E')
			break;
	}
	std::cout << root << std::endl;
	CLEAR(root);
	std::cout << root << std::endl;
	return 0;
}