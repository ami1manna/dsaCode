#include<stdio.h>
#define max 10
int queue[max];
int front = -1,rear = -1;

void enqueue(int data){
   
if(rear == -1 && front == -1){
    front = rear = 0;
    queue[rear] = data;
}
else   if((rear+1)%max ==front){
    printf("overflow");
}
else{
    rear = (rear+1)%max;
    queue[rear] = data;

}



}

int dequeue(){
    int val;
    if(rear == front == -1){
          printf("Underlfow");
        return -1;
    }
    else if( front == rear){
        val = queue[front];
        front = rear =  -1 ;
    }
    else{
    val = queue[front];
    front = (front+1)%max;
    }
    return val;
   
}
void display(){
    int i = front ;
    if(front == rear ==-1){
      printf("Queue is empty");
        return;   
    }
    
    for(int i = front; i !=rear ; i = (i+1)%max){
        printf("%d ", queue[i]);

    }
  printf("%d\n", queue[rear]);
}

int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    enqueue(25);
    display();
    dequeue();
    dequeue();
    enqueue(200);
    enqueue(500);
    display();
    dequeue();
    display();

    return 0;
}
