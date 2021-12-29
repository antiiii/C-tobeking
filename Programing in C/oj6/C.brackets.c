#include <stdio.h>
#include <string.h>

int main ()
{
    int n;
    scanf ("%d", &n);
    int judge[n];

    for (int j = 0; j < n; j++)
    {
        char array[101000] = {0};
        char stack[101000] = {0};
        scanf ("%s", array);
        int p = 0;
        int i = 0;

        while (array[i] != 0)
        {
            if (array[i] == ')' && stack[p-1] == '(')
                p--;
            else if (array[i] == ']' && stack[p-1] == '[')
                p--;
            else if (array[i] == '}' && stack[p-1] == '{')
                p--;
            else 
                stack[p++] = array[i];
            i++;     
        }

        if (p == 0) judge[j] = 1;
        else judge[j] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (judge[i] == 1) printf("True\n");
        else printf("False\n");
    }
}
