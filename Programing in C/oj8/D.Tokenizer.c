#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define letter_length 5000
#define result_length 50000
int true = 1;
char *result = NULL;
void Judge (char *string);
void Reserved ();
void Integer ();
void Float ();
void Operator ();
void Variable ();
char *MyStrrchr(char *, char );//其实就是strchr
int main (void)
{
    result = malloc (result_length * sizeof (char));
    for (int i = 0; i < result_length; i++)
        *(result + i) = 0;
    char *string = NULL;
    string = malloc (letter_length * sizeof (char));
    for (int i = 0; i < letter_length; i++)
        *(string + i) = 0;
    char *start = result;
    char *semicolon = NULL;
    while (scanf("%s", string) != EOF) 
    {
        semicolon = MyStrrchr(string, ';');
        if(semicolon != NULL)
        {
            *semicolon = '\0';
            Judge (string);
            *result = '\n';
            result ++;
            if (*(semicolon + 1))
                Judge (semicolon + 1);
        }
        else
            Judge (string);
        for (int i = 0; i < letter_length; i++)
            *(string + i) = 0;
        if (true == 0) break;
    }
    if (true == 0) printf("Compile Error");
    else if (true == 1 && semicolon == NULL) printf("Compile Error");
    else printf("%s", start);
}

void Judge (char *string)
{
    char *reserved = {"const\0int\0float\0double\0long\0static\0void\0char\0extern\0return\0break\0enum\0struct\0typedef\0union\0goto"};
    if(strcmp(string, reserved + 0) == 0) 
    {
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 6) == 0) 
    {
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 10) == 0) 
    {
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 16) == 0) 
    {
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 23) == 0) 
    {
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 28) == 0) 
    {
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 35) == 0) 
    {
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 40) == 0) 
    {
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 45) == 0) 
    { 
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 52) == 0) 
    {
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 59) == 0) 
    {
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 65) == 0) 
    {
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 70) == 0) 
    {
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 77) == 0) 
    {
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 85) == 0) 
    {
        Reserved();
        return;
    }
    else if(strcmp(string, reserved + 91) == 0) 
    {
        Reserved();
        return;
    }
    
    int true_integer = 0;
    for (int i = 0; *(string + i) != '\0'; i++)
    {
        true_integer = 1;
        if (!((*(string + i) > 47 && *(string + i) < 58) || *(string + i) == 46))
        {
            true_integer = 0;
            break;
        }
    }
    if (true_integer && !(strrchr(string, 46)))
    {
        Integer();
        return;
    }
    else if (true_integer && strrchr(string, 46))
    {
        if (MyStrrchr ((MyStrrchr(string, '.')) + 1, 46) == NULL)
        {
            Float();
            return;
        }
    }

    char *operator = {"+\0-\0*\0/\0=\0==\0!=\0>=\0<=\0>\0<"};
    if(strcmp(string, (operator + 0)) == 0) 
    {
        Operator();
        return;
    }
    else if (strcmp(string,(operator + 2)) == 0)
    {
        Operator();
        return;
    }
    else if (strcmp(string,(operator + 4)) == 0)
    {
        Operator();
        return;
    }
    else if (strcmp(string,(operator + 6)) == 0)
    {
        Operator();
        return;
    }
    else if (strcmp(string,(operator + 8)) == 0)
    {
        Operator();
        return;
    }
    else if (strcmp(string,(operator + 10)) == 0)
    {
        Operator();
        return;
    }
    else if (strcmp(string,(operator + 13)) == 0)
    {
        Operator();
        return;
    }
    else if (strcmp(string,(operator + 16)) == 0)
    {
        Operator();
        return;
    }
    else if (strcmp(string,(operator + 19)) == 0)
    {
        Operator();
        return;
    }
    else if (strcmp(string,(operator + 22)) == 0)
    {
        Operator();
        return;
    }
    else if (strcmp(string,(operator + 24)) == 0)
    {
        Operator();
        return;
    }

    if((*string > 64 && *string < 91) || (*string > 90 && *string < 123) || (*string ==95))
    {
        int true_variable = 1;
        for (int i = 0; *(string + i) != '\0'; i++)
        {
            if (!((*(string + i) > 64 && *(string + i) < 91) || (*(string + i) > 90 && *(string + i) < 123) || *(string + i) == 46 || (*(string + i) > 47 && *(string + i) < 58)))
                true_variable = 0;
        }
        if (true_variable)
        {
            Variable ();
            return;
        }
    }

    if (strlen(string) == 0)
        return;

    true = 0;
}

void Reserved ()
{
    *(result +0) = 'r';
    *(result +1) = 'e';
    *(result +2) = 's';
    *(result +3) = 'e';
    *(result +4) = 'r';
    *(result +5) = 'v';
    *(result +6) = 'e';
    *(result +7) = 'd';
    *(result +8) = ' ';
    result = result + 9;
}

void Integer ()
{
    *(result +0) = 'i';
    *(result +1) = 'n';
    *(result +2) = 't';
    *(result +3) = 'e';
    *(result +4) = 'g';
    *(result +5) = 'e';
    *(result +6) = 'r';
    *(result +7) = ' ';
    result = result + 8;
}

void Float ()
{
    *(result +0) = 'f';
    *(result +1) = 'l';
    *(result +2) = 'o';
    *(result +3) = 'a';
    *(result +4) = 't';
    *(result +5) = ' ';
    result = result + 6;
}

void Operator ()
{
    *(result +0) = 'o';
    *(result +1) = 'p';
    *(result +2) = 'e';
    *(result +3) = 'r';
    *(result +4) = 'a';
    *(result +5) = 't';
    *(result +6) = 'o';
    *(result +7) = 'r';
    *(result +8) = ' ';
    result = result + 9;
}

void Variable ()
{
    *(result +0) = 'v';
    *(result +1) = 'a';
    *(result +2) = 'r';
    *(result +3) = 'i';
    *(result +4) = 'a';
    *(result +5) = 'b';
    *(result +6) = 'l';
    *(result +7) = 'e';
    *(result +8) = ' ';
    result = result + 9;
}

char *MyStrrchr(char *s, char c)
{
    char *target = NULL;
    int i = 0;
    for ( ; i < letter_length; i++)
    {
        if (*(s + i) == c)
        {
            target = s + i;
            break;
        }
    }
    return target;
}