#include <stdio.h>
struct student {
    char Name[50];
    int roll;
    int marks;
}s[2];

int main() {
    

    // storing information
    for (int i = 0; i < 2; ++i) {
        s[i].roll = i + 1;
        printf("\nFor roll %d,\n", s[i].roll);
        printf("Enter name: ");
        scanf("%s", s[i].Name);
        printf("Enter marks: ");
        scanf("%d", &s[i].marks);
    }
    printf("Displaying Information:\n\n");

    // displaying information
    for (int i = 0; i < 2; ++i) {
        printf("\nRoll number: %d\n", i + 1);
        printf("name: %s\n",s[i].Name);
        printf("Marks: %d\n", s[i].marks);
        printf("\n");
    }
    return 0;
}
