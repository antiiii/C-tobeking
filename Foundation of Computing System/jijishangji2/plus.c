#include <stdio.h>

void SWAP (double *p, double *q);
int main (void)
{
    int n, m, head;
    scanf ("%d", &n);
    double pmt[n];
    int judge = 1;

    for (int i = 0; i < n; i ++)
    {
        scanf("%lf", &pmt[i] );
    }
    
    for (int i = 0; i < n; i ++)
    {
        if (pmt[i] == 10) pmt[i] = 1.5;
        if (pmt[i] == -10) pmt[i] = -9.5;
        if (pmt[i] == -1) pmt[i] = -10;
        if (pmt[i] == -2) pmt[i] = -9;
        if (pmt[i] == -3) pmt[i] = -8;
        if (pmt[i] == -4) pmt[i] = -7;
        if (pmt[i] == -5) pmt[i] = -6;
        if (pmt[i] == -6) pmt[i] = -5;
        if (pmt[i] == -7) pmt[i] = -4;
        if (pmt[i] == -8) pmt[i] = -3;
        if (pmt[i] == -9) pmt[i] = -2;
    }
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n-1; j ++)
        {
            if ( pmt[j] > pmt[j+1] )
            {
                SWAP (&pmt[j], &pmt[j+1]);
            }
        }
    }
    while (judge == 1)
    {
        for (int i = 0; i < n; i ++)
        {
            if (pmt[i] == 1.5) printf ("10 ");
            else if (pmt[i] == -9.5) printf ("-10 ");
            else if (pmt[i] == -10) printf ("-1 ");
            else if (pmt[i] == -2) printf ("-9 ");
            else if (pmt[i] == -3) printf ("-8 ");
            else if (pmt[i] == -4) printf ("-7 ");
            else if (pmt[i] == -5) printf ("-6 ");
            else if (pmt[i] == -6) printf ("-5 ");
            else if (pmt[i] == -7) printf ("-4 ");
            else if (pmt[i] == -8) printf ("-3 ");
            else if (pmt[i] == -9) printf ("-2 ");
            else printf ("%.0f ", pmt[i]); 
        }
        printf ("\n");
        judge  = 0;
        for (int i = 1; i < n; i ++)
        {
            if (pmt[i] > pmt[i-1]) 
            {
                head = i;
                judge = 1;
            }    
        }
        m = n - head;// 找出最长递降数列

        int Wnumb = head-1;
        int Rnumb = head;
        for (int i = head + 1; i < n; i ++)
        {
            if (pmt[i] > pmt[Wnumb] && pmt[i] < pmt[Rnumb]) Rnumb = i;
        }
        SWAP (&pmt[Wnumb], &pmt[Rnumb] );// 交换

        double flip[m];
        for (int i = n-1; i >= head; i --)
        {
            flip[i - head] = pmt[i];
        }
        int j = 0;
        for (int i = n-1; i >= head; i --)
        {
            pmt[i] = flip [j];
            j++;
        }
    }
}

void SWAP (double *p, double *q)
{
    double t = *p;
    *p = *q;
    *q = t;
}