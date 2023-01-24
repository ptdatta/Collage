#include<stdio.h>
#include<string.h>
int main(){
    char c[6];
    fgets(c,sizeof(c),stdin);
    char d[100]=" world";
    printf("%s",c);
    printf("%c\n",c[2]);
    printf("%d\n",strlen(c));
    strcat(c,d);
    printf("%s",c);
    strcpy(c,d);
    printf("%s",c);
    
    printf("%d",strcmp(c,d));
    return 0;
}