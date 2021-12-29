#include <stdio.h>

int main (void)
{
    int x;
    scanf("%d", &x);
    int num[12] = { 0 };
    for (int i = 0; i < 10; i++)
    {
        num[i] = x % 10;
        x /= 10; 
    }

    for (int i = 9; i >= 0; i -= 3)
    {
        int judge = 0; 
        for (int j = 2; j >= 0; j--)
        {
            int judgehundred = 0;
            if ( j != 1 && num[i+j] != 0 )
            {
                if ( num[i+j] == 1 ) printf("One ");
                if ( num[i+j] == 2 ) printf("Two ");
                if ( num[i+j] == 3 ) printf("Three ");
                if ( num[i+j] == 4 ) printf("Four ");
                if ( num[i+j] == 5 ) printf("Five ");
                if ( num[i+j] == 6 ) printf("Six ");
                if ( num[i+j] == 7 ) printf("Seven ");
                if ( num[i+j] == 8 ) printf("Eight ");
                if ( num[i+j] == 9 ) printf("Nine ");
                judge = 1;
                if (j == 2 ) judgehundred = 1;
            }
            else if ( j == 1 && num[i+j] != 0 )
            {
                if ( num[i+j] == 1 ) printf("Ten ");
                if ( num[i+j] == 2 ) printf("Twenty ");
                if ( num[i+j] == 3 ) printf("Thirty ");
                if ( num[i+j] == 4 ) printf("Forty ");
                if ( num[i+j] == 5 ) printf("Fifty ");
                if ( num[i+j] == 6 ) printf("Sixty ");
                if ( num[i+j] == 7 ) printf("Seventy ");
                if ( num[i+j] == 8 ) printf("Eighty ");
                if ( num[i+j] == 9 ) printf("Ninety ");
                judge = 1;
            }
            if ( j == 2 && judgehundred == 1 ) printf("Hundred ");
        }
        if ( i == 3 && judge == 1 ) printf("Thousand ");
        if ( i == 6 && judge == 1 ) printf("Million ");
        if ( i == 9 && judge == 1 ) printf("Billion ");
    }
}