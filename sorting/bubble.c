#include<stdio.h>
void swap( int *x , int *y ){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort(int a[],  int n){
    int i,j ;
    int flag=0;
    for( i = 0 ; i < n-1 ;i++){

       flag = 0 ;
        for( j = 0 ; j < n-1 - i ; j++){

       if(a[j]> a[j+1]){
swap(&a[j],&a[j+1]);
flag = 1;

       }}
       if(flag == 0) break; 
        
    }



}

int main(){
    int arr[] = { 9 , 8 , 4 , 3 , 2 , 1 };
  
    for(int i = 0 ; i < 6 ; i++){

        printf("%d  ",arr[i]);
    }
    printf("\n");
    bubbleSort(arr,6);
    for(int i = 0 ; i < 6 ; i++){

        printf("%d  ",arr[i]);
    }
    printf("\n");
}
