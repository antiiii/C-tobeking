#include <stdio.h>
#include <math.h>

int calculate (int ,int );
int main (void)
{
    int n, t, sum;
    scanf("%d %d", &n, &t);
    for (int i = n; i > 0; i--)
    {
        sum += calculate (i , t);
    }
    printf ("%d", sum);   
}

int calculate (int n,int t)
{
    int sum = 0;
    if ( n > 0 )
    {
        sum = pow (10, n-1) * t + calculate (n-1, t);
    }

    return sum;
}