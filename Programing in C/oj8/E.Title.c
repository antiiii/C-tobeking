#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 4096
int main (void)
{
    char *letter = malloc(sizeof(char) * MAX);
    char c = 0;
    for (int i = 0; i < MAX; i++)
    {
        *(letter + i) = 0;
    }
    for (int i = 0;i < MAX; i++)
    {
        c = getchar ();
        if (c != '\n')
        {
            *(letter+i) = c;
        }    
        else
        {
            *(letter+i) = '\0';
            break;
        }
    } 
    for (int i = 0; *(letter+i) != '\0'; i++)
    {
        if ((i == 0 || *(letter+i-1) == ' ') && *(letter+i) > 96 && *(letter+i) < 123) *(letter+i) -= 32;
        else if (!(i == 0 || letter[i-1] == ' ') && *(letter+i) < 96 && *(letter+i) > 64) *(letter+i) += 32;
    }
    puts(letter);

    return 0;
}