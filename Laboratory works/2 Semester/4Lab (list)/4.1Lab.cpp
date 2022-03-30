#include <iostream>
#include <4.1Functions.hpp>
#include <string>

using namespace fal;


int main()
{
	void (*op[4])(T_List*) = { PRINT, CLEAR, DELETE, DUPLICATE }; // массив указателей на функции

	T_List* head = new T_List; // создание фиктивного элемента (самый первый эелемент в списке) ((!)) ОПЕРАТОР NEW ВОЗВРАЩАЕТ ССЫЛКУ 
	head->next = nullptr; // по хорошему никакой информацией на заполнять (при обращении к след. элементу ->next он ссылается ни на что nullptr)

	// создаем список 
	//for (int i = 0; i < 2; i++)
		//ADD(head, rand() % 10); // отправляем начало списка и рандомные данные, которые хранит элемент в нашем случаe только 1 число 
	
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

	delete head; // написали new T_list - Удалили сразу ((!))
	return 0;
}