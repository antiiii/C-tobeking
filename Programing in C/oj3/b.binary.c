#include <stdio.h>
#include <math.h>

int main (void)
{
    int n;
    scanf("%d",&n);
    char binary[n];
    getchar ();
    scanf("%s",binary);

    for (int i = 0; i < n; i++)
    {
        binary[i] = binary[i] -48;
    }

    int sum =0;
    for (int i=n-1; i >= 0; i--) 
    {
        sum += binary[i] * pow(2,n-i-1);
    }
    printf("%d\n",sum);
}