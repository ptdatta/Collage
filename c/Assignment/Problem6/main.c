#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, c = 1;
    printf("Enter N: ");
    scanf("%d", &n);
    int **arr = (int **)malloc(n * sizeof(int)); // initializing a 2D array
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    int l = 0, r = n - 1, t = 0, b = n - 1; // taking 4 pointers(left,right,top,bottom)
    while (l <= r || t <= b)
    {
        for (int i = l; i <= r; i++) // moving left to right
        {
            arr[t][i] = c;
            c++;
        }
        t++;                         // incrementing top
        for (int i = t; i <= b; i++) // moving top to bottom
        {
            arr[i][r] = c;
            c++;
        }
        r--;                         // decrementing right
        for (int i = r; i >= l; i--) // moving right to left
        {
            arr[b][i] = c;
            c++;
        }
        b--;                         // decrementing bottom
        for (int i = b; i >= t; i--) // moving bottom to top
        {
            arr[i][l] = c;
            c++;
        }
        l++; // incrementing left
    }
    for (int i = 0; i < n; i++) // printing the array
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %3d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}