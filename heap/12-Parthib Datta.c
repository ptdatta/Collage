#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int size = 0;

void heapify(int *arr, int n, int i)
{
    int parent = (i - 1) / 2;
    if (arr[parent] > 0)
    {
        if (arr[i] > arr[parent])
        {

            int temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp;

            heapify(arr, n, parent);
        }
    }
}

void insertNode(int arr[], int Key)
{

    size++;

    arr[size - 1] = Key;

    heapify(arr, size, size - 1);
}

void printArray(int arr[], int n)
{
    int currentLevel = 0;
    int maxPerLevel = (int)pow(2, currentLevel);
    for (int i = 0; i < n; i++)
    {
        if (i == maxPerLevel - 1)
        {
            printf("\n");
            currentLevel++;
            maxPerLevel = (int)pow(2, currentLevel);
        }
        printf("%d ", arr[i]);
    }
}

int main()
{
    int *heap = (int *)malloc(1000 * sizeof(int));
    insertNode(heap, 34);
    insertNode(heap, 23);
    insertNode(heap, 20);
    insertNode(heap, 12);
    insertNode(heap, 1);
    printArray(heap, size);
    return 0;
}
