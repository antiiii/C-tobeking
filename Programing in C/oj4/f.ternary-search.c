#include <stdio.h>
#include <math.h>

double RESULT (double, int *cfc, int);
double THREEDIVIDE (double *, double *, int *cfc, int);
int main (void)
{
    int N;
    double l, r;
    scanf ("%d", &N);
    int cfc[N+1];
    for (int i = 0; i <= N; i++)
    {
        scanf ("%d", &cfc[i]);
    }
    scanf ("%lf %lf", &l, &r);

    printf ("%.6f", THREEDIVIDE (&l, &r, cfc, N));
}

double THREEDIVIDE (double *l, double *r, int *cfc, int N)
{
    double x;
    while (*r - *l > 0.000002)
    {
        double p1 = *l + (*r - *l) / 3;
        double p2 = *r - (*r - *l) / 3;
        if (RESULT (p1, cfc, N) > RESULT (p2, cfc, N))
        {
            *r = p2;
        }
        else
        {
            *l = p1;
        }
        { x = *l + (*r - *l) / 2; }
        if (*r - *l > 0.000002) x = THREEDIVIDE (l, r, cfc, N);
    }

    return x;
}

double RESULT (double x, int *cfc, int N)
{
    double value = 0;
    for (int i = N; i >= 0; i--)
    {
        value += cfc[N-i] * pow(x, i);
    }

    return value;
}