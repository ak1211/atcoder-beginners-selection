/* ABC081B - Shift only */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

bool all(int64_t n, int64_t *a)
{
    for (int64_t i = 0; i < n; ++i)
    {
        if (a[i] & 1)
        {
            return false;
        }
    }
    return true;
}

void half(int64_t n, int64_t *a)
{
    for (int64_t i = 0; i < n; ++i)
    {
        a[i] = a[i] >> 1;
    }
}

int64_t solver(int64_t n, int64_t *a)
{
    int64_t counter = 0;
    while (all(n, a))
    {
        half(n, a);
        counter++;
    }
    return counter;
}

int main()
{
    static int64_t a[200];
    int64_t n;
    scanf("%ld", &n);
    for (int64_t i = 0; i < n; ++i)
    {
        scanf("%ld", &a[i]);
    }
    printf("%ld\n", solver(n, a));
    return 0;
}
