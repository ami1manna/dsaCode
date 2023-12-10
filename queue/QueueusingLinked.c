#include<stdio.h>
#include<stdlib.h>

//Node structure for  Queue node
struct Node{
int data;
struct Node* next;

};
struct Queue{
struct Node *front ;
struct Node *rear ;
};
struct Queue *q ;
//create node function 

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//create Queue function code onnce 
 void createQueue(struct Queue *queue){

queue->rear = NULL;
queue->front= NULL;

}

//insert into Queue function code
struct Queue* enqeue(struct Queue *queue, int data){
    //new node
      struct Node *newNode=  createNode(data);
    //if q empty
    if(queue->front ==NULL ){
        queue->front = queue->rear = newNode;
    }
    else {
       queue->rear->next = newNode;
       queue->rear = newNode;
       queue->rear->next =NULL;

    }
return queue;

}

struct Queue *dequeue(struct Queue *queue){
if(queue->front == NULL){
    printf("Queue is empty\n");
    

}
else{
// store cuurent top node in temp var
struct Node *temp = queue->front;
//store date of top node
int data = queue->front->data;
// point next node 
queue->front = queue->front->next ;
//free the topnode
free(temp);

}
return queue;
}


struct Queue* display(struct Queue *queue){
    struct Node *ptr  = queue->front;
    if(ptr==NULL){
        printf("Underflow\n");
    }
    else{
        while(ptr!=NULL){
            printf("data: %d\n", ptr->data);
            ptr = ptr->next;  // Move to the next node in the loop
        }
    }
    printf("\n");
    return queue;
}


//code for peek
int peek(struct Queue *q)
{
if(q->front==NULL)
{
printf("\n QUEUE IS EMPTY");
return -1;
}
else
return q->front->data;
}
// MAIN MODE
int main()
{
int val, option;
//intialize queue rear and front to Null
q = (struct Queue *)malloc(sizeof(struct Queue));
createQueue(q);

do
{
printf("\n *****MAIN MENU*****");
printf("\n 1. INSERT");
printf("\n 2. DELETE");
printf("\n 3. PEEK");
printf("\n 4. DISPLAY");
printf("\n 5. EXIT");
printf("\n Enter your option : ");
scanf("%d", &option);
switch(option)
{
case 1:
printf("\n Enter the number to insert in the queue:");
scanf("%d", &val);
q = enqeue(q,val);
break;
case 2:
q = dequeue(q);
break;
case 3:
val = peek(q);
if(val!= -1)
printf("\n The value at front of queue is : %d", val);
break;
case 4:
q = display(q);
break;
}
}while(option != 5);

return 0;
}
