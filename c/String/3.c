#include<stdio.h>
#include<string.h>
int main(){
    char a[]="brain",b[]="storm";
    char c[100];
    int i=0,j=0;
    while(a[i]!='\0'){
        c[j]=a[i];
        j++;
        i++;
    }
    i=0;
    while(b[i]!='\0'){
        c[j]=b[i];
        j++;
        i++;
    }
    c[j]='\0';
    printf(c);
    strcat(a,b);
    printf("\n%s",a);
    return 0;
}