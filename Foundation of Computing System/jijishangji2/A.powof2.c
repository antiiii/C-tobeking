#include <stdio.h>
#include <math.h>

int main ()
{
    int x;
    scanf ("%d", &x);
    int wtf[31000] = {0};
    wtf [1] = 1;
    int k = 1;

    for (int i = 0; i < x; i++)
    {
        int carry = 0;
        for (int j = 1; j <= k; j++)
        {   
            wtf [j] = wtf [j] * 2 + carry;
            if (carry ) carry = 0;
            if ( wtf [j] >= 10)
            {
                carry = 1;
                wtf[j] = wtf[j] % 10; 
                if (j == k) k++;
            }
        }
    }

    int i = 30999; 
    for ( ; wtf[i] == 0; i--);
    for ( ; i > 0; i--) printf ("%d", wtf[i]);
} 