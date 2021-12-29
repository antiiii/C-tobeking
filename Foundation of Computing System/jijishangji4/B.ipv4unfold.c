#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_f 15
#define MAX_unf 20
int answer = 0;
int first = 1;
char *ipv4_unf = NULL;
int *intval = NULL;
char *start = NULL;
char ipv4_f[MAX_f] = {0};
void Undoo (int index, int place);
int main ( )
{
    scanf("%s", ipv4_f);
    answer = strlen(ipv4_f) - 1;
    intval = (int *) malloc(sizeof(int) * MAX_f);
    for (int i = 0; i < MAX_f; i++) *(intval + i) = 0;
    ipv4_unf = (char *) malloc(sizeof(char) * MAX_unf);
    for (int i = 0; i < MAX_unf; i++) *(ipv4_unf + i) = '\0';
    start = ipv4_unf;
    int index = 0;
    Undoo (index, 0);
    free(ipv4_unf);
    free(intval);
}

void Undoo (int index, int place)
{
    for ( ; place < answer; place++)
    {
        int i = place;
        int truee = 1;
        for ( ; intval[i] == 0 ; i--);
        i++;
        int sum = 0;
        for ( ; i <= place; i++)
        {
            sum += (ipv4_f[i] - 48) * pow(10,place - i);
        }
        for ( ; intval[i] == 0 ; i--);
        i++;
        if (ipv4_f[i] == '0' && place - i > 0) truee = 0;
        if (sum >= 256) truee = 0;
        if (truee)
        {
            intval[place] = 1;
            int j = i;
            for ( ; j < place + 1; j++)
            {
                *ipv4_unf= ipv4_f[j];
                ipv4_unf ++;
                if(intval[j])
                {
                    *ipv4_unf = '.';
                    ipv4_unf ++;    
                }
            }
            if (index < 2)
                Undoo (index + 1 , place + 1);
            else 
            {
                int total = 0;
                for (int k = j ; k <= answer; k++) 
                {
                    total += (ipv4_f[k]-48) * pow (10, answer - k);
                }
                if(total < 256 && !(answer - j > 0 && ipv4_f[j] == '0'))
                {
                    for ( ; j <= answer; j++) 
                    {
                        *ipv4_unf = ipv4_f[j];
                        ipv4_unf ++;
                    }
                    if (first != 1) printf(",");
                    first = 0;
                    printf("%s", ipv4_unf - answer - 4);
                }
            }
            for ( ; j > i; j--)
            {
                ipv4_unf --;
            }
            ipv4_unf --;
            intval[place] = 0;
        }
    } 
}
//ipv4_ f = 12.345
//ipv4_unf = 12.
//intval = 1000