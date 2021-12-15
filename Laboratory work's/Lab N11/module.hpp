#pragma once
#include <string>
#include <vector>

namespace fal
{
	class Module
	{
public:

		Module(std::string name, int address);

		~Module();


		void Poll();

		void Print();

private:
		int m_address;
		std::string m_name;
		float m_input1, m_input2;
	};
}
