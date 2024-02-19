#include <stdio.h>
#define size 50
char stack[size];
int top = -1;

void push(char x)
{
    if (top == size - 1)
    {
        printf("Stack is full");
    }
    else
    {
        top = top + 1;
        stack[top] = x;
    }
}

char pop()
{
    int item;
    if (top == -1)
    {
        return 0;
    }
    else
    {
        item = stack[top];
        top = top - 1;
    }
    return item;
}

int priority(char x)
{
    if (x == '(')
    {
        return 0;
    }
    if (x == '+' || x == '-')
    {
        return 1;
    }
    if (x == '*' || x == '/')
    {
        return 2;
    }
    if (x == '^')
    {
        return 3;
    }
}

int alnum(char x)
{
    if (x != '(' && x != ')' && x != '+' && x != '-' && x != '*' && x != '/' && x != '^' && x != '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    char exp[50], *e, x;
    printf("Enter the expression:");
    scanf("%s", exp);
    e = exp;

    printf("The postfix expression is:");

    while (*e != '\0')
    {
        if (alnum(*e))
        {
            printf("%c", *e);
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }

    while (top != -1)
    {
        printf("%c", pop());
    }
}