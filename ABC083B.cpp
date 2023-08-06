// ABC083B - Some Sums
#include <cstdlib>
#include <iostream>

long sum_of_digits(long x)
{
    auto y = 0;
    while (x > 0)
    {
        auto n = std::div(x, 10L);
        x = n.quot;
        y = y + n.rem;
    }
    return y;
}

long solver(long N, long A, long B)
{
    auto summary = 0L;
    for (auto i = 1L; i <= N; ++i)
    {
        if (auto s = sum_of_digits(i); A <= s && s <= B)
        {
            summary += i;
        }
    }
    return summary;
}

int main()
{
    long N, A, B;
    std::cin >> N >> A >> B;
    std::cout << solver(N, A, B) << std::endl;
    return 0;
}
