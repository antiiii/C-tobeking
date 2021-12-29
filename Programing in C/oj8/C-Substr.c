#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{  
    char c;
    char *Minecraft = malloc (1e5*sizeof (char));
    char *minicraft = malloc (1e5*sizeof (char));
    for (int i = 0;i < 1e5; i++)
    {
        c = getchar ();
        if (c != '\n')
            *(Minecraft + i) = c;
        else
        {
            *(Minecraft + i) = '\0';
            break;
        }
    }    
    for (int i = 0;i < 1e5; i++)
    {
        c = getchar ();
        if (c != '\n')
            *(minicraft + i) = c;
        else
        {
            *(minicraft + i) = '\0';
            break;
        }
    }
    int size = 0;
    for(; *( minicraft + size ) != '\0'; size++);
    char *start;
    char *Minecraft_temp = Minecraft;
    while ((start = strstr (Minecraft_temp, minicraft)))
    {
        printf("%lld ", start - Minecraft);
        Minecraft_temp = start + size;
    }
    printf("\n");
    
    return 0;    
}