#include <iostream>
#include <chrono>

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::chrono::time_point<clock_t> m_beg;
public:
    Timer() : m_beg(clock_t::now())
    {}
    void reset()
    {
        m_beg = clock_t::now();
    }
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

int FACTORIAL(int n)
{
    int fac{ 1 };

    for (int i = 2; i <= n; i++)
        fac = fac * i;

    return fac;
}

int main()
{
    int n;
    std::cin >> n;

    Timer t;

    std::cout << FACTORIAL(n) << std::endl;
    std::cout << "Time taken: " << t.elapsed() << '\n';
}

/*
    Cложность алгоритма:
    В лучшем - тета(n)
    В среднем - тета(n)
    В худшем - тета(n)

    расчетное время - ~5*10^-4 sec
    среднее время - 4*10^-4 sec
*/
