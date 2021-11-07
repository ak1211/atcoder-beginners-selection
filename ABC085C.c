/* ABC085C - Otoshidama */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct S
{
    int32_t a, b, c;
};

struct S solver(int32_t N, int32_t Y)
{
    struct S r;
    for (r.a = 0; r.a <= N; ++r.a)
    {
        for (r.b = 0; r.b <= (N - r.a); ++r.b)
        {
            r.c = N - r.a - r.b;
            if (10000 * r.a + 5000 * r.b + 1000 * r.c == Y)
            {
                return r;
            }
        }
    }
    r.a = r.b = r.c = -1;
    return r;
}

int main()
{
    int32_t N, Y;
    scanf("%d %d", &N, &Y);
    struct S s = solver(N, Y);
    printf("%d %d %d\n", s.a, s.b, s.c);
    return 0;
}
