#include <iostream>

int main()
{
    int i, j, k;
    int s{ 0 };
    char c[6];

    for (i = 1; i <= 999999; i++)
    {
        for (k = i, j = 0; j < 6; j++, k /= 10)
            c[j] = k % 10;

        if (c[0] + c[1] + c[2] == c[3] + c[4] + c[5])
            s += 1;
    }

    std::cout << s << std::endl;
    return 0;
}
