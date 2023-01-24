#include <stdio.h>
#include <stdlib.h>

// Normal Queue
int rear, front;
int *queue;
int size = 5;
int f = -1, e = -1;
void init() //Initializing the normal queue
{
    rear = -1;
    front = -1;
    f = 0;
    e = 0;
    queue = (int *)calloc(100, sizeof(int));
}

void enqueue(int item)  //Normal queue insertion
{
    if (rear - front == size)
    {
        f++;
        return;
    }
    queue[++rear] = item;
}

int dequeue()  //Normal queue deletion
{
    if (front == rear)
    {
        e++;
        return -1;
    }
    return queue[++front];
}



// Circular Queue
int cirrear, cirfront;
int *cirqueue;
int cirsize = 3;
int cf = -1, ce = -1;
void cir_init()  //Initializing the circular queue
{
    cirrear = -1;
    cirfront = -1;
    cf = 0;
    ce = 0;
    cirqueue = (int *)calloc(cirsize, sizeof(int));
}

void cir_enqueue(int item)  //Circular queue insertion
{
    if (cirfront == (cirrear + 1) % cirsize)
    {
        cf++;
        return;
    }
    if (cirfront == -1)
    {
        cirfront = 0;
    }
    cirrear = (cirrear + 1) % cirsize;
    cirqueue[cirrear] = item;
    return;
}

int cir_dequeue() //Circular queue deletion
{
    if (cirfront == cirrear)
    {
        ce++;
        return -1;
    }
    cirfront = (cirfront + 1) % cirsize;
    return cirqueue[cirfront];
}


int main()
{
    // For 1000 enqueue and dequeue we have to check for each 25 times,so we are iterating a loop 40 times and for each time we are randomly enqueue and dequeue 25 times as 40 x 25=1000.

    // For Normal Queue -->
    printf("For Normal Queue--->\n");
    for (int i = 0; i < 40; i++)
    {
        init();
        for (int j = 0; j < 25; j++)
        {
            int x = rand() % 2;
            if (x == 0)
            {
                enqueue(rand());
            }
            else
            {
                dequeue();
            }
        }
        printf("For %d th case: \n", i + 1);
        printf("Full: %d\n", f);
        printf("Empty: %d\n\n", e);
    }


// For Circular Queue-->
    printf("For Circular Queue--->\n");
    for (int i = 0; i < 40; i++)
    {
        cir_init();
        for (int j = 0; j < 25; j++)
        {
            int x = rand() % 2;
            if (x == 0)
            {
                cir_enqueue(rand());
            }
            else
            {
                cir_dequeue();
            }
        }
        printf("For %d th case: \n", i + 1);
        printf("Full: %d\n", cf);
        printf("Empty: %d\n\n", ce);
    }
    return 0;
}