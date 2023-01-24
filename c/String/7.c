#include<stdio.h>
#include<string.h>
int main(){
    char s1[100];
    fgets(s1,sizeof(s1),stdin);
    char s2[100];
    fgets(s2,sizeof(s2),stdin);
    int c=strcmp(s1,s2);
    if(c==0){
        printf("Strings are same");
    }else{
        printf("Strings are different");
    }
    return 0;
}