#include <stdio.h>
#include <stdlib.h>
struct person {
   int age;
   char name[30];
};

int main()
{
   struct person *ptr;

   ptr = (struct person*) malloc(2 * sizeof(struct person));

   for(int i = 0; i < 2; ++i)
   {
       printf("Enter first name and age respectively: ");
       scanf("%s %d", (ptr+i)->name, &(ptr+i)->age);
   }

   printf("Displaying Information:\n");
   for(int i = 0; i < 2; ++i)
       printf("Name: %s\tAge: %d\n", (ptr+i)->name, (ptr+i)->age);

   return 0;
}
