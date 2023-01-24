#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n=10,*p;
    p=&n;
    printf("%p",&p);
    return 0;
}