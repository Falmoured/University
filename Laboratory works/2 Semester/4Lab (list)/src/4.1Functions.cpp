#include <4.1Functions.hpp>
#include <iostream>
#include <math.h>

// ����� ������������ ������ : ������ � ������� ��������������� � ���-��� ���������
// ������: �������������� � ��������� ������� � ����������� ��������

namespace fal
{
	// �-� �� ���������� ������ �������� � ������
	void ADD(T_List* head, int age)
	{
		T_List* p = new T_List; // �������� NEW ���������� ������ 
		p->age = age;
		// ������������� ��������� [head] -> nullptr // ������� ���� ���������� ����� ������� [p] -> nullptr
		p->next = head->next; // ������� ���� ���������� ����� ������� [p] -> nullptr
		head->next = p; // � ������ ����� [head] -> [p] 
	}

	// ��������� ������������ ���������� ������ � ������� �-�� ������ ������ ������
	void PRINT(T_List* head) // ���������� ������(������) ������ ������
	{
		T_List* p = head->next; // ��� ������ �������� ������ �.�. �� �������� � ��� ������ ��� => ����� ������ �� ����. ������� �� ������
		while (p != nullptr) // [head] -> [next] -> ...  -> nullptr ... ��� ������ �� nullptr
		{
			std::cout << p->age << std::endl; // ������� ����
			p = p->next; // ��������� � ����� �������� �� [next] � -> ...
		}
	}

	// ������ ������ (������� �������� �� ����������� ������, �.�. ��� ��������� � �����)	
	void CLEAR(T_List* head) // ���������� ������ ������ 
	{
		T_List* tmp; 
		T_List* p = head->next; // ������� ���������� ������ ������� �� ������
		while (p != nullptr) // ���� �� ������ �� ����� 
		{
			tmp = p; // [head] -> [p] -> ... -> nullptr // [tmp] = [p]
			p = p->next; // [head] -> [tmp] -> [p] -> ... -> nullptr 
			delete tmp; // ������� [tmp]
		}
	}

	void DELETE(T_List* head, int max)
	{
		T_List* tmp; // �������� ���������� ���������, ������� � ����������� ����� ������� 
		T_List* p = head; // ����� ������ ������ 
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

	// �������������� �����-�� ������� � ������
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