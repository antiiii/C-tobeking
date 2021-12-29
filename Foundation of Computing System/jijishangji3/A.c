#include <stdio.h>
#include <string.h>

int main (void)
{
    
        char str[10000] = {0};
        char stack[10000] = {0};
        scanf ("%s", str);
        int p = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == '}' && stack[p-1] == '{' && stack[p-2] == '{')
            {
                p--;
                for (int j = p; j < p + 3; j++) stack[j] = '\0';
                stack[p-1] = '*';
            } 
            else if (str[i] == '}' && stack[p-1] == '{' && str[i+1] == '}')
            {
                p --;
                for (int j = p; j < p + 3; j++) stack[j] = '\0';
                stack[p] = '/';
            }

            else if (str[i] == '}' && stack[p-2] == '{' && stack[p-1] >= 48 && stack[p-1] <= 57)
            {
                int times = stack[p-1] - 48;
                for (int j = p-3; j < p - 3 + times; j++) stack[j] = stack[p-3];
                p = p - 3 + times;
                for (int j = p; j < p + 3; j++) stack[j] = '\0';
            }  

            else if (str[i] == '}' && stack[p-3] == '{' && stack[p-1] >= 48 && stack[p-1] <= 57 && stack[p-2] >= 48 && stack[p-2] <=57)
            {
                int times = (stack[p-1] - 48) + (stack[p-2] - 48) * 10;
                for (int j = p-4; j < p - 4 + times; j++) stack[j] = stack[p-4];
                p = p - 4 + times;
            }

            else 
            {
                stack[p] = str[i];
                p++;
            }   

        }
        for (int i = 0; stack[i] != '\0'; i++)
        {
            if (stack[i] == '*') printf ("{");
            else if (stack[i] == '/') printf ("}");
            else printf("%c", stack[i]);
        }
        printf ("\n");  
}