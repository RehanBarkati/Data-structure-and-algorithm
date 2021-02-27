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
struct Node* deletionInBetween(struct Node* head,struct Node* previousNode ){
         struct Node* ptr=head;
         struct Node* p=previousNode;
         while(ptr->next!=previousNode){
             ptr++;
         }
         ptr->next=previousNode->next;
         free(p);
         return head;
}

struct Node* deletionOfLastNode(struct Node* head){
    struct Node* p=head
;
    struct Node* q=head->next;
    while(q->next!=NULL){
        p++;
        q++;
    }
    p->next=q->next;
    free(q);
    
    return head;
}

struct Node* deletionAtAGivenValue(struct Node* head,int value){
         struct Node* p=head;
         struct Node* q=head->next;
        while(q->data!=value && q->next!=NULL){
            p++;
            q++;
        }
        if(q->data==value){
            p->next=q->next;
            free(q);
        }
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
   printf("Linked list before deletion \n");
   linkedlisttraversal(head);
    printf("\n");
    // head=deletionAtBegin(head);
    // head=deletionInBetween(head,second);
    //head=deletionOfLastNode(head);
    head=deletionAtAGivenValue(head,14);
   printf("Linked list after deletion \n");
   linkedlisttraversal(head);
    
    return 0;
}