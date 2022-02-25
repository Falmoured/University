/*
���� ����������� ����� N<10^6. �������� ��� ��������.
��������, 123 ����������� � 321.
�����, ����� �� ������ � ��� ���� �����. �.�. �������� ����� ����� � ������� ������.
*/

#include <iostream>

int Reverse(int n, int k)
{
	if (n < 10) 
		return k * 10 + n;

	return Reverse(n / 10, k * 10 + n % 10);
}

int main()
{
	int n;
	std::cin >> n;

	std::cout << Reverse(n, 0) << std::endl;
}

