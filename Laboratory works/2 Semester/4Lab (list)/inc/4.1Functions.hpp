#include <chrono>

namespace fal
{
    struct T_List
    {
        T_List* next;
        int age;
    };

    void ADD(T_List* head, int age);

    void DELETE(T_List* head, int max);

    void PRINT(T_List* head);

    void CLEAR(T_List* head);

    int MAXSEARCH(T_List* head);

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