#include <iostream>
#include <3.1Functions.hpp>
#include <string>

using namespace fal;

int main()
{
	// 3.1
	std::cout << "First task : " << std::endl;

	int arr[6]{ 12,102,41,30,71,5 };

	std::cout << "Not sorted: " << std::endl;
	PrintArray(6,arr);

	QuickSort(0, 5, arr);

	std::cout << "Sorted: " << std::endl;
	PrintArray(6, arr);

	std::cout << "Plased on " << BinarySearch(0, 5, 102, arr) << " position \n" << std::endl;

	// // // // // // // // // // // // // // // // // // // // // // // // // // // // 

	// 3.2
	std::cout << "Second task : " << std::endl;

	std::cout << "Result is : " << Bisection(0, 1, 1e-5) << std::endl;
}