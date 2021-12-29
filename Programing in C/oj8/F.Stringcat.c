#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1100
char *MyStringCat (char *a, char *b);
int main ()
{
    int index = 0;
    scanf("%d", &index);
    char *(*string);
    string = (char **)malloc (sizeof(char *) * index);
    for (int i = 0; i < index; i++)
    {
        char *stringA = NULL;
        char *stringB = NULL;
        stringA = (char *)malloc(sizeof(char) * MAX);
        stringB = (char *)malloc(sizeof(char) * MAX);
        scanf("%s", stringA);
        scanf("%s", stringB);
        *(string + i) = MyStringCat (stringA, stringB);
    }
    for (int i = 0; i < index; i++)
    {
        printf("%s\n", *(string + i));
    }

    return 0;
}

char *MyStringCat (char *a, char *b)
{
    int len_a = strlen(a);
    int len_b = strlen(b);   
    int same = 0;
    for (int i = 0; i < len_a && same < len_b; i++)
    {
        if (*(a + i) == *(b + same)) 
        {
            same ++;
        }
        else 
        {
            same = 0;
            if (*(a + i) == *(b + same)) 
            {
                same ++;
            }
        }
    }
    strcat(a, b + same);
    free(b);
    return a;
}