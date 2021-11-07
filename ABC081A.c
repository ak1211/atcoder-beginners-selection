/* ABC081A - Placing Marbles */
#include <stdio.h>
#include <string.h>

int main()
{
    char s[4];
    gets(s);
    int counter = 0;
    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] == '1')
        {
            counter++;
        }
    }
    printf("%d\n", counter);
    return 0;
}
