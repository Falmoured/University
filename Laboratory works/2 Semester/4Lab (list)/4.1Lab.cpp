#include <iostream>
#include <4.1Functions.hpp>
#include <string>

using namespace fal;


int main()
{
	void (*op[4])(T_List*) = { PRINT, CLEAR, DELETE, DUPLICATE }; // ������ ���������� �� �������

	T_List* head = new T_List; // �������� ���������� �������� (����� ������ �������� � ������) ((!)) �������� NEW ���������� ������ 
	head->next = nullptr; // �� �������� ������� ����������� �� ��������� (��� ��������� � ����. �������� ->next �� ��������� �� �� ��� nullptr)

	// ������� ������ 
	//for (int i = 0; i < 2; i++)
		//ADD(head, rand() % 10); // ���������� ������ ������ � ��������� ������, ������� ������ ������� � ����� �����e ������ 1 ����� 
	
	ADD(head, 5);
	ADD(head, 10);

	op[0](head);

	//DELETE(head, MAXSEARCH(head));
	//std::cout << "After Delete: " << std::endl;
	//op[0](head);

	op[3](head, MAXSEARCH(head));
	std::cout << "After Duplicate: " << std::endl;
	op[0](head);

	op[1](head);

	delete head; // �������� new T_list - ������� ����� ((!))
	return 0;
}