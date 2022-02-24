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

unsigned __int64 FACTORIAL(int n)
{
    unsigned __int64 fac{ 1 };
    
    for (int i = 2; i < n+1; i++) // n-2 �������� (-2 �� ������ ����)
        fac = fac * i; // 2 ��������

    return fac;
}

int main()
{
    int n;
    std::cin >> n;

    Timer t;
    std::cout << "Time taken: " << t.elapsed() << '\n';�
    std::cout << FACTORIAL(n) << std::endl;
    
}

/*
    C�������� ���������:
    � ������ - ����(n)
    � ������� - ����(n)
    � ������ - ����(n)

    ��������� ����� - ~1*10^-4 sec
    ������� ����� - 1*10^-4 sec
*/
