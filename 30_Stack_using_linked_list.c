#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
void linkedlisttraversal(struct Node *ptr){
    while(ptr!=NULL){
    printf("Element : %d \n", ptr->data);
    ptr=ptr->next;
    }
}
int isFull(struct Node* top){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        return 1;
    }
    else 
    {
        return 0;
    }
}
int isEmpty(struct Node* top)
{
  if(top==NULL){
      return 1;
  }
  else{
      return 0;
  }
}

struct Node* push(struct Node* top,int a){
     if(isFull(top)){
         printf("Stack Overflow\n");
     }
     else{
         struct Node* p=(struct Node*)malloc(sizeof(struct Node));
         p->data=a;
         p->next=top;
         top=p;
         return top;
     }
}
int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack is underflow!!\n");
    }
    else{
    struct Node* p= *top;
    *top=(*top)->next;
    int a=p->data;
    free(p);
    return a;
    }
}

int main(){
    struct Node* top=NULL;
    top=push(top,40);
    top=push(top,30);
    top=push(top,20);
    top=push(top,10);
   int element =pop(&top);
   printf("Popped element is %d\n",element);
    linkedlisttraversal(top);
    return 0;
}