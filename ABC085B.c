/* ABC085B - Kagami Mochi */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t compare(const void *x, const void *y)
{
    return *(int32_t *)x - *(int32_t *)y;
}

int32_t solver(int32_t N, int32_t *d)
{
    qsort(d, N, sizeof(int32_t), compare);
    int32_t counter = 1, prev = d[0];
    for (int32_t i = 0; i < N; ++i)
    {
        if (prev != d[i])
        {
            prev = d[i];
            ++counter;
        }
    }
    return counter;
}

int main()
{
    static int32_t d[100];
    int32_t N;
    scanf("%d", &N);
    for (int32_t i = 0; i < N; ++i)
    {
        scanf("%d", &d[i]);
    }
    printf("%d\n", solver(N, d));
    return 0;
}
