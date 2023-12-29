
#include<stdio.h>
#define max 100
typedef struct Data
{
    int data ;
    int priority ;

}Data;


Data queue[max];

int front = -1;
int rear = -1;

int isEmpty(){
return front == -1;
}


void enqueue(Data data){

if(rear == max -1 ){
printf("overflow\n");return;

}



//imp
if(front == -1){
     front =  0;

}
queue[++rear] = data ; 

for(int i = rear - 1 ; i >= front && data.priority < queue[i].priority ; i--){

    queue[i+1] = queue[i];
    queue[i] = data;


}
}
Data deque(){
   
Data d ;
d.data = -1;
d.priority = -1;
if(front == -1 ){
printf("underflow\n");
return d;
}

if(front == rear )
{
     d  = queue[front];
    front = rear = -1 ;
return d ;
}
else{

    d = queue[front++];
    return d;
}

   
}

void display(){


    int i ;
   if(isEmpty()){
    return ;
   }

for(int i = front ;i <=  rear;i++){

printf("%d  - %d \n",queue[i].data ,queue[i].priority);
}

}

int main(){
//lowe rthe number higher the priority 
Data d;
d.data = 1 ;
d.priority = 0 ;

enqueue(d);

d.data = 2 ;
d.priority = 4 ;

enqueue(d);


d.data = 3 ;
d.priority = 2 ;

enqueue(d);


d.data = 4 ;
d.priority = 1 ;

enqueue(d);

display();

d = deque();

display();

}
