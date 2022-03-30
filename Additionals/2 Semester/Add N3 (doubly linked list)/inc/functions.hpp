#pragma once
#include <iostream>

namespace fal
{
	struct D_List
	{
		D_List* next; // след элемент в списке
		D_List* prev; // пред элемент в списке
		int data; // info
	};

	class DLCL
	{
		D_List* head;
		D_List* tail;
		D_List* m_sent;
		int count;

	public:
		DLCL();

		~DLCL();

		// void ADD(int data); // хз

		void ADDINHEAD(int data); // add в начало списка
		void ADDINTAIL(int data); // add в конец спика
		void INSERT(int pos, int data);  // add в рандомную position
		void REVERSEPRINT();
		void DELETE(int pos); // delete elemnt

		void PRINT();
		
		void CLEAR();
	};
};