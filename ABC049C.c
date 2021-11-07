/* ABC049C - Daydream */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

bool walk(const char *s, const size_t length, size_t offset)
{
    static const char *words[4] = {"dream", "dreamer", "erase", "eraser"};

    if (length == offset)
        return true;
    else if (length < offset)
        return false;
    else
    {
        for (int32_t i = 0; i < 4; ++i)
        {
            size_t len = strlen(words[i]);
            if (strncmp(words[i], &s[offset], len) == 0)
            {
                if (walk(s, length, offset + len))
                    return true;
            }
        }
        return false;
    }
}

bool solver(char *s)
{
    return walk(s, strlen(s), 0);
}

int main()
{
    static char s[100001];
    gets(s);
    printf("%s\n", solver(s) ? "YES" : "NO");
    return 0;
}
