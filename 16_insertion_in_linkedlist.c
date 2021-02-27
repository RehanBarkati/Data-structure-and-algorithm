#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data ;
    struct Node* next;
};

void linkedlisttraversal(struct Node *ptr){
    while(ptr!=NULL){
    printf("Element : %d \n", ptr->data);
    ptr=ptr->next;
    }
}

struct Node* insertAtFirst(struct Node *head,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    head=ptr;
}
struct Node* insertAtIndex(struct Node *head,int data,int index){
     struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
     struct Node *p=head;
     int i=0;
     while(i!= index-1){
         p++;
         i++;
     }
     ptr->data=data;
     ptr->next=p->next;
     p->next=ptr;
     return head;
};
struct Node* insertAtTheEnd(struct Node* head,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    while(p->next!=NULL){
        p++;
    }
    p->next=ptr;
    ptr->next=NULL;
    ptr->data=data;
    return head;
}
struct Node* insertAfterAgivenNode(struct Node* head,struct Node* previousNode,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    while(p!=previousNode){
        p++;
    }
    ptr->next=p->next;
    p->next=ptr;
    ptr->data=data;
    return head;
}
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
  
   printf("Linked list before insertion\n");
    linkedlisttraversal(head);
    printf("\n");
  
 // head=insertAtFirst(head,28);
 //head=insertAtIndex(head,40,1);
// head=insertAtTheEnd(head,35);
  head=insertAfterAgivenNode(head,second,70);
 printf("Linked list after insertion\n");
   linkedlisttraversal(head);

    return 0;
}