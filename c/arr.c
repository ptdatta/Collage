#include<stdio.h>

float fun(float n){
    return 3*n*n;
}

float integration(int r,int l){
    int sum=0;
    while(l+2<=r){
        float mid=(float)(l+(l+2))/2;
        sum+=fun(mid);
        l+=1;
    }
    return sum;
}

int main(){
    printf("%f",2*integration(5,1));
    return 0;
}