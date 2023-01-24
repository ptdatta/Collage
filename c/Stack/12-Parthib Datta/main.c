#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>

int *stack;
int top = -1;
int size = 1;

void init()
{
    stack = (int *)calloc(size, sizeof(int));
}

int *create(int *stack)
{
    int *new_stack = (int *)calloc(2 * size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        new_stack[i] = stack[i];
    }
    size *= 2;
    return new_stack;
}

void push(int item)
{
    if (top == size - 1)
    {
        stack = create(stack);
    }
    stack[++top] = item;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack[top--];
}

bool isEmpty(){
    return top==-1;
}

void display()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n");
    return;
}

double time_required(int n)
{
    double time_spent = 0.0;
    clock_t begin = clock();
    init();
    for (int i = 0; i < n; i++)
    {
        push(rand());
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    return time_spent;
}

int main()
{
    // printf("%lf",time_required(50000));
    init();
    // push(5);
    printf("%d",isEmpty(stack));
    // int p;
    // scanf("%d", &p);
    // int *n = (int *)malloc(p * sizeof(int));
    // int *time = (int *)malloc(p * sizeof(int));
    // for (int i = 0; i < p; i++)
    // {
    //     scanf("%d", &n[i]);
    //     time[i] = (int)(time_required(n[i]) * 1000000);
        
    // }
    // int max = -1;
    // for (int i = 0; i < p; i++)
    // {
    //     printf("For n = %d time needed %d sec\n",n[i],time[i]);
    //     if (time[i] > max)
    //     {
    //         max = time[i];
    //     }
    // }
    // printf("The n vs time graph-->\n");
    // for (int i = 0; i < max; i++)
    // {
    //     for (int j = 0; j < p; j++)
    //     {
    //         if (i < max - (int)time[j])
    //         {
    //             printf("     ");
    //         }
    //         else
    //         {
    //             printf(" *** ");
    //         }
    //     }
    //     printf("\n");
    // }
    // for(int i=0;i<p;i++){
    // 	printf(" %d",n[i]);
    // }
    return 0;
}