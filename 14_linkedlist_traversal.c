#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *ptr){
    while(ptr!=NULL){
    printf("Element : %d \n", ptr->data);
    ptr=ptr->next;
    }
}
// in c++  Node * head=NULL

int main(){
   struct Node * head;    //head=new node();
   struct Node * second;
   struct Node * third;

   //allocate memory for nodes in the linked list in heap.
   head=(struct Node*) malloc( sizeof(struct Node));   
   second=(struct Node*) malloc( sizeof(struct Node));   
   third=(struct Node*) malloc( sizeof(struct Node));

   //link first and second node
   head->data=7;
   head->next=second;

    //link second and third node
   second->data=14;
   second->next=third;

    //terminate list at third node
   third->data=21;
   third->next=NULL;

   linkedlisttraversal(head);

    return 0;
}