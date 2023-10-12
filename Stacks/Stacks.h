#include<stdio.h>

typedef struct
{
    int s[5];
    int Top;
}Stack;

void push(char element, Stack *stack) 
{
    stack->Top++;
    if (stack->Top >= (sizeof(stack->s)/sizeof(int)))
    {
        stack->Top--;
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
        return 0; // empty
    }
    return 1; //not empty
}

int isFull(Stack *stack)
{
    if (stack->Top >= (sizeof(stack->s)/sizeof(char)))
    {
        return 0;   //full
    }
    return 1; //not full
}

int size(Stack *stack){
    return sizeof(stack->s)/sizeof(int);
}

void menu_stack(Stack *stack)
{
    int break_loop = 0;
    while (break_loop != 1){
    printf("\nWhat operation do you want to do?\n");
    printf("1 - Push\n");
    printf("2 - Pop\n");
    printf("3 - Check size\n");
    printf("4 - Check top\n");
    printf("(Enter any other integer to exit)\n");

    int reply, element;
    printf("You: ");
    scanf("%d", &reply);
    
    switch (reply)  
    {
    case 1:
        printf("Enter Element: ");
        scanf("%d", &element);
        push(element, stack);
        break;
        
    case 2:
        printf("Popped element: %d\n", pop(stack));
        break;
    
    case 3:
        printf("size of stack: %d\n", size(stack));
        break;

    case 4:
        printf("Top element of stack: %d\n", peek(stack));
        break;
    default:
        break_loop = 1;
        break;
    }
    }
}

/* int main(int argc, char const *argv[])
{
    Stack stack;
    stack.Top = -1;
    menu_stack(&stack);

    return 0;
}
 */