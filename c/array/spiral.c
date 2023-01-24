#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int **arr;
    arr=(int**)calloc(n,sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i]=(int*)calloc(n,sizeof(int));
    }
    int l=0,r=n-1,t=0,b=n-1,c=0;
    while(l<=r || t<=b){
        for(int i=l;i<=r;i++){
            arr[t][i]=c;
            c++;
        }
        t++;
        for(int i=t;i<=b;i++){
            arr[i][r]=c;
            c++;
        }
        r--;
        for(int i=r;i>=l;i--){
            arr[b][i]=c;
            c++;
        }
        b--;
        for(int i=b;i>=t;i--){
            arr[i][l]=c;
            c++;
        }
        l++;
    }
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
         printf(" %3d ",arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}