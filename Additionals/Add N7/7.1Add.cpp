#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    std::vector<int> vec{ 36, 17, 4, 70 };

    for (int i = 0; i < vec.size(); i++)
    {
        int x, pr{ 1 }, ost;

        x = vec[i];

        while (x > 0)
        {
            ost = x % 10;
            x = x / 10;
            pr = pr * ost;
        }

        if (pr % 18 == 0)
            vec.erase(vec.begin() + i);
    }

    int newsize = vec.size();

    for (int i = 0; i < newsize; i++)
    {
        int x, ost;
        bool f7{ 0 }, f0{ 0 };

        x = vec[i];

        while (x > 0)
        {
            ost = x % 10;

            if (ost == 7)
                f7 = 1;
            if (ost == 0)
                f0 = 1;

            x = x / 10;
        }

        if ((f7 == 1) && (f0 == 0))
        {
            vec.insert(vec.end(), vec[i]);
        }
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";

    return 0;
}

