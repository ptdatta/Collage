#include<stdio.h>
#include<stdlib.h>
struct queue
{
   int size;
   int f;
   int r;
   int* arr;
};
struct cirqueue
{
   int size;
   int f;
   int r;
   int* arr;
};
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
int isFullCir(struct cirqueue *q){
    if(((q->r+1)%q->size)==q->f){
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
int isEmptyCir(struct cirqueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("This Queue is full");
    }else{
        q->r++;
        q->arr[q->r]=val;
    }
}
void enqueueCir(struct cirqueue *q,int val){
    if(isFullCir(q)){
        printf("This Queue is full");
    }else{
        q->r=(q->r+1)% q->size;
        q->arr[q->r]=val;
    }
}
int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("This Queue is empty");
    }else{
        q->f++;
        a=q->arr[q->f ];
    }
    return a;
}
int dequeueCir(struct cirqueue *q){
    int a=-1;
    if(isEmptyCir(q)){
        printf("This Queue is empty");
    }else{
        q->f=(q->f+1)% q->size;
        a=q->arr[q->f ];
    }
    return a;
}
int main(){
    struct queue q;
    q.size=100;
    q.f=-1;
    q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    enqueue(&q,12);
    struct cirqueue qc;
    qc.size=100;
    qc.f=0;
    qc.r=0;
    qc.arr=(int *)malloc(qc.size*sizeof(int));
    enqueueCir(&qc,12);
    enqueueCir(&qc,15);
    return 0;
}