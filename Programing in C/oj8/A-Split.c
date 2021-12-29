#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** StrSplit (char *, char knife, int *);
void SWAP (char *, char *);
int main (void)
{    
    char *waxgourd = NULL;
    char knife;
    waxgourd = malloc(11500 * sizeof(char));
    char *waxgourd_temp = waxgourd;
    for (int i = 0; i < 11500; i++)
    {
        char c = getchar ();
        if (c != '\n')
        {
            *waxgourd_temp = c;
            waxgourd_temp ++;
        }    
        else
            break;
    }
    scanf ("%c", &knife);
    int count = 0;

    char **feast = NULL;
    feast = StrSplit (waxgourd, knife, &count);

    char *plasticbag = NULL;
    plasticbag = (char *) malloc (110*110*sizeof(char));
    char *plasticbag_temp = plasticbag;
    for (int i = 0; i < 110*110; i++)
    {
        *plasticbag_temp = '\0';
        plasticbag_temp++;
    }
    plasticbag_temp = plasticbag;
    for (int i = 0; i < count; i++)
    {
        while (**feast != '\0')
        {
            *plasticbag_temp = **feast;
            (*feast) ++;
            plasticbag_temp ++;
        }
        if (**feast == '\0')
        {
            feast++;
            plasticbag_temp = plasticbag + (i + 1) * 110; 
        }
    }

    for (int i = 0; i < count  - 1; i++)
    {
        plasticbag_temp = plasticbag;
        for (int k = 0; k < count - 1 - i; k++)
        {
            if (strcmp (plasticbag_temp, plasticbag_temp+110) > 0)
            {
                while (!(*plasticbag_temp == '\0' && *(plasticbag_temp + 110) == '\0'))
                {
                    SWAP(plasticbag_temp, (plasticbag_temp + 110));
                    plasticbag_temp++;
                }    
            } 
            plasticbag_temp = plasticbag + (k + 1) * 110;
        }
    }

    plasticbag_temp = plasticbag;
    for (int i = 0; i < count; i++)
    {
        while (*plasticbag_temp != '\0')
        {
            printf("%c", *plasticbag_temp);
            plasticbag_temp++;
        }
        if (plasticbag_temp != plasticbag) printf("\n");
        plasticbag_temp = plasticbag + (i + 1) * 110;
    }
    
    return 0;
}

char** StrSplit (char *waxgourd, char knife, int *count)
{
    char **dishs = NULL;
    char *dish = NULL;
    char *cutted_waxgourd = waxgourd;
    while ((dish = strchr (cutted_waxgourd, knife)))
    {
        dish = strchr (cutted_waxgourd, knife);
        *dish = '\0';
        dishs = (char **)realloc(dishs, ((*count + 1) * sizeof (char *)));
        *(dishs+*count) = cutted_waxgourd;
        cutted_waxgourd = dish + 1;
        (*count)++; 
    }
    if ((*cutted_waxgourd) != '\0')
    {
        dish = strchr (cutted_waxgourd, knife);
        dishs = (char **)realloc(dishs, ((*count + 1) * sizeof (char *)));
        *(dishs+*count) = cutted_waxgourd;
        (*count)++;
    }    
    
    return dishs;
}

void SWAP (char *pa, char *pb)
{
    char t = *pa;
    *pa =  *pb;
    *pb = t;
}
