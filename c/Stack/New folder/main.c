#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Creating the stack
double *stack;
int top = -1;
int size = 100000;
//Initializing the stack
void init()
{
    stack = (double *)calloc(size, sizeof(double));
}

void push(double item)
{
    stack[++top] = item;
}

double pop()
{
    return stack[top--];
}

double peek()
{
    return stack[top];
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// One function that can handle all five operands
double prec(double a, double b, char ch)
{
    switch (ch)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return (float)a / b;
    case '^':
        return pow(a, b);
    }
}

int main()
{
    init();
    char *s;
    int x = 0;
    s = (char *)malloc(10000 * sizeof(char));
    scanf("%[^\n]s", s);
    double ans;
    for (int i = 0; i < strlen(s); i++) // Iterate over the string
    {
        if (s[i] == ' ')  //For ' ' continue
        {
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9')  // For operator push into the stack
        {
            push((double)s[i] - '0');
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')  //For operator found the last two operator inserted to the stack and operate them.
        {
            if (isEmpty())    //check if the stack is empty
            {
                printf("Invalid Input");
                x = 1;
                break;
            }
            double b = pop();
            if (isEmpty())    //check if the stack is empty
            {
                printf("Invalid Input");
                x = 1;
                break;
            }
            double a = pop();
            if (s[i] == '/' && b == 0.0)   // check if the denominator is 0 or not
            {
                printf("Unknown");
                x = 1;
                break;
            }
            else
            {
                ans = prec(a, b, s[i]);
            }
            push(ans);
        }
    }
    if (top > 0)  //After all operaions id the stack is not empty.
    {
        printf("Invalid Input");
        x = 1;
    }
    if (x == 0)
    {
        printf("%.2lf", ans);
    }
    return 0;
}
