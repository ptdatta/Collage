#include<stdio.h>
#include<string.h>
int main(){
    int a=8208,b=0,n=0;
    b=a;
    while(a>0){
        n++;
        a/=10;
    }
    printf("%d",n);
    a=b;
    printf("%d\n",n);
    int sum=0;
    while(a>0){
        int l=a%10;
        int c=1;
        for(int i=0;i<n;i++){
            c*=l;
        }
        printf("%d\n",l);
        sum+=c;
        a/=10;
    }
    printf("%d\n",sum);
    if(sum==b){
        printf("Armstrong");
    }else{
        printf("Not armstrong");
    }
    return 0;
}