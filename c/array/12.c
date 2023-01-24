#include<stdio.h>
#include<stdlib.h>
int main(){
    int a[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int b[3][3]={
        {7,8,9},
        {4,5,6},
        {1,2,3}
    };
    int **add,**sub;
    add=(int**)malloc(3*sizeof(int));
    sub=(int**)malloc(3*sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        add[i]=(int*)malloc(3*sizeof(int));
        sub[i]=(int*)malloc(3*sizeof(int));
        for(int j=0;j<3;j++){
         add[i][j]=a[i][j]+b[i][j];
         sub[i][j]=a[i][j]-b[i][j];
        }
    }

    printf("Addition\n");
    for (int i = 0; i < 3; i++)
    {
        for(int j=0;j<3;j++){
        printf("%d\t",add[i][j]);
        }
        printf("\n");
    }
    printf("Subtraction\n");
    for (int i = 0; i < 3; i++)
    {
        for(int j=0;j<3;j++){
        printf("%d\t",sub[i][j]);
        }
        printf("\n");
    }
    return 0;
}