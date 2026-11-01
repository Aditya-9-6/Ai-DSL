/*
 * Practical No: 6
 * AIM: In any language program mostly syntax error occurs due to unbalancing delimiter
 * such as (), {}, []. Write a program using stack to check whether a given expression
 * is well parenthesized or not.
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop()
{
    if (top == -1)
        return '\0';
    return stack[top--];
}

int isMatching(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int checkExpression(char exp[])
{
    int i;
    char ch, open;
    top = -1;

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
                return 0;
            open = pop();
            if (!isMatching(open, ch))
                return 0;
        }
    }
    return (top == -1);
}

int main()
{
    char exp[MAX];
    printf("Enter an expression: ");
    fgets(exp, MAX, stdin);

    if (checkExpression(exp))
        printf("Expression is well-parenthesized.\n");
    else
        printf("Expression is not well-parenthesized.\n");

    return 0;
}
