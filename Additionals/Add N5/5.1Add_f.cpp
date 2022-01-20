#pragma once
#include <iostream>
#include "5.1Add_f.hpp"
#define N 10000

namespace fal
{
    void input(int& n, int mas[N])
    {
        for (int i = 0; i < n; i++)
            std::cin >> mas[i];
    }

    void deleteAndDup(int& n, int mas[N])
    {
        int pr, x;
        bool f7, f0;

        for (int i = 0; i < n; i++)
        {
            x  = mas[i];
            pr = 1; f7 = 0; f0 = 0;
            int ost;

            while (x > 0)
            {
                ost = x % 10;

                if (ost == 7)
                    f7 = 1;
                if (ost == 0)
                    f0 = 1;

                x = x / 10;
                pr = pr * ost;
            }

            if (pr % 18 == 0)
            {
                for (int j = i; j < n; j++)
                    mas[j] = mas[j + 1];
                n--;
                i--;
            }

            if ((f7 == 1) && (f0 == 0))
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
