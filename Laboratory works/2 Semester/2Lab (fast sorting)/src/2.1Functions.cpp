#include <iostream>
#include <2.1Functions.hpp>
#include <chrono>
#define N 5000

namespace fal
{
	void PrintArray(int* arr)
	{
		for (int i = 0; i < N; i++)
			std::cout << arr[i] << std::endl;
	}

	Timer::Timer() : m_beg(clock_t::now()) {}

	void Timer::reset()
	{
		m_beg = clock_t::now();
	}
	double Timer::elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
	

	void BubbleSort(int* arr)
	{
		for (int i = 1; i < N; i++)
		{
			if (arr[i] >= arr[i - 1])
				continue;

			int j{ i - 1 };

			while ((j > 0) && (arr[j] > arr[j + 1]))
			{
				std::swap(arr[j], arr[j + 1]);
				j = j - 1;
			}
		}
	}

	void QuickSort(int low, int high, int* arr)
	{
		if (low >= high)
			return;

		int m, k, l, h;
		m = rand() % high + 1; // генерируем рандомное число, но возвращаем его в диапазон от high+1(+1,т.к. изначально n-1)
		k = arr[m]; // почему при m > N не выдает ошибку (выход за пределы границ массива? xD)
		l = low - 1;
		h = high + 1;

		while (1)
		{
			do (l = l + 1); while (arr[l] < k);
			do (h = h - 1); while (arr[h] > k);
			if (l >= h)
				break;
			std::swap(arr[l], arr[h]);
		}

		h = l;
		l = l - 1;

		QuickSort(low, l, arr);
		QuickSort(h, high, arr);
	}
}