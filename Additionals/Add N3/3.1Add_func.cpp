#include <iostream>
#include "3.1Add_func.hpp"

using namespace std;

namespace pox
{
	int getNum(char s)
	{
		return int(s);
	}

	string whatIsThat(int x)
	{
		string s{ "" };
		if (((x >= 65) && (x <= 90)) || ((x >= 97) && (x <= 122)))
			return "Bukva";
		if ((x >= 48) && (x <= 57))
			return "Cifra";
		else
			return "Znak";
	}

}