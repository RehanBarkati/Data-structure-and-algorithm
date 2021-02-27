#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct queue *q){
    if(q->r==q->size-1){
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
void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("This queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}
int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("This queue is empty\n");
    }
    else{
       q->f++;
      a = q->arr[q->f];
    }
    return a;
}
int main(){
    struct queue q;
    q.size=4;
    q.f=q.r=-1;
    q.arr=(int *)malloc(q.size * sizeof(int));

    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,18);
    enqueue(&q,21);
    // printf("dequeuing element %d\n",dequeue(&q));
    // printf("dequeuing element %d\n",dequeue(&q));
    // printf("dequeuing element %d\n",dequeue(&q));
    // printf("dequeuing element %d\n",dequeue(&q));
     
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
    return 0;
}