#include <stdio.h>

int main (void)
{
    char str[13] = "hello world!";
    str[13] = 0;
    
    char *p;
    p = str;
    while (*p != ' ')
    {
        printf("%c", *p - 'a' + 'A');
        p++;
    }
} 