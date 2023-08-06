// ABC088B - Card Game for Two
#include <iostream>
#include <vector>
#include <algorithm>

long solver(std::vector<long> &A, long N)
{
    std::sort(A.begin(), A.end(), std::greater<long>{});
    auto alice = 0L;
    auto bob = 0L;
    for (auto i = 0L; i < N; i += 2)
    {
        alice += A[i];
        bob += A[i + 1];
    }
    return alice - bob;
}

int main()
{
    long N;
    std::cin >> N;
    std::vector<long> A(100);
    for (auto i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    std::cout << solver(A, N) << std::endl;
    return 0;
}
