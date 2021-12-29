#include <stdio.h>

void yanghui1 (int a, int b, int *sum);
int main ()
{
    int a, b;
    int sum = 0;
    scanf ("%d %d", &a, &b);
    yanghui1 (a , b, &sum);
    printf ("%d\n", sum);
}

void yanghui1 (int a, int b, int *sum)
{
    if (b == 1 || b == a) *sum += 1;
    else
    {
        yanghui1 (a-1, b-1, sum);
        yanghui1 (a-1, b, sum);
    }
}
