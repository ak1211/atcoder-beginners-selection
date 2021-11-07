/* ABC087B - Coins */
#include <stdio.h>
#include <stdint.h>

int32_t solver(int32_t A, int32_t B, int32_t C, int32_t X)
{
    int32_t counter = 0;
    for (int32_t a = 0; a <= A; ++a)
    {
        for (int32_t b = 0; b <= B; ++b)
        {
            for (int32_t c = 0; c <= C; ++c)
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
    int32_t A, B, C, X;
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &X);
    printf("%d\n", solver(A, B, C, X));
    return 0;
}
