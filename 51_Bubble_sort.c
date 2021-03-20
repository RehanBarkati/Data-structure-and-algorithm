#include<stdio.h>

int isSorted=0;
void bubblesort(int *A,int n){
   for(int i=0;i<n-1;i++){   //for number of passes
      for(int j=0;j<n-1-i;j++){ //for comparison in each pass
           if(A[j]>A[j+1]){
               isSorted++;
               int temp=A[j];
               A[j]=A[j+1];
               A[j+1]=temp;
         }
      }
      if(isSorted==0){
          printf("Array is sorted in %d pass\n",i);
          break;
      }
      else{
          isSorted=0;
      }
   }
}

void printArray(int *A,int n){
      printf("Sorted array is : \n");
    for(int i=0;i<n;i++){
       printf("%d ",A[i]);
    }
}

int main(){
    //int A[]={12,54,65,7,23,9};
    int A[]={1,4,5,2,6,9};
    int n=6;
    bubblesort(A,n); //function to sort the array
    printArray(A,n);
    return 0;
}