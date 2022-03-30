#include <4.1Functions.hpp>
#include <iostream>
#include <math.h>

// ПЛЮСЫ ОДНОСВЯЗНОГО СПИСКА : ЛЕГКОЕ И БЫСТРОЕ МАНИПУЛИРОВАНИЕ С КОЛ-ВОМ ЭЛЕМЕНТОВ
// МИНУСЫ: БЫСТРОДЕЙСТВИЕ К ПОЛУЧЕНИЮ ДОСТУПА К КОНКРЕТНОМУ ЭЛЕМЕНТУ

namespace fal
{
	// ф-я по добавлению нового элемента в списко
	void ADD(T_List* head, int age)
	{
		T_List* p = new T_List; // ОПЕРАТОР NEW ВОЗВРАЩАЕТ ССЫЛКУ 
		p->age = age;
		// перекидывание стрелочек [head] -> nullptr // сначала надо перекинуть новый эелмент [p] -> nullptr
		p->next = head->next; // сначала надо перекинуть новый эелмент [p] -> nullptr
		head->next = p; // а только потом [head] -> [p] 
	}

	// проверяем правильность заполнения списка с помощью ф-ии печати самого списка
	void PRINT(T_List* head) // отправляем голову(начало) нашего списка
	{
		T_List* p = head->next; // нет смысла выводить голову т.к. по хорошему в ней ничего нет => нужно начать со след. элемнта от головы
		while (p != nullptr) // [head] -> [next] -> ...  -> nullptr ... вот почему до nullptr
		{
			std::cout << p->age << std::endl; // выводим инфу
			p = p->next; // переходим в некст элементу от [next] к -> ...
		}
	}

	// чистка памяти (удаляем элементы за исключением головы, т.к. она удаляется в мейне)	
	void CLEAR(T_List* head) // отправляем начало списка 
	{
		T_List* tmp; 
		T_List* p = head->next; // придаем переменной первый элемент от головы
		while (p != nullptr) // пока не дойдем до конца 
		{
			tmp = p; // [head] -> [p] -> ... -> nullptr // [tmp] = [p]
			p = p->next; // [head] -> [tmp] -> [p] -> ... -> nullptr 
			delete tmp; // удаляем [tmp]
		}
	}

	void DELETE(T_List* head, int max)
	{
		T_List* tmp; // создание временнего указателя, который в последствии будем удалять 
		T_List* p = head; // берем начало списка 
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

	// Продублировать какой-то элемент в списке
	void DUPLICATE(T_List* head, int max)
	{
		T_List* p = head->next;
		while (p != nullptr)
		{
			if (p->age == max)
			{
				T_List* q = new T_List;
				q->next = p->next;
				p->next = q;
				q->age = p->age;
				p = p->next;
			}
			p = p->next;
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