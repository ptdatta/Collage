#include <stdio.h>
#include <stdlib.h>

typedef struct Point
{
    int val;
    int row;
    int col;
} Point;

// This transpose alogorithm takes O(n*c) time
Point *transpose(Point *arr, Point p)
{
    Point *ans = (Point *)malloc(p.val * sizeof(Point));
    int current = 0;
    for (int i = 1; i < p.col; i++)
    {
        for (int j = 0; j < p.val; j++)
        {
            if (arr[j].col == i)
            {
                ans[current].row = arr[j].col;
                ans[current].col = arr[j].row;
                ans[current].val = arr[j].val;
                current++;
            }
        }
    }
    return ans;
}

// This transpose alogorithm takes O(n+c) time
Point *quick_transpose(Point *arr, Point p)
{
    Point *ans = (Point *)malloc(p.val * sizeof(Point));
    int *count = (int *)calloc(p.col + 1, sizeof(int));
    for (int i = 0; i < p.val; i++)
    {
        count[arr[i].col]++;
    }
    int *index = (int *)calloc(p.col + 1, sizeof(int));
    index[1] = 0;
    for (int i = 2; i < p.col + 1; i++)
    {
        index[i] = index[i - 1] + count[i - 1];
    }
    for (int i = 0; i < p.val; i++)
    {
        int current = index[arr[i].col]++;
        ans[current].col = arr[i].row;
        ans[current].row = arr[i].col;
        ans[current].val = arr[i].val;
    }
    return ans;
}

int main()
{
    FILE *fpr, *fwr;
    fpr = fopen("E:\\collage\\c\\matrix\\input.txt", "r");
    fwr = fopen("E:\\collage\\c\\matrix\\output.txt", "w");
    if (fpr == NULL)
    {
        printf("Not Opened");
    }
    Point p;
    fscanf(fpr, "%d%d%d", &p.row, &p.col, &p.val);
    Point *arr = (Point *)malloc(p.val * sizeof(Point));
    for (int i = 0; i < p.val; i++)
    {
        fscanf(fpr, "%d\n%d\n%d", &arr[i].row, &arr[i].col, &arr[i].val);
    }
    Point *duplicate_arr = arr;     //Creating a duplicate array
    arr = transpose(arr, p);
    fprintf(fwr, "The O(n*c) transpose\nRow Column Value\n");
    for (int i = 0; i < p.val; i++)
    {
        fprintf(fwr, "%d\t%d\t%d\n", arr[i].row, arr[i].col, arr[i].val);
    }
    arr = duplicate_arr;   //Reset the array
    fprintf(fwr, "\n\nThe O(n+c) transpose \nRow Column Value\n");
    arr = quick_transpose(arr, p);
    for (int i = 0; i < p.val; i++)
    {
        fprintf(fwr, "%d\t%d\t%d\n", arr[i].row, arr[i].col, arr[i].val);
    }
    return 0;
}