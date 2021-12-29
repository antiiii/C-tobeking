#include <stdio.h>

void wtf (float *);
int main (void)
{
    int numb;
    scanf ("%x", &numb);
    printf("%d\n", numb);
    printf("%u\n", numb);
    wtf(&numb);

    return 0;
}
void wtf (float *x)
{
    printf("%f", *x);
}