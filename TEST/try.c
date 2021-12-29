#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50
char *nomal;
char *regular;

int dp(int i, int j, char *s, char *p);
int Match(char *s, char *p);
void Nob1(char *nomal);
void Nob2(char *regular);

int main (void)
{
    nomal = malloc (sizeof (char) * MAX);
    regular = malloc (sizeof (char) * MAX);
    scanf("%s %s", nomal, regular);
    Nob1(regular);
    Nob2(nomal);
    if (Match(nomal, regular) == 1)
        printf("1");
    else printf("0");

    return 0;
}

int dp(int i, int j, char *s, char *p)
{
    int ans = 0;
    if (j == (int)strlen(p) && i == (int)strlen(s))
        ans = 1;
    else
    {
        int Nob1_match = (i < (int)strlen(s) && (p[j] == s[i] || p[j] == '.'));
        if (j + 1 < (int)strlen(p) && p[j + 1] == '*')
            ans = (dp(i, j + 2, s, p) || (Nob1_match && dp(i + 1, j, s, p)));
        else
            ans = Nob1_match && dp(i + 1, j + 1, s, p);
    }
    return ans;
}

int Match(char *s, char *p)
{
    return dp(0, 0, s, p);
}

void Nob1(char *nomal)
{
    for (int i = 0; nomal[i + 1] != '\0'; i++)
    {
        if ((nomal[i] == '\\') && (nomal[i + 1] == '\\'))
        {
            nomal[i] = '#';
            nomal[i + 1] = ' ';
        }
        if ((nomal[i] == '\\') && (nomal[i + 1] == '.'))
        {
            nomal[i] = '!';
            nomal[i + 1] = ' ';
        }
        if ((nomal[i] == '\\') && (nomal[i + 1] == '*'))
        {
            nomal[i] = '@';
            nomal[i + 1] = ' ';
        }
    }
    for (int i = 0; nomal[i] != '\0'; i++)
    {
        if (nomal[i] == ' ')
        {
            for (int j = i; nomal[j] != '\0'; j++)
            {
                nomal[j] = nomal[j + 1];
            }
        }
    }
    return;
}
void Nob2(char *regular)
{
    for (int i = 0; regular[i + 1] != '\0'; i++)
    {
        if (regular[i] == '\\')
            regular[i] = '#';
        if (regular[i] == '*')
            regular[i] = '@';
        if (regular[i] == '.')
            regular[i] = '!';
    }
}