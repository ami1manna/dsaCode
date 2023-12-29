#include<stdio.h>
#define max 5
//logn 
//fm  = fm1  + fm2 
int min(int a , int b){
    return (a<=b)?a:b;
}

int fibonaccisearch(int arr[] , int x , int n ){
    //initilize 
    int fm1 = 1 ;
    int fm2 =  0 ;
    int fm = fm1 + fm2 ;

    //find the smallest possible that is greater than or equal to leng of array 
    while(fm < n){//or  >=n
fm2 = fm1;
fm1 = fm;
fm =  fm1 + fm2;


    }
int offset = -1 ;

    while(fm > 1){
  int i = min(offset + fm2 ,n-1 );

  if(arr[i] == x) { return i;}
  //if arr[i] <  x pay lay say chota hai to - 1
  else if(arr[i] <  x ){
    fm = fm1;
    fm1 = fm2;
    fm2 = fm - fm1;
   offset =  i;

    
  }
// if arry[i] > x 
  else 
  {
fm = fm2 ;
fm1 = fm1 - fm2;
fm2 = fm - fm1;
  }
    }
//comapring the last element with x 
  if ( fm1 && arr[offset + 1 ] == x)
return offset +1 ;


  
  
  


    
    
    
    return - 1;
}
int main(){
int arr[max]  ={ 1, 4 , 6 , 7, 11};
int x = 7 ;
printf(" %d\n", fibonaccisearch(arr , x, max));



    return 0 ;
}
