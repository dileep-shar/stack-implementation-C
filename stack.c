#include <stdio.h>

typedef struct lifo
{
    int arr[100];
    int peak;

} stack;

void initializaStack(stack *s)
{
    s->peak = -1;
    return;
}
void push(stack *s, int element)
{
    if (s->peak >= 99)
    {
        printf("Memory Overflow");
        return;
    }
    s->peak++;
    s->arr[s->peak] = element;
    return;
}

int pop(stack *s)
{
    if (s->peak == -1)
    {
        printf("The stack is empty");
        return -1;
    }
    int returner = s->arr[s->peak];
    --s->peak;
    return returner;
}
void printStack(stack *s)
{
    int i = s->peak;
    while (i >= 0)
    {
        printf("%d\n", s->arr[i]);
        i--;
    }
    return;
}
int thirdFromTop(stack *s)
{
    stack ts;
    initializaStack(&ts);
    for (int i = 0; i < 2; i++)
    {
        push(&ts, pop(s));
    }
    int returner = s->arr[s->peak];

    for (int i = 0; i < 2; i++)
    {
        push(s, pop(&ts));
    }
    return returner;
}
int thirdFromBottom(stack *s)
{
    stack ts;
    initializaStack(&ts);
    int tempTop = s->peak;
    while (tempTop >= 0)
    {
        push(&ts, pop(s));
        tempTop--;
    }
}

int main()
{
    stack s;
    initializaStack(&s);
    push(&s, 23);
    push(&s, 33);
    push(&s, 43);
    push(&s, 3);
    push(&s, 7);
    push(&s, 123);
    printStack(&s);
    printf("\n\n%d\n\n", thirdFromTop(&s));
    //   printf("%d\n",pop(&s));
    //   printf("This is a poor guy last\n");
    printf("\n");

    printStack(&s);
    return 0;
}

