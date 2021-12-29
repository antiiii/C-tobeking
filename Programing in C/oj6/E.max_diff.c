#include <stdio.h>

int main (void)
{
    int array[200] = {0};
    int i = 0;
    while (scanf("%d", &array[i]) != EOF) i++;
    int max = array[0];
    for (int j = 1; j < i; j++)
    {
        if (array[j] > max) max = array[j];
    }
    if (array[0] > array[i-1]) printf("%d", max - array[i-1]);
    else printf("%d\n", max - array[0]);
}