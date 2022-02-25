#include <chrono>

namespace fal
{
	// 3.1
	int BinarySearch(int low, int high, int M, int k,int* arr);

	void QuickSort(int low, int high, int* arr);

    int StupidSearch(int N, int M, int* arr, int k);

	void PrintArray(int high, int* arr);

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


	// 3.2
	double MathFunction(double x);

	double Bisection(double a, double b, double eps);
}