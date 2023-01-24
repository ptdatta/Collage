#include<stdio.h>
int main(){
    // int n=6,d=0;
    // int c=1;
    // while(n>0){
    //     int l=n%2;
    //     d+=l*c;
    //     c*=10;
    //     n/=2;
    // }
    // printf("%d",d);
    // char c='A';
    // // int a=(int)c;
    // printf("%d",c);
    for(int i=0;i<=4;i++){
        for(int j=4;j>i;j--){
            printf("  ");
        }
        for(int j=0;j<(2*i-1);j++){
            printf("%d ",i);
        }
        printf("\n");
    }
    printf("%d",sizeof(float));
    return 0;
}