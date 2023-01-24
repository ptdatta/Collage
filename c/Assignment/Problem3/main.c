#include <stdio.h>
#include <math.h>
int main()
{
    int k;
    float c;
    printf("Enter the number ");
    scanf("%d", &k);
    if (k < 5)
    {
        printf("No Pythagorean triples available \n");
    }
    else
    {
        printf("Pythagorean triples are: \n");
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = i; j <= k; j++)
        {
            c = sqrt(i * i + j * j);   // finding the sqrt
            if (c == (int)c && c <= k) // if sqrt and it's integer value is same then print
            {
                printf("%d %d %d \n", i, j, (int)c);
            }
        }
    }
    return 0;
}
