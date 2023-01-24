#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int roll, marks;
    char name[100];
} student;

// Sorting the array of structure
void sort(student s1[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s1[i].marks < s1[j].marks)
            {
                student temp = s1[i];
                s1[i] = s1[j];
                s1[j] = temp;
            }
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    student *s1;
    student *s2;
    FILE *fpr, *fwr;
    fpr = fopen(argv[1], "r"); // reading from file
    fwr = fopen(argv[2], "w"); // writing from file
    if (fpr == NULL)
    {
        printf("Not Opened");
    }
    int n;
    fscanf(fpr, "%d", &n);
    s1 = (student *)malloc(n * sizeof(student));
    s2 = (student *)malloc(n * sizeof(student));
    for (int i = 0; i < n; i++)
    {
        fscanf(fpr, "%d%s%d", &s1[i].roll, s1[i].name, &s1[i].marks);
    }
    sort(s1, n);
    for (int i = 0; i < n; i++)
    {
        fprintf(fwr, "Rank: %d : %d %s %d\n", i + 1, s1[i].roll, s1[i].name, s1[i].marks);
        printf("Rank: %d : %d %s %d\n", i + 1, s1[i].roll, s1[i].name, s1[i].marks);
    }
    fclose(fpr);   //Closing the files
    fclose(fwr);
    return 0;
}

