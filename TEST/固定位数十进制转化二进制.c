#include <stdio.h>

#define N 38
int main ()
{
    while (1){
        int x,i;
        scanf("%d", &x);
        int a[N] = {0};
        for (i =N-1 ; i>-1 ; i--)
        {
            if (x % 2 == 0) a[i]=0;
            else a[i] = 1;
            x/=2;
        }
        int judge = 0;
        for (i = 0; i < N; i++)
        {
            if (a[i] == 1) judge = 1;
            if (judge == 1) printf("%d",a[i]);
        }
        printf("\n");

    }
    return 0;
}