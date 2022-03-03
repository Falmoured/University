#include <iostream>
#include <3.1Functions.hpp>
#include <string>
#pragma comment(linker, "/STACK:900000000000")
#define N 5000
#define M 5000

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

	// std::cout << "Not sorted: " << std::endl; // test вывожу чтобы брать числа для k 10116 - для 1000 элементов
	// PrintArray(N,arr); // test

	QuickSort(0, N-1, arr);

	 //std::cout << "Sorted: " << std::endl; // test
	 //PrintArray(N, arr); // test
	
	Timer binary_timer;
	for (int i = 0; i < 1000; i++)
		BinarySearch(0, N - 1, M, k, arr);

	std::cout << binary_timer.elapsed() << std::endl;

	Timer stupid_timer;
	for (int i = 0; i < 1000; i++)
		StupidSearch(N, M, arr, k);

	std::cout << stupid_timer.elapsed() << std::endl;

	// // // // // // // // // // // // // // // // // // // // // // // // // // // // 

	// 3.2
	std::cout << "Second task : " << std::endl;

	std::cout << "Result is : " << Bisection(0, 1, 1e-5) << std::endl;
}