#include <stdio.h>
#include <string.h>

#define N 50
void Two (long long x);
long long Ten (char n[N]);
int main ()
{
    while (1)
    {
        char dividend[N] = {0};
        char divisor[N] = {0};
        long long remainder, quotient;
        scanf ("%s %s", dividend, divisor);
        long long ten_dividend = Ten(dividend);
        long long ten_divisor = Ten(divisor);
        quotient = ten_dividend / ten_divisor;
        remainder = ((double) Ten(dividend) / (double) ten_divisor - quotient) * ten_divisor + 0.01;
        Two (quotient);
        if (quotient == 0) printf ("0");
        printf ("\n");
        for (int i = 0; dividend[i] != 0; i++) printf("%c", dividend[i]); 
        int digit1 = 0;
        int digit2 = 0;
        for (long long i = 1; ten_divisor >= i; i*=2)
        { 
            digit1++;
        }
        for (long long i = 1; remainder >= i; i*=2) digit2++;
        for (int i = 0; i < digit1 - digit2; i++) printf("0"); 
        Two (remainder);
        printf ("\n");    
    }
}

long long Ten (char n[N])
{
    int digits = 0;
    while (n[digits] != 0) digits++; 
    long long  sum =0;
    for (int i=digits-1; i >= 0; i--) 
    {
        sum += (n[i]-48) * pow(2,digits-i-1);
    }
    return sum;
}

void Two (long long x)
{
    int i;
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
}
//11111111111111111111111111111111111111