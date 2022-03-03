#include <3.1Functions.hpp>
#include <iostream>
#include <math.h>

namespace fal
{
	// 3.2
	double MathFunction(double x)
	{
		return std::sin(2 * x + 3);
	}

	double Bisection(double a, double b,double eps)
	{
		double lowF{ MathFunction(a) };
		while (1)
		{
			double x{ (a + b) / 2 };
			if ((abs(x - a) < eps) || (abs(x - b) < eps))
				return x;

			else if ((MathFunction(x) * lowF) > 0)
				a = x;
			else
				b = x;
		}
	}
	/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///

	// 3.1
	int StupidSearch(int N, int M, int* arr, int k)
	{
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				if (arr[j] == k)
					return j+1;
	}

	int BinarySearch(int low, int high, int M, int k, int* arr)
	{
		for (int i = 0; i < M; i++)
		{
			if (k < arr[low])
				return -1;
			if (k == arr[low])
				return 0;
			if (k > arr[high])
				return -1;

			int a{ low };
			int b{ high };

			while (a + 1 < b)
			{
				int c{ (a + b) / 2 };

				if (k > arr[c])
					a = c;
				else
					b = c;
			}
			if (arr[b] == k)
				return b;
			else
				return -1;
		}
	}

	void QuickSort(int low, int high, int* arr)
	{
		if (low >= high)
			return;

		int m, k, l, h;
		m = (rand()*rand()) % (high - low + 1) + low;
		k = arr[m];
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

	/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// 
	Timer::Timer() : m_beg(clock_t::now()) {}
	void Timer::reset() {
		m_beg = clock_t::now();
	}
	double Timer::elapsed() const {
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}


	void PrintArray(int high,int* arr)
	{
		for (int i = 0; i < high; i++)
			std::cout << arr[i] << std::endl;
	}
}