#include<stdio.h>
#include<string.h>
int main(){
    char s[]="helloworld";
    char c[100];
    char c2[100];
    strcpy(c,s);
    printf(c);
    int i=0;
    while(s[i]!='\0'){
        c2[i]=s[i];
        i++;
    }
    printf("\n%s",c2);
    return 0;
}