#include <iostream>

namespace fal
{
	struct Elem
	{
		int data;
		Elem* left;
		Elem* right;
		Elem* parent;
	};

	Elem* MAKE(int data, Elem* p);

	void ADD(int data, Elem*& root);

	void PASS(Elem* v);

	Elem* SEARCH(int data, Elem* v);

	void SEARCHPOS(int data, Elem* v, int c);
	 
	void DELETE(int data, Elem*& root);

	void CLEAR(Elem*& root);
}