#include <iostream>
#pragma comment(linker, "/STACK:40000000")
#include <2.1Functions.hpp>
#include <chrono>
#define N 5000

using namespace fal;

int main()
{
	int arr[N];
	for (int i = 0; i < N; i++)
		arr[i] = rand(); // массив из N элементов с рандомными числами
	
	 // std::cout << "not sorted: " << std::endl;
	 // PrintArray(arr);

	 Timer timer_quicksort;
	 QuickSort(0, N-1,arr); // N-1, т.к. массив начинает своей отсчет с нуля, а верхняя граница берется в самой ф-ии quicksort 
	 std::cout << "Quicksort time: " << timer_quicksort.elapsed() << '\n';

	// Timer timer_bubblesort;
	// BubbleSort(arr);
	// std::cout << "Bubblesort time: " << timer_bubblesort.elapsed() << '\n';

	 // std::cout << "sorted:" << std::endl;
	 // PrintArray(arr);

}