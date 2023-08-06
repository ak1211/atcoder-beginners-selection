// ABC085C - Otoshidama
#include <iostream>
#include <tuple>

std::tuple<long, long, long> solver(long N, long Y)
{
    for (long a = 0; a <= N; ++a)
    {
        for (long b = 0; b <= (N - a); ++b)
        {
            long c = N - a - b;
            if (10000 * a + 5000 * b + 1000 * c == Y)
            {
                return {a, b, c};
            }
        }
    }
    return {-1, -1, -1};
}

int main()
{
    long N, Y;
    std::cin >> N >> Y;
    auto [a, b, c] = solver(N, Y);
    std::cout << a << " " << b << " " << c << std::endl;
    return 0;
}
