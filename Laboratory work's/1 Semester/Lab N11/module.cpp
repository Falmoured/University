#include "module.hpp"
#include <iostream>

namespace fal
{
	Module::Module(std::string name, int address)
	{
		m_name = name;
		m_address = address;
	}
	Module::~Module() {};

	void Module::Poll()
	{
		std::cin >> m_input1;
		std::cin >> m_input2;
	}
	void Module::Print()
	{
		std::cout << " Address :  " << m_address << std::endl;
		std::cout << " Name of the module -  " << m_name << std::endl;
		std::cout << "  First data entry: " << m_input1 << std::endl;
		std::cout << "  Second data entry: " << m_input2 << std::endl;
	}

}
