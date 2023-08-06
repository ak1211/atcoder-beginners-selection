// ABC081B - Shift only
#include <vector>
#include <iostream>
#include <algorithm>

bool even(long x)
{
    return x & 1 ? false : true;
}

long solver(std::vector<long> &v)
{
    long counter = 0;
    for (; std::all_of(v.begin(), v.end(), even); ++counter)
    {
        for (auto &a : v)
        {
            a >>= 1;
        }
    }
    return counter;
}

int main()
{
    long n;
    std::cin >> n;
    std::vector<long> v(n);
    for (auto &a : v)
    {
        std::cin >> a;
    }
    std::cout << solver(v) << std::endl;
    return 0;
}
