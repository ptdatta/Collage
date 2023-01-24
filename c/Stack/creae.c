#include<stdio.h>
#include<stdlib.h>
struct stack{
   int size;
   int top;
   int * arr;
}; 
int isEmpty(struct stack*ptr){
    if(ptr->top==-1){
        return 1;
    }else{
        return 0;
    }
}
int isFull(struct stack*ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
 
int peek(struct stack* sp, int i){
    int arrayInd = sp->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}
int main(){
    // struct stack s;
    // s.size=80;
    // s.top=-1;
    // s.arr=(int *) malloc(s.size*sizeof(int));
    struct stack *s;
    s->size=80;
    s->top=-1;
    s->arr=(int *) malloc(s->size*sizeof(int));
    push(s,5);
    push(s,57);
    push(s,53);
    push(s,25);
    printf("%d\n",pop(s));
    printf("%d",peek(s,3));
    return 0;
}