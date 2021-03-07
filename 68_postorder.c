#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node* right;
  struct node* left;
};

struct node* createnode(int data){
     struct node* n; //creating node pointer
    n=(struct node*)malloc(sizeof(struct node)); //allocating memory in the heeap
    n->data=data; //setting data
    n->left=NULL; 
    n->right=NULL;
    return n; //finally returning the created node
}

void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
         printf("%d ",root->data);
    }
}
int main(){
    

    //constructing the root node using function
    struct node* p=createnode(4);
    struct node* p1=createnode(1);
    struct node* p2=createnode(6);
    struct node* p3=createnode(5);
    struct node* p4=createnode(2);
   /*  finally tree looks like
           4
          / \
         1   6
        / \
       5   2
    */
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
  postorder(p);
    return 0;
}