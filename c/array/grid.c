#include<stdio.h>
#include<stdlib.h>
void find(int** grid,int r,int c){
        if(c<0){
            return;
        }
        if(r>7){
            return;
        }
      if(grid[r][c]==0){
          if(r>0 && grid[r-1][c]==2 || c<7 && grid[r][c+1]==2){
              grid[r][c]=2;
          }
      }
      find(grid,r,c-1);
      find(grid,r+1,c);
      find(grid,r+1,c-1);
      return;
    }
int main(){
   
    int **arr;
    arr=(int**)calloc(8,sizeof(int));
    for (int i = 0; i < 8; i++)
    {
        arr[i]=(int*)calloc(8,sizeof(int));
    }
    arr[0][7]=2;
        int c1,r1,c2,r2;
    for(int i=0;i<3;i++){
        scanf("%d %d %d %d",&c1,&r1,&c2,&r2);
        for(int j=c1;j<=c2;j++){
            arr[7-r1][j]=1;
        }
    }
    find(arr,0,7);
    int c=0;
    for (int i = 0; i < 8; i++)
    {
        for(int j=0;j<8;j++){
          if(arr[i][j]==0){
            c++;
          }
        }
    }
    printf("%d",c);
    return 0;
}