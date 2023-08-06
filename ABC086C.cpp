// ABC086C - Traveling
#include <iostream>
#include <tuple>
#include <vector>

using XY = std::pair<long, long>;

long distance(XY a, XY b)
{
    const auto [ax, ay] = a;
    const auto [bx, by] = b;
    return std::abs(ax - bx) + std::abs(ay - by);
}

using TXY = std::pair<long, XY>;

bool solver(std::vector<TXY> &A)
{
    TXY previous = {};
    for (const auto &[t, xy] : A)
    {
        auto dt = t - std::get<0>(previous);
        auto dist = distance(xy, std::get<1>(previous));
        if (dt < dist)
            return false;
        else if ((dt - dist) % 2 != 0)
            return false;
        previous = {t, xy};
    }
    return true;
}

int main()
{
    long N;
    std::cin >> N;
    std::vector<TXY> A(N);
    for (auto &a : A)
    {
        long n, x, y;
        std::cin >> n >> x >> y;
        a = {n, {x, y}};
    }
    std::cout << (solver(A) ? "Yes" : "No") << std::endl;
    return 0;
}
