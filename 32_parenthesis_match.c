#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size,top;
    char *arr;
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
void push(struct stack *ptr,char value){
     if (isFull(ptr)){
         printf("stack overflow !! Cannot push %d element to the stack \n",value);
     }
     else{
         ptr->top++;
         ptr->arr[ptr->top]=value;
     }
 }
 char pop(struct stack *ptr){
     if (isEmpty(ptr)){
         printf("stack underflow !! Cannot pop from the stack \n");
         return -1;
     }
     else{
        char val=ptr->arr[ptr->top];
         ptr->top--;
         return val;
     }
 }

int parenthesisMatch(char *exp){
    //Create an initialize the stack
    struct stack *p;
    p->size=100;
    p->top=-1;
    p->arr=(char *)malloc((p->size)*sizeof(char));
    
    for(int i=0;exp[i]!='\0';i++){
      if(exp[i]=='('){
          push(p,'(');
      }
      else if(exp[i]==')'){
               if(isEmpty(p)){
                  return 0;
               }   
                   pop(p);
          }
    }
    if(isEmpty(p)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    
    char * exp = "8*(9))";
    //Check if stack is empty
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching\n");
    } 
    else{
        printf("The parenthesis is not matching\n");
    }   
    return 0;
} 