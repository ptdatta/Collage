#include<stdio.h>
#include<string.h>
// int main(){
//     int i=0;
//     do{
//         printf("%d\n",i);
//         i++;
//     }while(i<5);
//     return 0;
// }
struct student
{
    char name[50];
    int roll;
};
struct collage
{
    char name[50];
    struct student stu;
};
int main(){
    struct collage coll;
    strcpy(coll.stu.name,"Parthib");
    strcpy(coll.name,"CU");
    coll.stu.roll=46;
    printf("%d",coll.stu.roll);
    printf("%s",coll.stu.name);
    printf("%s",coll.name);
    
    return 0;
}