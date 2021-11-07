/* ABC086A - Product */
#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t a, b;
    scanf("%d %d", &a, &b);
    (a * b % 2) ? puts("Odd") : puts("Even");
    return 0;
}
