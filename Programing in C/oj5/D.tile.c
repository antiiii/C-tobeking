#include <stdio.h>

void Fibonacci (int fibo[40], int n);
int main ()
{
    int n;
    int fibo[40] = {1, 2};
    scanf ("%d", &n);
    Fibonacci (fibo, 2);
    printf ("%d", fibo[n-1]);
}

void Fibonacci (int fibo[40], int n)
{
    if (n < 40) 
    {
        fibo[n] = fibo[n-1] + fibo[n-2];
        Fibonacci (fibo, n+1);
    }    
}