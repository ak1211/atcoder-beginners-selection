/* ABC088B - Card Game for Two */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t compare(const void *x, const void *y)
{
    return *(int32_t *)y - *(int32_t *)x;
}

int32_t solver(int32_t N, int32_t *A)
{
    qsort(A, N, sizeof(int32_t), compare);
    int32_t alice = 0, bob = 0;
    for (int32_t i = 0; i < N; i += 2)
    {
        alice += A[i];
        bob += A[i + 1];
    }
    return alice - bob;
}

int main()
{
    static int32_t A[100];
    int32_t N;
    scanf("%d", &N);
    for (int32_t i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    printf("%d\n", solver(N, A));
    return 0;
}
