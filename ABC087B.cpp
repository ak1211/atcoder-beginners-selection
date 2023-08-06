// ABC087B - Coins
#include <iostream>

long solver(long A, long B, long C, long X)
{
    auto counter = 0;
    for (auto a = 0; a <= A; ++a)
    {
        for (auto b = 0; b <= B; ++b)
        {
            for (auto c = 0; c <= C; ++c)
            {
                if ((500 * a) + (100 * b) + (50 * c) == X)
                {
                    ++counter;
                }
            }
        }
    }
    return counter;
}

int main()
{
    long A, B, C, X;
    std::cin >> A >> B >> C >> X;
    std::cout << solver(A, B, C, X) << std::endl;
    return 0;
}
