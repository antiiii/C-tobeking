/* 链表基础功能实现 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLET 9
#define MAXOPE 5

typedef struct link{
    int idnumb;
    struct link *next;
    struct link *last;
} LINK;

char standard[MAXOPE][MAXLET] = 
{"Forward", "Backward", "Insert", "Remove", "Print"};
LINK *head = NULL;
LINK *current, *prev;
LINK *start = NULL;
int time = 0;
int *output;
int point, operation; 

void Select (int operation);
void Forward(void);
void Backward(void);
void Insert(void);
void Remove(void);
void Print(void);

int main (void)
{
    output = (int * )malloc(sizeof(int) * 114550);
    scanf ("%d %d", &point, &operation);
    for (int i = 1; i <= point; i++)
    {
        current = (LINK *)malloc(sizeof (LINK));
        if (head == NULL)
            head = start = current;
        else
        { 
            prev->next = current;
            current->last = prev;
        }
        current->idnumb = i;
        prev = current;
    }
    start->last = current;
    current->next = start;
    current = start;
    
    Select(operation);
    for (int i = 0; i < time; i++)
        printf("%d\n", output[i]);

    start = current;
    current = start->next;
    while (current != start)
    {
        prev = current;
        current = prev->next;
        free(prev);
    }
    free (start);

    return 0;
}

void Select (int operation)
{
    char string[MAXLET] = {0};
    for (int index = 0; index < operation; index++)
    {
        scanf("%s", string);
        if (strcmp(string, standard[0]) == 0)
        {
            Forward();
        }
        else if (strcmp(string, standard[1]) == 0)
        {
            Backward();
        }
        else if (strcmp(string, standard[2]) == 0)
        {
            Insert();
        }
        else if (strcmp(string, standard[3]) == 0)
        {
            Remove();
        }
        else if (strcmp(string, standard[4]) == 0)
        {
            Print();
        }
    }
}

void Forward ()
{
    int times;
    scanf("%d", &times);
    if (point != 0)
        times = times % point;
    for (int i = 0; i < times; i++)
    {
        current = current->next;
    }
}

void Backward ()
{
    int times;
    scanf("%d", &times);
    if (point != 0)
        times = times % point;
    for (int i = 0; i < times; i++)
    {
        current = current->last;
    }
}

void Insert ()
{
    int i;
    prev = current;
    scanf ("%d", &i);
    current = (LINK *) malloc(sizeof(LINK));
    current->next = prev->next;
    current->last = prev;
    current->idnumb = i;
    prev->next = current;
    prev = current->next;
    prev->last = current;
    current = current->last;
    point ++;
}

void Remove ()
{
    prev = current->last;
    prev->next = current->next;
    prev = current->next;
    prev->last = current->last;
    current = prev;
    point --;
}

void Print ()
{
    output[time] = current->idnumb;
    time ++;
}
/*
2 2
Remove
Print
*/