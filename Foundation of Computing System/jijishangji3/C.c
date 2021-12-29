#include <stdio.h>

int true = 1;
#define Len 32
void GetTwo (char array[Len]);

int main (void)
{
    char ipv4a[Len] = {0};
    char masks[Len] = {0};
    char ipv4b[Len] = {0};

    scanf ("%s", ipv4a);
    scanf ("%s", masks);
    scanf ("%s", ipv4b);

    GetTwo (ipv4a);
    GetTwo (masks);
    GetTwo (ipv4b);

    for (int i = 0; i < Len; i++) ipv4a[i] = ipv4a[i] && masks[i];
    for (int i = 0; i < Len; i++) ipv4b[i] = ipv4b[i] && masks[i];

    for (int i = 0; i < Len; i++)
    {
        if (ipv4a[i] != ipv4b[i]) true = 0;
    }

    if (true) printf("True\n");
    else printf("False\n");   
}

void GetTwo (char array[Len])
{
    char string[Len];
    for (int i = 0; i < Len; i++) string[i] = array[i];
    int nob = 31;
    int ten = 0;
    int k = 0;
    int j = 0;
    while (string[j] != '\0') j++;
    for (j -= 1; j >= -1; j--)
    {
        if (string[j] !='.' && j != -1) 
        {
            ten += (string[j]-48) * pow (10, k);
            k++;
        }   
            
        else 
        {
            for (int l = 0; l < 8; l++)
            {
                if (ten % 2 != 0) array[nob] = 1;
                else array[nob] = 0;
                ten/=2;
                nob--;
            }  
            ten = 0;
            k = 0;
        }   
    }
}