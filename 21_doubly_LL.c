#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data ;
    struct Node* next;
    struct Node* prev;
};
void linkedlistTraversal(struct Node *head){
    struct Node* p=head;
       while(p->next!=NULL){
           printf("Element : %d\n",p->data);
           p=p->next;
       }  
       printf("Element : %d\n",p->data);            
       printf("\n");
       printf("Backward traversal :\n");

      while(p!=head){
           printf("Element : %d\n",p->data);
           p=p->prev;
       }  
       printf("Element : %d\n",p->data);
}
int main(){
    struct Node * head;    
   struct Node * second;
   struct Node * third;

   head=(struct Node*) malloc( sizeof(struct Node));   
   second=(struct Node*) malloc( sizeof(struct Node));   
   third=(struct Node*) malloc( sizeof(struct Node));

   head->prev=NULL;
   head->data=7;
   head->next=second;
  
   second->prev=head;
   second->data=14;
   second->next=third;

   third->prev=second;
   third->data=21;
   third->next=NULL;

  printf(" Forward traversal :\n");
   linkedlistTraversal(head);


    return 0;
}