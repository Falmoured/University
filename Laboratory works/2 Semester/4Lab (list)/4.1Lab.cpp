#include <iostream>
#include <4.1Functions.hpp>
#include <string>

using namespace fal;


int main()
{
	T_List* head = new T_List;
	head->next = nullptr;

	for (int i = 0; i < 10; i++)
		ADD(head, rand());
	
	PRINT(head);

	DELETE(head, MAXSEARCH(head));
	std::cout << "After Delete: " << std::endl;
	PRINT(head);

	CLEAR(head);

	delete head;
	return 0;
}