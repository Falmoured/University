#include <iostream>
#define N_Max 100000

void SWAPSORT(int mas[N_Max], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (mas[i] > mas[j])
				std::swap(mas[i], mas[j]);
}

/*
* SWAP
int t = mas[i]
mas[i] = mas[j]
mas[j] = t
*/

int main()
{
	srand(time(0));
	int mas[N_Max];
	for (int i = 0; i < N_Max; i++)
		mas[i] = rand();

	// Swap Sort

	SWAPSORT(mas, N_Max);

	for (int i = 0; i < N_Max; i++)
		std::cout << mas[i] << std::endl;

}