#include <stdio.h>

int main ()
{
    int n,m;
    long long x = 0;
    long long sum = 0;
    scanf("%d", &n);
    m = n;
    for ( ;n > 0; n--)
    {
        sum += 2*n;
    }
    for (n = 2*m-1; n > 0; n--)
    {
        scanf("%lld",&x);
        sum -= x;
    }
    printf ("%lld",sum);

    return 0;
}