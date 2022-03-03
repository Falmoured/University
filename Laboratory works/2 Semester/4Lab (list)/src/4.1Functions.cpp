#include <4.1Functions.hpp>
#include <iostream>
#include <math.h>

namespace fal
{
	void ADD(T_List* head, int age)
	{
		T_List* p = new T_List;
		p->age = age;

		p->next = head->next;
		head->next = p;

	}

	void DELETE(T_List* head, int max)
	{
		T_List* tmp;
		T_List* p = head;
		while (p->next != nullptr)
		{
			if (p->next->age == max)
			{
				tmp = p->next;
				p->next = p->next->next;
				delete tmp;
			}
			else
				p = p->next;
		}
	}

	void PRINT(T_List* head)
	{
		T_List* p = head->next;
		while (p != nullptr)
		{
			std::cout << p->age << std::endl;
			p = p->next;
		}
	}

	void CLEAR(T_List* head)
	{
		T_List* tmp;
		T_List* p = head->next;
		while (p != nullptr)
		{
			tmp = p;
			p = p->next;
			delete tmp;
		}
	}

	int MAXSEARCH(T_List* head)
	{
		int max{ 0 };
		T_List* p = head;
		while (p->next != nullptr)
		{
			if ((p->next->age) > max)
				max = p->next->age;
			p = p->next;
		}

		return max;
	}
}