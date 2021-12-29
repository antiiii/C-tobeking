#include <stdio.h>

int n;
int numb[30] = {0};
void search(int, int, int);
int main ()
{
    scanf ("%d", &n);
    search (n, 1, 0);
}

void search (int remain, int origin, int num)
{
    if (remain == 0)
    {
        for (int i = 0; i < num; i++) printf ("%d ", numb[i]);
        printf ("\n");
    }
    for (int i = origin; remain >= i; i++)
    {
        numb[num] = i;
        search(remain - i, i, num+1);
    }
}