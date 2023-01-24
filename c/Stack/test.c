#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int* stack;
int top=-1;
void init(){
    stack=(int*)malloc(100000*sizeof(int));
}

void push(int val){
    if(top==100000){
        printf("Stack is full");
        return ;
    }
    stack[++top]=val;
}

int peek(){
    return stack[top];
}

int pop(){
   return stack[top--];
}

bool isEmpty(){
    return top==-1;
}

int main(){
    init();
    // char* st=(char*)malloc(100*sizeof(char));
    // scanf("%[^\n]s", st);
    // for(int i=0;i<100;i++){
    //     if(st[i]=='('){
    //         push('(');
    //     }else if(st[i]==')'){
    //         pop();
    //     }
    // }
    // printf("%d",isEmpty());

    // int arr[]={10,4,5,90,120,80};
    // int* ans=(int*)malloc(6*sizeof(int));
    // ans[0]=1;
    // push(0);
    // for(int i=1;i<6;i++){
    //    if(!isEmpty() && arr[peek()]>arr[i]){
    //     ans[i]=1;
    //    }else{
    //     while(!isEmpty() && arr[peek()]<=arr[i]){
    //         pop();
    //     }
    //     if(isEmpty()){
    //         ans[i]=i+1;
    //     }else{
    //         ans[i]=i-peek();
    //     }
    //    }
    //    push(i);
    // }
    // for(int i=0;i<6;i++){
    //     printf("%d\t",ans[i]);
    // }

    int c=0;
    int a[]={5,8,12,15,36,74};
    int b[]={4,6,10,16,35};
    int i=0,j=0;
    while(i<6 && j<5){
      if(a[i]>b[j]){
          c+=6-i;
          j++;
      }else{
        i++;
      }
    }
    printf("%d",c);
    return 0;
}