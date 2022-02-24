#pragma once
#include <chrono>

namespace fal
{
	void PrintArray(int* arr);

	void QuickSort(int low, int high, int* arr);

	void BubbleSort(int* arr);

    class Timer {
    private:
        using clock_t = std::chrono::high_resolution_clock;
        using second_t = std::chrono::duration<double, std::ratio<1> >;
        std::chrono::time_point<clock_t> m_beg;
    public:
        Timer();
        void reset();
        double elapsed() const;
    };

}

