#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
void linkedlisttraversal(struct Node *head){
    struct Node *ptr=head;
    do{
    printf("Element : %d \n", ptr->data);
    ptr=ptr->next;
    }while(ptr!=head);
}

struct Node* insertAtFirst(struct Node* head,int data){
   struct Node *ptr= (struct Node*) malloc( sizeof(struct Node));
    ptr->data=data;
   struct Node *p=head->next;
   while(p->next!=head){
       p++;
   }
  //at this point ppoint tothe last node of circular LL
  p->next=ptr;
  ptr->next=head;
  head=ptr;
  return head;
}
int main(){
   struct Node * head;    //head=new node();
   struct Node * second;
   struct Node * third;
   struct Node * fourth;

   //allocate memory for nodes in the linked list in heap.
   head=(struct Node*) malloc( sizeof(struct Node));   
   second=(struct Node*) malloc( sizeof(struct Node));   
   third=(struct Node*) malloc( sizeof(struct Node));
   fourth=(struct Node*) malloc( sizeof(struct Node));

   //link first and second node
   head->data=4;
   head->next=second;

    //link second and third node
   second->data=3;
   second->next=third;

    //link third and fourth node
   third->data=6;
   third->next=fourth;

  //link fourth  and first node
   fourth->data=1;
   fourth->next=head;

   printf("Linked list before insertion\n");
   linkedlisttraversal(head);
   
  head= insertAtFirst(head,30);
   printf("\n");

   printf("Linked list after insertion\n");
   linkedlisttraversal(head);

    return 0;
}