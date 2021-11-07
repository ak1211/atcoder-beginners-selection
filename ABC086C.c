/* ABC086C - Traveling */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define abs(x) ((x) < 0 ? (-(x)) : (x))

struct Coord
{
    int32_t x, y;
};

int32_t distance(struct Coord a, struct Coord b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

struct TXY
{
    int32_t t;
    struct Coord c;
};

bool solver(int32_t N, struct TXY A[])
{
    struct TXY previous = {0};
    for (int32_t i = 0; i < N; ++i)
    {
        int32_t dt = A[i].t - previous.t;
        int32_t dist = distance(A[i].c, previous.c);
        if (dt < dist)
            return false;
        else if ((dt - dist) % 2 != 0)
            return false;
        previous = A[i];
    }
    return true;
}

int main()
{
    static struct TXY A[100000];
    int32_t N;
    scanf("%d", &N);
    for (int32_t i = 0; i < N; ++i)
    {
        scanf("%d %d %d", &A[i].t, &A[i].c.x, &A[i].c.y);
    }
    solver(N, A) ? puts("Yes") : puts("No");
    return 0;
}
