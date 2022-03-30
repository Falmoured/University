#include <iostream>
#include <functions.hpp>

namespace fal
{
	DLCL::DLCL()
	{
		m_sent = new D_List;
		m_sent->next = m_sent;
		m_sent->prev = m_sent;

		head = nullptr;
		tail = nullptr;
		count = 0;
	}

	/*void DLCL::ADDINTAIL(int data) // хз не уверен
	{
		D_List* tmp = new D_List;

		tmp->data = data;

		if (head == nullptr)
			head = tmp;
		else
			tail->next = tmp;
		tail = tmp;

		1count++;
	}*/

	void DLCL::ADDINHEAD(int data)
	{
		/*
		D_List* tmp = new D_List;
		tmp->next = head;
		head = tmp;
		if (count == 0)
			tail = head;
		
		count++;
		*/
		
		D_List* tmp = new D_List;

		tmp->next = m_sent->next;
		tmp->prev = m_sent;
		m_sent->next->prev = tmp;
		m_sent->next = tmp;
		tmp->data = data;

		/*tmp->prev = nullptr;

		tmp->data = data;	

		if (head != nullptr)
		{
			tmp->prev = tail;
			tail->next = tmp;
			head = tmp;
		}
		else
			head = tail = tmp;*/

		count++;
	}

	void DLCL::ADDINTAIL(int data)
	{
		/*
		D_List* tmp = new D_List;

		tmp->next = m_sent->next;
		tmp->prev = m_sent;
		m_sent->next->prev = tmp;
		m_sent->next = tmp;
		tmp->data = data;*/
		D_List* tmp = new D_List;

		tmp->prev = m_sent->prev;
		tmp->next = m_sent;
		m_sent->prev->next = tmp;
		m_sent->prev = tmp;
		tmp->data = data;

		count++;
		/*D_List* tmp = new D_List;

		tmp->next = nullptr;
		tmp->prev = nullptr;

		tmp->data = data;

		if (head != nullptr)
		{
			tmp->next = head;
			head->prev = tmp;
			head = tmp;
		}
		else
			head = tail = tmp;

		count++;*/
		/*D_List* tmp = new D_List;

		tmp->prev = tail;
		tmp->next = nullptr;

		tmp->data = data;

		if (tail != nullptr)
			tail->next = tmp;

		if (count == 0)
			tail = head = tmp;
		else
			tail = tmp;

		count++;*/
	}

	void DLCL::PRINT()
	{
		if (count != 0)
		{
			D_List* tmp = m_sent->next;
			while (tmp != m_sent)
			{
				std::cout << tmp->data << " , ";
				tmp = tmp->next;
			}
		}
	}

	void DLCL::REVERSEPRINT()
	{
		if (count != 0)
		{
			D_List* tmp = m_sent->prev;
			while (tmp != m_sent)
			{
				std::cout << tmp->data << " , ";
				tmp = tmp->prev;
			}
		}
	}


	void DLCL::INSERT(int pos, int data)
	{
		if (pos < 1 || pos > count + 1) { std::cout << "Incorrect pos, put new one: "; std::cin >> pos; }

		if (pos == count + 1)
		{
			ADDINTAIL(data);
			return;
		}

		if (pos == 1)
		{
			ADDINHEAD(data);
			return;
		}

		int i = 0; // счетчик
		D_List* curr = m_sent; // элемент, который занимает нашу позицию в которую мы хотим вставить

		while (i < pos) // цикл чтобы дойти до этого элемента (curr)
		{
			curr = curr->next;
			i++;
		}

		D_List* prevcurr = curr->prev; // элемент перед которым новый элемент будет стоять

		D_List* tmp = new D_List; // новый элемент который вставляем

		tmp->data = data;

		if (prevcurr != nullptr && count != 1) // проверка
			prevcurr->next = tmp;

		tmp->next = curr;
		tmp->prev = prevcurr;
		curr->prev = tmp;

		count++;
	}

	void DLCL::DELETE(int pos)
	{
		if (pos < 1 || pos > count) { std::cout << "Incorrect pos, put new one: "; std::cin >> pos; }
	
		int i = 1; // счетчик элементов

		D_List* Del = m_sent->next; // элемент который ищем

		while (Del != m_sent && i < pos) // доходим до элемента, Который удаляем
		{
			Del = Del->next;
			i++;
		}

		Del->next->prev = Del->prev;
		Del->prev->next = Del->next;
		delete Del;
		
		/*D_List* PrevDel = Del->prev; // элемент перед удаляемым
		D_List* AfterDel = Del->next; // элемент после удаляемого

		if ((pos == 1) && (count > 1))
		{
			PrevDel->next = AfterDel;
			AfterDel->prev = PrevDel;
			delete Del;
		}

		else if ((pos == 1) && (count = 1)) { CLEAR(); }

		else
		{
			PrevDel->next = AfterDel;
			AfterDel->prev = PrevDel;
			delete Del;
		}*/


		/*if (PrevDel != m_sent && count != 1) // Удаляем НЕ ГОЛОВУ
			PrevDel->next = AfterDel;

		if (AfterDel != m_sent->prev && count != 1) // Удаляем НЕ ХВОСТ
			AfterDel->next = PrevDel;

		if (pos = 1*/
		
		/*// Хвост или голову
		if (pos == 1)
		{
			PrevDel->next = AfterDel;

			head = AfterDel;
		}
		if (pos == count)
			tail = PrevDel;*/

		//delete Del;

		count--;
	}

	void DLCL::CLEAR() // хотел через функцию delete, но как-то каждый раз ее вызывать...
	{
		D_List* tmp;
		D_List* p = m_sent->next;
		while (p != m_sent)
		{
			tmp = p;
			p = p->next;
			delete tmp;
		}
	}

	DLCL::~DLCL()
	{
		CLEAR();
		delete m_sent;
	}

};
