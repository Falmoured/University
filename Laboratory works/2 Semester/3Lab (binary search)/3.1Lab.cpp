#include <iostream>
#include <3.1Functions.hpp>
#include <string>
#define N 1000
#define M 1000

using namespace fal;

int main()
{
	// 3.1
	std::cout << "First task : " << std::endl;

	int arr[N]{ };
	for (int i = 0; i < N; i++)
		arr[i] = rand();

	std::cout << "Please, enter what are you searching for: " << std::endl;
	int k;
	std::cin >> k; // 12508 7376

	std::cout << "Not sorted: " << std::endl; // test вывожу чтобы брать числа для k 10116 - для 1000 элементов
	PrintArray(N,arr); // test

	QuickSort(0, N-1, arr);

	// std::cout << "Sorted: " << std::endl; // test
	// PrintArray(N, arr); // test
	
	Timer binary_timer;
	std::cout << "Plased on " << BinarySearch(0, N - 1, M, k, arr) + 1 << " position - (BinarySearch) for " << binary_timer.elapsed() << "\n" << std::endl; // + 1 чтобы нулевой позиции не было
	
	Timer stupid_timer;
	std::cout << "Plased on " << StupidSearch(N, M, arr, k) << " position - (StupidSearch) for " << stupid_timer.elapsed() << "\n" << std::endl;

	// // // // // // // // // // // // // // // // // // // // // // // // // // // // 

	// 3.2
	std::cout << "Second task : " << std::endl;

	std::cout << "Result is : " << Bisection(0, 1, 1e-5) << std::endl;
}