#include <stdio.h>

int main()
{
    long long t = 0;
    int n;
    long long sum = 0;
    scanf ("%d",&n);
    int a[n];
    int m =n;
    for ( ;n > 0; n--)
    {
        scanf ("%d",&a[n]);
    }
    for (n = m;n >0; n--)
    {
        t = n * (long long)a[n];
        sum += t;
    }
    printf ("%lld",sum);

    return 0;
}