#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    // int **arr;
    // arr=(int**)malloc(2*sizeof(int));
    // arr[0]=(int*)malloc(2*sizeof(int));
    // arr[0][0]=5;
    // arr[0][1]=6;
    // arr[1]=(int*)malloc(2*sizeof(int));
    // arr[1][0]=51;
    // arr[1][1]=61;
    // printf("%d\t%d\n",arr[0][0],arr[0][1]);
    // printf("%d\t%d",arr[1][0],arr[1][1]);

    // int a=(78+95+5)/30;
    // switch (a)
    // {
    // case 10:
    // case 9:
    //     printf("A");
    //     break;
    // case 8:
    //     printf("b");
    //     break;
    // case 7:
    //     printf("c");
    //     break;
    
    // default:
    //     printf("F");
    //     break;
    // }

    char a[100]="hello",*p;
    p=a;
    int j=0;
    while(*p!='\0'){
        j++;
        p++;
    }
    printf("%d",j);
    // char c[100];
    // // fgets(a,sizeof(a),stdin);
    // printf("%s",a); 
    // strcpy(c,a);
    // printf("%s",c);
    // strcat(c,a);
    // printf("\n%s",c);
    // char a[100];
    // char c[100];
    // fgets(a,sizeof(a),stdin);
    // scanf("%s",&c);
    // printf("%d",strlen(a)); //6
    // printf("%d",strlen(c)); //5

//     int x=10,y=20,*ptr_x,*ptr_y,temp;
//     // x=x+y;
//     // y=x-y;
//     // x=x-y;
//     ptr_x = &x;
// ptr_y = &y;
// temp = *ptr_y;
// *ptr_y = *ptr_x;
// *ptr_x = temp;
//     printf("%d\n%d",x,y);
    return 0;

}