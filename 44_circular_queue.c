#include<stdio.h>
#include<stdlib.h>

struct circularqueue{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct circularqueue *q){
    if((q->r+1)%(q->size)==q->f){
        return 1;
    }
    return 0;
}
int isEmpty(struct circularqueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
void enqueue(struct circularqueue *q,int val){
    if(isFull(q)){
        printf("This queue is full\n");
    }
    else{
        printf("Enqueuing element : %d\n",val);
        q->r= (q->r+1)%q->size;
        q->arr[q->r]=val;
    }
}
int dequeue(struct circularqueue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("This queue is empty\n");
    }
    else{
       q->f=(q->f+1)%q->size;
      a = q->arr[q->f];
    }
    return a;
}
int main(){
    struct circularqueue q;
    q.size=4;
    q.f=q.r=0; // f should be initialised to 0.
    q.arr=(int *)malloc(q.size * sizeof(int));

    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,18);
   // enqueue(&q,18);  Only three elements can be enqueued as one space is fixed for 0.
    
    printf("dequeuing element %d\n",dequeue(&q));
    printf("dequeuing element %d\n",dequeue(&q));
    printf("dequeuing element %d\n",dequeue(&q));
     enqueue(&q,24);
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
    return 0;
}