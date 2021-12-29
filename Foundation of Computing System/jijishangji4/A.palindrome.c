#include <stdio.h>
#include <string.h>

#define MAX 120
int main (void)
{
    char string[MAX];
    gets(string);
    int i = strlen(string);
    int true = 1;
    for (int j = 0; j < i; j++)
    {
        if (!(string[j] == string[i-1-j]))
        {
            true = 0;
        }
    }
    if (true && strlen(string) % 2 == 0)
    {
        for (int j = 0; j < i/2; j++)
        printf("%c", string[j]);
    }
    else if (true && strlen(string) % 2 != 0)
    {
        for (int j = 0; j < i/2 + 1; j++)
        printf("%c", string[j]);
    }
    else
    {
        printf("%s", string);
    }

    return 0;
}