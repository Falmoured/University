#include <iostream>
#include <tree.hpp>

namespace fal
{
	// ������������� �������
	Elem* MAKE(int data, Elem* p)
	{
		Elem* q = new Elem; // �������� ������
		q->data = data;
		q->left = nullptr;
		q->right = nullptr;
		q->parent = p; // �- ������� , p - ��������
		return q;
	}

	// ���������� �������� � �������� ������
	void ADD(int data, Elem*& root)
	{
		if (root == nullptr)
		{
			root = MAKE(data, nullptr);
			return;
		}

		Elem* v = root;
		while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))
			if (data < v->data)
				v = v->left;
			else
				v = v->right;
		if (data == v->data)
			return;
		Elem* u = MAKE(data, v);
		if (data < v->data)
			v->left = u;
		else
			v->right = u;
	}

	// ����� ������ (��������)
	void PASS(Elem* v)
	{
		if (v == nullptr)
			return;
		// ���������� (������ ������ 1 ����)
		// std::cout << v->data << std::endl;
		PASS(v->left);
		// ��������� ������ (������ �� ��������)
		 std::cout << v->data << std::endl;
		PASS(v->right);
		// ����������� ������ (������ ���������)
		// std::cout << v->data << std::endl;
	}

	Elem* SEARCH(int data, Elem* v) // v - ,    
	{
		if (v == nullptr)
			return v;
		if (v->data == data)
			return v;
		if (data < v->data)
			return SEARCH(data, v->left);
		else
			return SEARCH(data, v->right);
	}


	void DELETE(int data, Elem*& root)
	{
		// �������� �� ������������ ������ ���������
		Elem* u = SEARCH(data, root);
		if (u == nullptr)
			return;

		// �������� ����� (������ ������)((������ ����� 1 ������ � �������))
		if (u->left == nullptr && u->right == nullptr && u == root)
		{
			delete root; // ������� Delete �� ������� ������, � ���� ���� ����� ������
			root = nullptr; // ������ 
			return;
		}

		// ����������� ������ �������
		if (u->left != nullptr && u->right != nullptr && u == root) // todo ������
		{
			Elem* t = u->right;
			while (t->left != nullptr)
				t = t->left;
			u->data = t->data;
			u = t;
		}

		// ����������� ����� �������
		if (u->left != nullptr && u->right != nullptr && u == root) // todo ������
		{
			Elem* t = u->left;
			while (t->right != nullptr)
				t = t->right;	
			u->data = t->data;
			u = t;
		}

		// ����������� ��� �������
		if (u->left != nullptr && u->right != nullptr) // todo ������
		{
			Elem* t = u->right;
			while (t->left != nullptr)
				t = t->left;
			u->data = t->data;
		}

			Elem* t;
			if (u->left == nullptr)
				t = u->right;
			else
				t = u->left;
			if (u->parent->left == u)
				u->parent->left = t;
			else
				u->parent->right = t;
			if (t != nullptr)
				t->parent = u->parent;
			delete u;
	
	}

	void CLEAR(Elem*& root)
	{
		if (root == nullptr)
			return;
		// 

		CLEAR(root->left);
		// 

		CLEAR(root->right);

		// 
		delete root;
		root = nullptr;
	}

	void SEARCHPOS(int data, Elem* v, int c) // v - ������� ������ root, � �������� �������� �����
	{
		if (v == nullptr)
		{
			std::cout << 'n' << std::endl;
			return;
		}
		if (v->data == data)
		{
			std::cout << c;
			return; // ������������ ��������� �� �������, � �� �������� (!)
		}
		if (data < v->data)
			return SEARCHPOS(data, v->left, c + 1);
		else
			return SEARCHPOS(data, v->right, c + 1);
	}
}