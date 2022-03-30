#pragma once
#include <iostream>

namespace fal
{
	struct D_List
	{
		D_List* next; // ���� ������� � ������
		D_List* prev; // ���� ������� � ������
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

		// void ADD(int data); // ��

		void ADDINHEAD(int data); // add � ������ ������
		void ADDINTAIL(int data); // add � ����� �����
		void INSERT(int pos, int data);  // add � ��������� position
		void REVERSEPRINT();
		void DELETE(int pos); // delete elemnt

		void PRINT();
		
		void CLEAR();
	};
};