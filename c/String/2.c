#include<stdio.h>
#include<string.h>

int main(){
    char str[]="hello world",*p;
    // printf("%d\n",strlen(str));
    // int i=0;
    // while(str[i]!='\0'){
    //   i++;
    // }
    // printf("%d\n",i);
    int j=0;
    p=str;
    while(*p!='\0'){
        j++;
        p++;
    }
    printf("%d\n",j);
    return 0;
}