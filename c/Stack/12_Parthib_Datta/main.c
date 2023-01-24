#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stack;
int top = -1;
int size = 100000;
// Creating the stack
void init()
{
    stack = (char *)calloc(size, sizeof(char));
}

void push(char item)
{
    stack[++top] = item;
}

char pop()
{
    return stack[top--];
}

char peek()
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

// Peference of every operator
int prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

int main()
{
    init();
    char *s;
    s = (char *)malloc(100000 * sizeof(char));
    scanf("%[^\n]s", s); // Inserting the string
    char *ans;
    ans = (char *)calloc(10000, sizeof(char));
    for (int i = 0; i < strlen(s); i++)
    { // Iterate over each charater and check
        if (s[i] == ' ')
        { // For ' ' skip
            continue;
        }
        char c = s[i];
        if (c - '0' >= 0 && c - '0' <= 9 || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        { // For operands add to answer string
            strncat(ans, &c, 1);
        }
        else if (c == '(')
        { // For '(' push into the stack
            push(c);
        }
        else if (c == ')') // For ')' pop elements from the stack and add to answer string until the stack ends and ')' comes
        {
            while (isEmpty() != 1 && peek() != '(')
            {
                char d = peek();
                strncat(ans, &d, 1);
                pop();
            }
            pop();
        }
        else // For operators pop elements from the stack and add to answer string until the stack ends according the peference and push them to stack
        {
            while (isEmpty() != 1 && prec(c) <= prec(peek()))
            {
                char d = peek();
                strncat(ans, &d, 1);
                pop();
            }
            push(c);
        }
    }
    while (isEmpty() != 1) // If the stack is not empty then add the remaining elements except brackets
    {
        if (peek() == '(')
        { // If '(' left in the stack then the expression is invalid
            printf("Invalid Input");
        }
        char d = peek();
        strncat(ans, &d, 1);
        pop();
    }
    printf("%s", ans);
    return 0;
}
