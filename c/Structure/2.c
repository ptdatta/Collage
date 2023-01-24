#include <stdio.h>
struct student {
    char Name[50];
    int marks;
}s[3];

int main() {
    int i;
    printf("Enter information of students:\n");

    // storing information
    for (i = 0; i < 3; ++i) {
       
        printf("Enter name: ");
        scanf("%s", s[i].Name);
        printf("Enter marks: ");
        scanf("%d", &s[i].marks);
    }
    printf("Displaying Information:\n\n");

    // displaying information
    for (i = 0; i < 3; ++i) {
       if(s[i].marks>=80){
         printf("%s\n",s[i].Name);
       }
    }
    return 0;
}
