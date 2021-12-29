#include <stdio.h>
#include <math.h>

int main ()
{
    int x,n;
    scanf("%d %d", &n, &x);//2,3
    double sumsum = 0;
    for (int i = n; i >= 0; i--)
    {
        long long sum = 1;
        for(int index = i; index > 1; index--)
        {
            sum *= index;
        }
        sumsum += pow(x, i) / sum*1.0;
    } 
    printf("%.3f", sumsum); 
}