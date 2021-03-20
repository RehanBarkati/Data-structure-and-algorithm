#include<stdio.h>


void printArray(int *A,int n){
    for(int i=0;i<n;i++){
       printf("%d ",A[i]);
    }
    printf("\n");
}

void insertionSort(int* A,int n){
    int key,j;
    //loop for passes
    for(int i=1;i<=n-1;i++){
         key=A[i];
         j=i-1;
         while(j>=0 && A[j]>key){
             A[j+1]=A[j];
             j--;
         }
         A[j+1]=key;
        //loop for each pass
       
    }
}

int main(){
    //  0   1   2   3   4   5
    //  12,| 54, 65, 07, 23 ,09 --> i=1, key=54,j=0
    //  12,| 54 , 65, 07, 23 ,09 -->Ist pass done (i=1)!

    //  12, 54 |, 65, 07, 23 ,09  -->i=2, key=65,j=1
    //  12, 54 |, 65, 07, 23 ,09  -->2nd pass done(i=2)!

    //  12, 54 , 65,| 07, 23 ,09  -->i=3, key=7,j=2
    //  12, 54 , 65,| 65, 23 ,09  -->i=3, key=7,j=1
    //  12, 54 , 54,| 65, 23 ,09  -->i=3, key=7,j=0
    //  12, 12 , 54,| 65, 23 ,09  -->i=3, key=7,j=-1
    //  7, 12 , 54,| 65, 23 ,09  -->i=3, key=7,j=-1   -->3rd pass done (i=3)!
  

    //process continues in the same way..........


    int n=6;
    int A[]={12,54,65,7,23,9};

    printArray(A,n);
   insertionSort(A,n);
   printArray(A,n);


    return 0;
}