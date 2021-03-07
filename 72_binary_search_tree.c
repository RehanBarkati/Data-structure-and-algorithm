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

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int isBST(struct node* root){
  static struct node* pre=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(pre!=NULL && root->data <= pre->data){
            return 0;
    }
        pre=root;  
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
int main(){
    

    //constructing the root node using function
    struct node* p=createnode(5);
    struct node* p1=createnode(3);
    struct node* p2=createnode(6);
    struct node* p3=createnode(1);
    struct node* p4=createnode(5);
   /*  finally tree looks like
           5
          / \
         3   6
        / \
       1   4
    */
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
  inorder(p);
  printf("\n");
  printf("%d",isBST(p));
    return 0;
}