#include<stdio.h>
#include<conio.h>

void swap(int *x, int *y);
int partition(int[] , int , int );
void quicksort(int[] , int , int);

void main(){
  int a[1000];
 int n,i ;
 scanf("%d",&n);
 for(i = 0 ; i <n ; i++){
scanf("%d",&a[i]);


 }
quicksort(a,0 , n);

       for (i = 0 ; i < n  ; i++)
       printf("%d " , a[i]);

getch();


}
void swap(int *x , int *y){
int temp = *x;
*x = *y;
*y = temp;
}


int partition(int a[] , int l , int h ){
 int pivot  = a[l];
 int i = l;
 int j = h;
 do{
   do{
   i++;
   }while(pivot >=a[i]);
   do{
   j--;

   }while(pivot< a[j]);
   if(i<j){
   swap(&a[i],&a[j]);
   }

   }while(i<j);

   swap(&a[l],&a[j]);

   return j ;

   }



   void quicksort(int a[],int l , int h ){
   int j ;
   if(l<h){
	  j = partition(a,l,h);
	  quicksort(a,l,j);
	  quicksort(a,j+1,h);
	  }
	  }


