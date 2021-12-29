#include <stdio.h>

void SWAP (int *p, int *q);
int main ()
{
    int n, m, head;
    scanf ("%d", &n);
    int pmt[n];

    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &pmt[i] );
    }

    for (int i = 1; i < n; i ++)
    {
        if (pmt[i] > pmt[i-1]) head = i;
    }
    { m = n - head; }// 找出最长递降数列

    int Wnumb = head-1;
    int Rnumb = head;
    for (int i = head + 1; i < n; i ++)
    {
        if (pmt[i] > pmt[Wnumb] && pmt[i] < pmt[Rnumb]) Rnumb = i;
    }
    SWAP (&pmt[Wnumb], &pmt[Rnumb] );// 交换

    int flip[m];
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

    for (int i = 0; i < n; i ++)
    {
        printf ("%d ", pmt[i]);
    }
}

void SWAP (int *p, int *q)
{
    int t = *p;
    *p = *q;
    *q = t;
}