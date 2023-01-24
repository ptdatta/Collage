#include<stdio.h>
int main(){
    int n=6;
    int p=1;
    int c=0;
    while(n>0){
        int l=n%2;
        c+=l*p;
        p*=10;
        n/=2;
    }
    printf("%d",c);
    return 0;
}