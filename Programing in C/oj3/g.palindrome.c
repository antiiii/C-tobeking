#include <stdio.h>

int main ()
{
    int n;
    scanf ("%d", &n);
    char line[n];
    scanf ("%s", line);

    for (int i = 0; i < n; i++)
    {
        if (line[i] == '?') line[i] = line[n-1-i];
    }
    
    printf ("%s", line);
}