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
 int matched(char a,char b){
     if(a=='}' && b=='{' ){
         return 1;
     }
     if(a==')' && b=='(' ){
         return 1;
     }
     if(a==']' && b=='[' ){
         return 1;
     }
     return 0;
 }

int parenthesisMatch(char *exp){
    //Create an initialize the stack
    struct stack *p;
    p->size=100;
    p->top=-1;
    p->arr=(char *)malloc((p->size)*sizeof(char));
    char popped_ch;
    
    for(int i=0;exp[i]!='\0';i++){
      if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
          push(p,exp[i]);
      }
      else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
                 if(isEmpty(p)){
                  return 0;
               }   
                 popped_ch=  pop(p);
                 if(!matched(popped_ch,exp[i])){
                     return 0;
                 }
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
    
    char * exp = "{8*(9))}";

    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching\n");
    } 
    else{
        printf("The parenthesis is not matching\n");
    }   
    return 0;
}