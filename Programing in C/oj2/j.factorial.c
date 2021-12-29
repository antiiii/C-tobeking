#include <stdio.h>

int main ()
{
    int n;
    long long ji = 1;
    long ji1 = 1;
    long he = 0;
    long he1 = 0;
    const long long yu = 10007;
    scanf("%d", &n);
    for (long i = n; i > 0; i--){
        for (long long cnt = 1,ji = 1; cnt <= i; cnt ++){
            ji *= cnt % yu;
            ji1 = ji % yu;
        }
        he += ji1 % yu;
        he1 = he % yu;
    }
    printf("%ld", he1);
}