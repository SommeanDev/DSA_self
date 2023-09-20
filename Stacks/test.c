#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#include "Stacks.h"

int evaluate(char expression[]) 
{
    Stack evalStack;
    int size = strlen(expression);
    //char postfixExpression[size];

    //convertExpression(&expression, &postfixExpression);

    evalStack.Top = -1;
    int temp1, temp2;
    for (int i = 0; i < size; i++)
    {
        switch (expression[i])
        {
        case '+':
            temp2 = pop(&evalStack);
            temp1 = pop(&evalStack);
            push((temp1 + temp2), &evalStack);
            displayStack(evalStack);
            break;
        case '-':
            temp2 = pop(&evalStack);
            temp1 = pop(&evalStack);
            push((temp1 - temp2), &evalStack);
            displayStack(evalStack);
            break;
        case '*':
            temp2 = pop(&evalStack);
            temp1 = pop(&evalStack);
            push((temp1 * temp2), &evalStack);
            displayStack(evalStack);
            break;
        case '/':
            temp2 = pop(&evalStack);
            temp1 = pop(&evalStack);
            push((temp1 / temp2), &evalStack);
            displayStack(evalStack);
            break;
        default:
            push(((int)expression[i] - (int)'0'), &evalStack);
            displayStack(evalStack);
            break;
        }        
    }
    printf("%d\n", evalStack.Top);
    return pop(&evalStack);
}

void displayStack(Stack stack){
    printf("Stack: [");
    for (int i = 0; i < sizeof(stack)/sizeof(int); i++)
    {
        printf("%d ", stack.s[i]);
    }
    printf("]\n");
    printf("Top element of stack: %d(i: %d)\n\n", peek(&stack), stack.Top);
}
/*
int checkFix(char expression[])
{
    int infixFlag = 1;
    bool isInfix = false, isPreFix = false, isPostfix = false;
    for (int i = 0; i < strlen(expression); i++)
    {
        if (isdigit(expression[i]) == 0)
        {
            if (expression[i] == '(' || expression[i] == ')')
            {
                isInfix = true;
            }

            if (isdigit(expression[i + 1]) == 0 || i == 0 || i == strlen(expression) - 1)
            {
                infixFlag = 0;
                if (i==0)
                {
                    isPreFix = true;
                }
                else if (i == strlen(expression) - 1)
                {
                    isPostfix = true;
                }
                
            }
            
        }
        
    }

    if (isInfix && infixFlag == 0)
    {
        printf("Expression is in infix form\n");
        return 1;
    }
    else if (isPostfix)
    {
        printf("Expression is in postfix form\n");
        return 0;
    }
    else if (isPreFix)
    {
        printf("Expression is in prefix form\n");
        return 2;
    }
}

int precedence(char operator)
{
    if (operator == '+' || operator == '-')
    {
        return 1;
    }
    else if (operator == '*' || operator == '/')
    {
        return 2;
    }
    return 0;
}

void convertExpression(char *expression, char *postfixExpression)
{
    Stack operatorStack;
    operatorStack.Top = -1;
    int size = strlen(expression), i, j;

    switch (checkFix(expression))
    {
    case 1:
        for (i = 0, j = 0; i < size; i++)
        {
            if (isdigit(expression[i]) == 0)
            {
                postfixExpression[j++] = expression[i];
            }
            else if (expression[i] == '(')
            {
                push(expression[i], &operatorStack);
                displayStack(operatorStack);
            }
            else if (expression[i] == ')')
            {
                while (!(isEmpty(&operatorStack) == 1) && peek(&operatorStack) != '(')
                {
                    postfixExpression[j++] = pop(&operatorStack);
                    displayStack(operatorStack);
                }
                if (peek(&operatorStack) == '(')
                {
                    pop(&operatorStack);
                    displayStack(operatorStack);
                }
            }
            else
            {
                while (!(isEmpty(&operatorStack) == 1) && precedence(expression[i]) <= precedence(peek(&operatorStack)))
                {
                    postfixExpression[j++] = pop(&operatorStack);
                }
                push(expression[i], &operatorStack);
                displayStack(operatorStack);
            }
        }

        while (!(isEmpty(&operatorStack) == 1))
        {
            postfixExpression[j++] = pop(&operatorStack);
            displayStack(operatorStack);
        }
        postfixExpression[j] = '\0'; 
        printf("%s", postfixExpression);
        break;
    
    default:
        strcpy(postfixExpression, expression);
        break;
    }
}
*/
int main(int argc, char const *argv[])
{
    char expression[50];
    int result = 0;
    printf("%d\n", (int)'2');
    printf("Enter expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strlen(expression) - 1] = '\0';
    result = evaluate(expression);
    printf("Result: %d\n", result);
    printf("Verification:\n");
    printf("%d\n", (6*(5*((2+3)*8)+3)));

    //checkFix("6*(5*((2+3)*8)+3)");
    //checkFix(expression);
    return 0;
}