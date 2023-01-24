#include<stdio.h>
int main(){
    int arr[10]={5,6,8,9,32,56,74,89,100,201};
    int s=0,e=9,t;
    scanf("%d",&t);
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==t){
            printf("%d",mid);
            break;
        }else if(arr[mid]>t){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return 0;
}