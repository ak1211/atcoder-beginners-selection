// ABC085B - Kagami Mochi
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

long solver(std::vector<long> &v)
{
    std::sort(v.begin(), v.end());
    long prev = v[0];
    return std::accumulate(v.begin(), v.end(), 1, [&prev](long acc, const long &d)
                           {
                               if (prev != d)
                               {
                                   prev = d;
                                   return acc+1;
                               }
                               else
                               {
                                   return acc;
                               } });
}

int main()
{
    long N;
    std::cin >> N;
    std::vector<long> v(N);
    for (auto &d : v)
    {
        std::cin >> d;
    }
    std::cout << solver(v) << std::endl;
    return 0;
}
