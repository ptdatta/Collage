#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Function to generate 10000 random number*/
int *generatenum(int n, int *count)
{
    srand(time(0));
    int *nums = (int *)calloc(10000, sizeof(int));
    for (int i = 0; i < 10000; i++)
    {
        nums[i] = rand() % 101; // to squeeze the numbers greater than 100
        count[nums[i]]++;       // calculating how many people are in a particular age
    }
    return nums;
}

int main()
{
    clock_t start_t, end_t;
    double total_t;
    start_t = clock(); // starting the clock
    int n = 10000;
    int *count = (int *)calloc((101), sizeof(int));
    int *arr = generatenum(n, count); // generate 10000 numbers and store it in an array
    printf("Number of people in every age:\n");
    for (int i = 0; i < 101; i++)
    {
        printf("Age %d = %d\n", i, count[i]);
    }
    printf("\n");

    int *barcount = (int *)calloc(10, sizeof(int));

    printf("Number of people between age groups:\n");
    for (int i = 1; i < 101; i += 10)
    {
        int c = 0;
        for (int j = i; j < i + 10; j++)
        {
            c += count[j]; // counting how many people fall on each age groups
        }
        barcount[i / 10] = c / 10; // storing the numbers in an array
        if (i == 1)
        {
            printf("%d to %d -> %d\n", 0, i + 9, c + count[0]);
        }
        else
        {
            printf("%d to %d -> %d\n", i, i + 9, c);
        }
    }
    printf("\n");

    int max = -1;
    for (int i = 0; i < 10; i++)
    {
        if (barcount[i] > max)
        {
            max = barcount[i]; // finding the max element from the array
        }
    }

    /*Ploting the graph*/
    printf("The people / age graph: \n\n");
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i < max - barcount[j])
            {
                printf("       ");
            }
            else
            {
                printf(" ***   ");
            }
        }
        printf("\n");
    }
    printf("0- 10 ");
    for (int i = 1; i < 10; i++)
    {
        printf("%d-%3d ", i * 10 + 1, (i + 1) * 10);
    }
    printf("\n");
    end_t = clock();                                      // ending the clock
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // counting the total time
    printf("\nTotal time taken by CPU: %f\n", total_t);
    return 0;
}