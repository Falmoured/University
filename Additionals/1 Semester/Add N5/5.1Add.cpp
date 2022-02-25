#include <iostream>
#include "5.1Add_f.hpp"
#define N 10000

int main()
{
    int n;
    int mas[N];
    
    std::cin >> n;
    fal::input(n, mas);

    fal::deleteAndDup(n, mas);

    fal::output(n, mas);

}
