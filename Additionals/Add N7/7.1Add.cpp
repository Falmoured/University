﻿#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int sum{ 0 }, rs{ 1 }, s{}, h{};
    std::vector<int> vec{ 75, 99, 56, 99, 342 };

    for (int i = 0; i < vec.size(); i++)
    {
        s = vec[i];
        sum = 0;

        while (s > 0)
        {
            h = s % 10;
            s = s / 10;
            sum += h;
        }

        if (sum == 18) {
            vec.erase(vec.begin() + i);
        }
    }

    int size = vec.size();
    for (int i = 0; i < size; i++)
    {

        s = vec[i];
        rs = 1;


        while (s > 0)
        {
            h = s % 10;
            s = s / 10;
            rs *= h;
        }

        if (rs == 35)
        {
            vec.insert(vec.end(), vec[i]);
        }
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";

    return 0;
}

