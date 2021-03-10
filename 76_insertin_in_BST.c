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

struct node* searchIter(struct node* root,int key){
     while(root!=NULL){
         if(key==root->data){
         return root;
     }
     else if(key<root->data){
         root=root->left;
     }
     else{
         root=root->right;
     }
}

   return NULL;

}
void insert(struct node* root,int key){
    struct node* prev=NULL;
   
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            printf("cannot insert %d \n",key);
            return ;
        }
        else if(key< root->data){
            root=root->left;
        }
        else {
            root=root->right;
        }
    }
     struct node* ptr=createnode(key);
     if(key<prev->data){
         prev->left=ptr;
     }
     else{
         prev->right=ptr;
     }

}
int main(){
    

    //constructing the root node using function
    struct node* p=createnode(6);
    struct node* p1=createnode(2);
    struct node* p2=createnode(7);
    struct node* p3=createnode(1);
    struct node* p4=createnode(4);
   /*  finally tree looks like
           6
          / \
         2   7
        / \
       1   4
    */
    p->left=p1;
    p->right=p2;
    p1->left=p3;
   // inorder(p);
   insert(p,3);
    p1->right->right=p4;
     printf("%d\n",p->left->right->data);
     inorder(p);
    return 0;
}