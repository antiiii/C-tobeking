/* INPUT:
2 1
0 1 1
-1 1
OUTPUT:
0.666667
*/
#include <stdio.h>
#include <math.h>

double n,p;
double function[21] = {0};
double Integral;
void Integration (double , double , double );
double Simpson(double , double );
double Result (double );
double Value (double , double , double );
int main ()
{
    double min;
    double max;
    double precision = pow (10, -6);
    scanf ("%lf %lf", &n, &p);
    for (int i = 0; i <= n; i++) scanf ("%lf", &function[i]);
    scanf ("%lf %lf", &min, &max);
    Integration (min, max, precision);
    printf ("%f", Integral);

    return 0;
}

void Integration (double min, double max, double precision)
{
    double sl = Simpson(min, (max + min) / 2);
    double sr = Simpson((max + min) / 2, max);
    double s = Simpson(min, max);
    if (Value(sl, sr, s) <= 15 * precision)
    {
        Integral += sl + sr + (sl + sr - s) / 15;
    }
    else 
    {
        Integration (min, (min + max) / 2, precision/2);
        Integration ((min + max) / 2, max, precision/2);
    }
}

double Simpson(double min, double max)
{
    double sum = 0;
    sum += 4 * Result((min+max)/2);
    sum += Result(min);
    sum += Result(max);
    sum /= 6;
    sum *= (max - min);

    return sum;
}

double Result (double x)
{
    double sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += function[i] * pow (x, i);
    }
    sum = pow(sum, p);
    
    return sum;
}

double Value (double sl, double sr, double s)
{
    double sum;
    sum = sl + sr - s;
    if (sum < 0) sum = -sum;

    return sum;
}