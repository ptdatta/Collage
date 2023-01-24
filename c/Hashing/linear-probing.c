#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ENTRY 10000

typedef struct N
{
    int data;
    bool isEmpty;
} Node;

int main()
{
    float lf[] = {0.25, 0.5, 0.75, 1};
    srand(time(0));
    int* entries=(int*)malloc(ENTRY*sizeof(int));
    for(int i=0;i<ENTRY;i++){
        entries[i]=rand();
    }
    for (int i = 0; i < 4; i++)
    {
        int size = (int)(ENTRY / lf[i]);

        Node *arr = (Node *)malloc(size * sizeof(Node));
        for (int i = 0; i < size; i++)
        {
            arr[i].isEmpty = true;
            arr[i].data = -1;
        }

        for (int i = 0; i < ENTRY; i++)
        {
            if (arr[entries[i] % size].isEmpty == true)
            {
                arr[entries[i] % size].data = entries[i];
                arr[entries[i] % size].isEmpty = false;
            }
            else
            {
                int j = entries[i] % size;
                while (arr[j].isEmpty == false)
                {
                    if (j == size)
                    {
                        j = 0;
                    }
                    else
                    {
                        j++;
                    }
                }
                arr[j].data = entries[i];
                arr[j].isEmpty = false;
            }
        }
        for (int i = 0; i < size; i++)
        {
            printf("%d\t", arr[i].data);
        }
        printf("\n\n");
    }
    return 0;
}
