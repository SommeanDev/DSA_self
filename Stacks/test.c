#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#include "Stacks.h"

int evaluate(char expression[]) 
{
    printf("\nEvaluating...\n");
    Stack evalStack;
    int size = strlen(expression);
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
            //displayStack(evalStack);
            break;
        case '-':
            temp2 = pop(&evalStack);
            temp1 = pop(&evalStack);
            push((temp1 - temp2), &evalStack);
            //displayStack(evalStack);
            break;
        case '*':
            temp2 = pop(&evalStack);
            temp1 = pop(&evalStack);
            push((temp1 * temp2), &evalStack);
            //displayStack(evalStack);
            break;
        case '/':
            temp2 = pop(&evalStack);
            temp1 = pop(&evalStack);
            push((temp1 / temp2), &evalStack);
            //displayStack(evalStack);
            break;
        default:
            push(((int)expression[i] - (int)'0'), &evalStack);
            //displayStack(evalStack);
            break;
        }        
    }
    return pop(&evalStack);
}

/* void displayStack(Stack stack){
    printf("Stack: [");
    for (int i = 0; i < sizeof(stack)/sizeof(int); i++)
    {
        printf("%d ", stack.s[i]);
    }
    printf("]\n");
    printf("Top element of stack: %d(i: %d)\n\n", peek(&stack), stack.Top);
}
 */
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

int isOperator(char operator){
    if (operator == '+' || operator == '-' || operator == '*' || operator == '/')
    {
        return 0;
    }
    return 1;
}

void infix_to_postfix(char *expression, char *postfix)
{
    printf("\nConverting expression to postfix...\n");
    int i = 0, j = 0, size = strlen(expression);
    Stack operatorStack;
    operatorStack.Top = -1;
    char appendToPostfix;
    for (i = 0; i < size; i++)
    {
        char ch = expression[i];
        switch (ch)
        {
        case '(':
            push((int)ch, &operatorStack);            
            break;
        case ')':
            while (!(isEmpty(&operatorStack) == 0) && !((char)peek(&operatorStack) == '('))
            {
                appendToPostfix = (char)pop(&operatorStack);
                postfix[j++] = appendToPostfix;
            }
            if ((char)peek(&operatorStack) == '(')
            {
                int discard = pop(&operatorStack);
            }
            break;
        default:
            if (isdigit(ch) == 1 || !(isalpha(ch) == 0))
            {
                postfix[j++] = ch;
            }
            else if (isOperator(ch) == 0)
            {
                if (precedence(ch) <= precedence((char)peek(&operatorStack)))
                {
                    while (precedence(ch) <= precedence((char)peek(&operatorStack)))
                    {
                        appendToPostfix = (char)pop(&operatorStack);
                        postfix[j++] = appendToPostfix;
                    }
                }
                
                if (precedence(ch) > precedence((char)peek(&operatorStack)))
                {
                    push(ch, &operatorStack);
                }
                
            }
            break;
        }
    }

    while (!(isEmpty(&operatorStack) == 0)) 
    {
        postfix[j++] = (char)pop(&operatorStack);
    }
    
    postfix[j] = '\0';
    printf("\nAfter converting to postfix: %s\n", postfix);
}

int main(int argc, char const *argv[])
{
    char expression[50], postfix[50];
    int result = 0;

    //Direct postfix evaluation
    printf("\n\nEnter postfix expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strlen(expression) - 1] = '\0';
    result = evaluate(expression);
    printf("\nResult: %d\n", result);

    //Infix to postfix conversion, and then postfix evaluation
    printf("\nEnter new infix expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strlen(expression) - 1] = '\0';
    infix_to_postfix(&expression, &postfix);
    printf("\nIts (infix expression's) result: %d\n", evaluate(postfix));


    return 0;
}
