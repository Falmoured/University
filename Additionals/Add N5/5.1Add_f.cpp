#pragma once
#include <iostream>
#include "5.1Add_h.hpp"

namespace fal
{
    void input(int& n, int mas[N])
    {
        for (int i = 0; i < n; i++)
            std::cin >> mas[i];
    }

    void deleteAndDup(int& n, int mas[N], int& s, int& s1, int& sum, int& rs, int& h)
    {
        for (int i = 0; i < n; i++)
        {
            s = s1 = mas[i];
            rs = 1;
            sum = 0;

            while (s > 0)
            {
                h = s % 10;
                s = s / 10;
                sum += h;
                rs *= h;
            }

            if (sum == 18)
            {
                for (int j = i; j <= n - 1; j++)
                    mas[j] = mas[j + 1];
                n--;
                i--;
            }

            if (rs == 35)
            {
                n++;
                for (int j = n - 1; j >= i + 1; j--)
                    mas[j] = mas[j - 1];
                i++;
            }
        }
    }

    void output(int& n, int mas[N])
    {
        for (int i = 0; i < n; i++)
            std::cout << mas[i] << " ";
    }
}
