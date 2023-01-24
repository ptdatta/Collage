#include<stdio.h>
#include<stdbool.h>
int main(){
    int i=0;
    int s=2;
    int sum=0;
    while(i<10){
       sum+=s;
       s+=2;
       i++;
    }
    printf("%d",sum);
return 0;
}