#include <vector>
#include "module.hpp"
#include <iostream>

using namespace fal;

int main()
{

	std::vector<Module*> vec;
	Module* module = new Module("OBEH MBA110-8A", 0);
	vec.push_back(module);
	module = new Module("Reallab-NL-8AI", 1);
	vec.push_back(module);

	for (const auto& i : vec)
	{
		i->Poll();
		std::cout << " " << std::endl;
		i->Print();
	}

	for (int i = 0; i < vec.size(); i++)
	{
		delete vec[i];
	}
}
