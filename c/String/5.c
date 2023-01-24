#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(){
    char s[100];
    fgets(s,sizeof(s),stdin);
    int i=0,j=0;
    while(s[j+2]!='\0'){
        j++;
    }
    bool a=true;
    while(j>=i){
        if(s[i]!=s[j]){
            a=false;
        }
        i++;
        j--;
    }
    printf("%s", a ? "true" : "false");
    return 0;
}