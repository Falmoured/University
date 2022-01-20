#include <iostream>
#include "5.1Add_f.hpp"
#define N 10000

int main()
{
    int h, s, s1, n;
    int sum = 0;
    int rs = 1;
    int mas[N];
    
    std::cin >> n;
    fal::input(n, mas);

    fal::deleteAndDup(n, mas, s, s1, sum, rs, h);

    fal::output(n, mas);

}
