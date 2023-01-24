#include<stdio.h>
int main(){
    int a;
    a=10;
    int *ptr=&a;
    printf("%u",*ptr);
    return 0;
}