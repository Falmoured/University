#include <iostream>
#include <tree.hpp>

namespace fal
{
	// инициализация вершины
	Elem* MAKE(int data, Elem* p)
	{
		Elem* q = new Elem; // выделяем память
		q->data = data;
		q->left = nullptr;
		q->right = nullptr;
		q->parent = p; // й- вершина , p - родитель
		return q;
	}

	// Добавление элемента в бинарное дерево
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

	// Обход дерева (рекурсия)
	void PASS(Elem* v)
	{
		if (v == nullptr)
			return;
		// Префиксный (корень всегда 1 элем)
		// std::cout << v->data << std::endl;
		PASS(v->left);
		// Инфиксный подход (корень по середине)
		 std::cout << v->data << std::endl;
		PASS(v->right);
		// Постфиксный подход (корень последний)
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
		// Проверка на сущестование такого эелемента
		Elem* u = SEARCH(data, root);
		if (u == nullptr)
			return;

		// Удаление корня (особый случай)((только когда 1 корень и остался))
		if (u->left == nullptr && u->right == nullptr && u == root)
		{
			delete root; // функция Delete не очищает память, а лишь дает снова доступ
			root = nullptr; // чистка 
			return;
		}

		// Присутсвует правый потомок
		if (u->left != nullptr && u->right != nullptr && u == root) // todo Убрать
		{
			Elem* t = u->right;
			while (t->left != nullptr)
				t = t->left;
			u->data = t->data;
			u = t;
		}

		// Присутсвует левый потомок
		if (u->left != nullptr && u->right != nullptr && u == root) // todo Убрать
		{
			Elem* t = u->left;
			while (t->right != nullptr)
				t = t->right;	
			u->data = t->data;
			u = t;
		}

		// Присутсвуют оба потомка
		if (u->left != nullptr && u->right != nullptr) // todo Убрать
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

	void SEARCHPOS(int data, Elem* v, int c) // v - элемент обычно root, с которого начинаем поиск
	{
		if (v == nullptr)
		{
			std::cout << 'n' << std::endl;
			return;
		}
		if (v->data == data)
		{
			std::cout << c;
			return; // возвращается указатель на вершину, а не значение (!)
		}
		if (data < v->data)
			return SEARCHPOS(data, v->left, c + 1);
		else
			return SEARCHPOS(data, v->right, c + 1);
	}
}