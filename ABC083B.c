/* ABC083B - Some Sums */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t sum_of_digits(int32_t x)
{
    int32_t y = 0;
    for (; x; x /= 10)
        y += x % 10;
    return y;
}

int32_t solver(int32_t N, int32_t A, int32_t B)
{
    int32_t summary = 0;
    for (int32_t i = 1; i <= N; ++i)
    {
        int32_t s = sum_of_digits(i);
        if (A <= s && s <= B)
        {
            summary += i;
        }
    }
    return summary;
}

int main()
{
    int32_t N, A, B;
    scanf("%d %d %d", &N, &A, &B);
    printf("%d\n", solver(N, A, B));
    return 0;
}
