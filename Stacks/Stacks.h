#include<stdio.h>

typedef struct
{
    int s[10];
    int Top;
}Stack;

void push(char element, Stack *stack) 
{
    stack->Top++;
    if (stack->Top >= (sizeof(stack->s)/sizeof(int)))
    {
        printf("Error: Stack overflow\n");  
    } 
    else
    {
        stack->s[stack->Top] = element;
        printf("pushed element %d\n", element);
    }
}

int pop(Stack *stack)
{
    int index = stack->Top;
    if (stack->Top >= 0)
    {
        stack->Top--;
        return stack->s[index];

    }
    else
    {
        printf("Error: Stack underflow\n");
        return;
    }
}

int peek(Stack *stack)
{
    return stack->s[stack->Top];
}

int isEmpty(Stack *stack)
{
    if (stack->Top == -1)
    {
        return 1; // empty
    }
    return 0; //not empty
}

int isFull(Stack *stack)
{
    if (stack->Top >= (sizeof(stack->s)/sizeof(char)))
    {
        return 1;   //full
    }
    return 0; //not full
}