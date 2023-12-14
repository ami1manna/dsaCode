#include<stdio.h>
// #include<conio.h>
void selection(int a[] ,int n ){
int i , j , small , index;
for(i = 0 ; i < n-1 ; i++){

small = a[i];
index = i ;

for(j = i +1 ; j< n ; j++){
if(a[j] < small){
small = a[j];
index = j;
}
}

a[index] = a[i];
a[i] = small;
}
}
int main(){
int i =0 ;
int arr[100] = {4,3,2,1};

// clrscr();


selection(arr,4);
for(i = 0 ; i < 4 ;i++){
printf("%d " ,arr[i]);
// getch();
}
return 0;




}

