#include <iostream>
#include <string>
#include "3.1Add_func.hpp"
// Программа только для англ. языка! )))))
using namespace pox;

int main()
{
	std::string s{ "" };
	
	std::getline(std::cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		whatIsThat(getNum(s[i]));
		std::cout << whatIsThat(getNum(s[i])) << std::endl;
	}

	return 0;
}