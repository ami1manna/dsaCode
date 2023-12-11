// To implement Double Ended queue.
//dequeu 
#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int dequeue[MAX];
int front = -1 ,rear = -1;

//input restricted -queue (insertion is only one end 
//                  but deletion can be both the end )
//output restricted -queue (deletion is only one end
//                   but insertion can be done in both end
void insert_rear(int val){
    
    if((rear+1)%MAX == front){
printf("Queue id full ");

    }
    else if(rear ==-1){
        // printf("enter the value :\n");
        // scanf("%d",&val);
        rear =front = 0 ;
        dequeue[rear] = val;

    }
    else{
        rear =(rear + 1)%MAX;
        dequeue[rear]= val;
    }
}


void insert_front(int data){
// is full
if((rear+1)%MAX == front){
printf("queue is full\n");

}
else if(front == -1 ){
    front = rear = 0 ;
    dequeue[front] = data;

}
else{ 
    front = (front-1 + MAX)%MAX;
    dequeue[front]= data;

}

}



void delete_rear(){
int val;
if(rear == -1 ){
    printf("Queue is empty\n");
}
//[---1---]
else if (rear == front){
    val = dequeue[rear];
    printf("%d deleted \n" , val);
    rear = front = -1 ; //reset
}
else {
    val = dequeue[rear];
    printf("%d deleted \n" , val);
    rear = (rear -1 + MAX)%MAX;

}
}

void delete_front(){

int val ;
if(front == -1){
      printf("Queue is empty\n");
}
 else if (rear == front){
    val = dequeue[rear];
    printf("%d deleted \n" , val);
    rear = front = -1 ; //reset
}
else{
    val = dequeue[front];
    printf("%d deleted \n" , val);
    front =(front +1)%MAX;
    
}
}


void main()
{
    int choice1, choice2;
    int exit1 = 1;
    int exit2 = 1;
    while (exit1)
    {
        printf("\nenter: \n 1.Input Restricted \n 2. Output Restricted \n3.Exit\n");
        scanf("%d", &choice1);
        switch (choice1)
        {
        case 1:
            while (choice2!=4)
            {
                printf("\nINPUT RESTRICTED:\n");
                printf("\nEnter:\n 1.insert_rear\n 2.delete_rear \n3.delete_front\n4.Exit\n");
                scanf("%d ", &choice2);
                switch (choice2)
                {
                case 1:
                    insert_rear(2);
                    break;
                case 2:
                    delete_rear();
                    break;
                case 3:
                    delete_front();
                    break;
                case 4:
                    
                    break;
                default:
                    printf("\ninvalid input!\n");
                    break;
                }
            }
            break;
        case 2:
            while (exit2)
            {
                printf("\nOUTPUT RESTRICTED:\n");
                printf("\nEnter:\n 1.insert_rear\n 2.delete_front \n3.insert_front\n4.Exit\n");
                scanf("%d ", &choice2);
                switch (choice2)
                {
                case 1:
                    insert_rear(3);
                    break;
                case 2:
                    delete_front();
                    break;
                case 3:
                    insert_front(4);
                    break;
                case 4:
                    exit2 = 0;
                    break;
                default:
                    printf("\ninvalid input!\n");
                    break;
                }
            }
            break;
        case 3:
            exit1 = 0;
            break;
        default:
            printf("\ninavlid input!\n");
            break;
        }
    }
}