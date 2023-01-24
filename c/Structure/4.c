#include <stdio.h>
#include <string.h>

struct Student
{
    int roll;
    char name[20];
};
struct Collage
{
    char collage_name[20];
    struct Student stu;
};



// Driver code
int main()
{
    // Structure variable
    struct Collage coll;

    coll.stu.roll = 417;
    strcpy(coll.stu.name, "Parthib");
    strcpy(coll.collage_name,
           "Calcutta University");

    // Printing the details
    printf("Collage Name : %s\n",
           coll.collage_name);
    printf("Employee id : %d\n",
           coll.stu.roll );
    printf("Employee name : %s\n",
           coll.stu.name);
    return 0;
}
