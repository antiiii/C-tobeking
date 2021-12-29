#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main ()
{
    int a,b,m;
    char c[5];
    int n = 0;
    int *result,*judge;
    double *resultt;
    result = (int *)malloc(sizeof(int)*10);
    resultt = (double *)malloc(sizeof(double)*10);
    judge = (int *)malloc(sizeof(int)*10);
    while (scanf("%d %s %d", &a,c,&b) != EOF){
        if (c[0] == 43)
    {
        result[n] = a + b;
        judge [n] = 0;
    }
    else if (c[0] == 45)
    {
        result[n] = a - b;
        judge [n] = 0;
    }
    else if (c[0] == 42 && c[1] != 42)
    {
        result[n] = a * b;
        judge [n] = 0;  
    }
    else if (c[0] == 47 && c[1] != 42)
    {
        result[n] = a / b;
        judge [n] = 0;
    }
    else if (c[0] == 47 && c[1] == 42)
    {
        resultt[n] = a*1.0 / b*1.0;
        judge [n] = 1;
    }
    else if (c[0] == 42 && c[1] == 42)
    {
        result[n] = pow(a , b);
        judge [n] = 0;
    }
    else if (c[0] == 37)
    {
        result[n] = a % b;
        judge [n] = 0;
    }
    n++;
    }
    m = n;
    for (n = 0; n < m; n++)
    {
        if (judge[n] == 0)
        {
            printf("%d\n", result[n]);
        }
        else if (judge[n] == 1)
        {
            printf("%.3f\n", resultt[n]);
        }
    }
    free(result);
    free(resultt);
    free(judge);

    return 0;
}