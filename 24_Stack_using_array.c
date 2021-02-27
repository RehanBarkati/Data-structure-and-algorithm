#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size,top;
    int *arr;
};

int isEmpty(struct stack* ptr){
     if(ptr->top==-1){
         return 1;
     }
     else{
         return 0;
     }
}
int isFull(struct stack* ptr){
     if(ptr->top==ptr->size -1){
         return 1;
     }
     else{
         return 0;
     }
}

int main(){
    //   struct stack s;
    //   s.size=80;
    //   s.top=-1;  // -1 means no element in stack
    //   s.arr=(int *)malloc((s.size)*sizeof(int));

      struct stack *s;
      s->size=4;
      s->top=-1;  // -1 means no element in stack
      s->arr=(int *)malloc((s->size)*sizeof(int));

      //pushing an element manually
     s->arr[0]=7;
     s->top++;
     s->arr[1]=6;
     s->top++;
     s->arr[2]=5;
     s->top++;
     s->arr[3]=4;
     s->top++;
   
    //Check if stack is empty
    if(isEmpty(s)){
        printf("Stack is empty\n");
    } 
    else{
        printf("Stack is not empty\n");
    } 
    if(isFull(s)){
        printf("Stack is full\n");
    } 
    else{
        printf("Stack is not full\n");
    } 
    return 0;
}