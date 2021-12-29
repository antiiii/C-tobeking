#include <stdio.h>

int main ()
{
    int times;
    scanf ("%d", &times);
    char stack[10000] = {0};
    int p = -1;
    char operation[times][10];
    char data[times];
    for (int i = 0; i < times; i++)
    {
        scanf ("%s", operation[i]);
        if (operation[i][1] == 'u')
        {
            getchar();
            scanf ("%c", &data[i]);
        }
    }

    for (int i = 0; i < times; i++)
    {
        if (operation[i][1] == 'u') 
        {
            p++;
            stack[p] = data[i];
        }    
        
        else if (operation[i][1] == 'o' && operation[i][0] == 'p')
        {
            if (stack[p] == 0)
            {
                printf ("Empty\n");
            }
            else p--;
        }

        else if (operation[i][0] == 't')
        {
            if (stack[p] == 0)
            {
                printf ("Empty\n");
            }
            else printf ("%c\n", stack[p]);
        }

        else if (operation[i][1] == 'r')
        {
            for (int j = p; j >= 0; j--)
            {
                printf ("| %c |\n", stack[j]);
            }
            printf ("|===|\n");
        }
    }
    // for (int i = 0; i < times; i++)
    // {
    //     scanf ("%s", operation);
    //     if (operation[1] == 'u') 
    //     {
    //         p++;
    //         getchar ();
    //         scanf ("%c", &data);
    //         stack[p] = data;
    //     }    
        
    //     else if (operation[1] == 'o' && operation[0] == 'p')
    //     {
    //         if (stack[p] == 0)
    //         {
    //             printf ("Empty\n");
    //         }
    //         else p--;
    //     }

    //     else if (operation[0] == 't')
    //     {
    //         if (stack[p] == 0)
    //         {
    //             printf ("Empty\n");
    //         }
    //         else printf ("%c\n", operation[p]);
    //     }

    //     else if (operation[1] == 'r')
    //     {
    //         for (int j = p; j >= 0; j--)
    //         {
    //             printf ("| %c |\n", stack[j]);
    //         }
    //         printf ("|===|\n");
    //     }
    // }
}