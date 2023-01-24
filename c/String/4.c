#include<stdio.h>
#include<string.h>
int main(){
    char s[]="helloworld";
    int i=0,j=strlen(s)-1;
    while(j>=i){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
    printf(s);
    return 0;
}