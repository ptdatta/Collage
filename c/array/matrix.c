#include<stdio.h>
#include<stdlib.h>

int main(){
     int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int **arr;
    arr=(int**)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i]=(int*)malloc(m*sizeof(int));
        for(int j=0;j<m;j++){
        arr[i][j]=0;
        }
    }
    int r1,c1,r2,c2,r3,c3;
    scanf("%d%d%d%d%d%d",&r1,&c1,&r2,&c2,&r3,&c3);
    int val=m*n;
    arr[n-1-r1][c1]=val/4;
    arr[n-1-r2][c2]=val/2;
    arr[n-1-r3][c3]=3*val/4;
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<m;j++){
        printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}