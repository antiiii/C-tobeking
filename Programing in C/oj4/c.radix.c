#include <stdio.h>
#include <math.h>

int convert (int, int );
int min (int );
int digit (int );
int main (void)
{
    int factora, factorb, product, scale;
    int judge = 0;
    scanf ("%d %d %d", &factora, &factorb, &product);
    if (min (factora) > min (factorb)) scale = min (factora);
    else scale = min (factorb);
    if (min (product) > scale) scale = min (product);
    for (scale++; (judge == 0) & (scale < 100); scale++)
    {
        if (convert (scale, factora) * convert (scale, factorb) == convert (scale, product)) judge = 1;
    }
    if ( judge == 1 ) printf ("%d", scale-1);
    else printf ("%d", judge);
}

int convert (int sl, int num)
{
    int digits = digit (num);
    int cvtnum = 0;
    for (int i = 0; i < digits; i++)
    {
        cvtnum += (num % 10) * pow (sl , i);
        num /= 10;
    }

    return cvtnum;
}

int min (int num)
{
    int minnum = 0;
    int digits = digit (num);
    for (int i = 0; i < digits; i++)
    {
        if (num % 10 > minnum) minnum = num % 10;
        num /= 10;
    }

    return minnum;   
}

int digit (int num)
{
    int digits = 0;
    while (num >= 1)
    {
        num /= 10;
        digits ++;
    }

    return digits;
}