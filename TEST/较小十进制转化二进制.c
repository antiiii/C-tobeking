#include <stdio.h>

int main ()
{
    int x,i;
    int sum = 0;
    scanf("%d", &x);
    for (i =0 ; x > 0; i++)
    {
        if (x % 2 != 0) sum += pow(10, i);
        x/=2;
    }
    printf("%d\n" ,sum);

    return 0;
}