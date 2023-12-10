#include <stdio.h>
#include<stdlib.h>
//struct node for linked list
struct Stack{
    int data ;
    struct Stack * next;
};
//stack Top
struct Stack * Top = NULL;
//function to create a node
struct Stack * createNode(int data){
struct  Stack * newNode = (struct Stack *)malloc(sizeof(struct Stack));
newNode->data = data;
newNode->next = NULL;
return newNode;

}

//function to push an element
struct Stack *push(struct Stack* Top, int data){
    struct Stack * newNode = createNode(data);
    if(Top == NULL){
        Top = newNode;
        
    }
    else {
        newNode->next = Top;
        Top = newNode;

    }
    return Top;
}

//function to delete 
struct Stack *pop(struct Stack *Top)
{
struct Stack *ptr = Top;
if(Top == NULL)
printf("\n STACK UNDERFLOW");
else
{
Top = Top->next;
printf("\n The value being deleted is: %d", ptr->data);
free(ptr);
}
return Top;
}

// display full stack
struct Stack *display(struct Stack *Top)
{
struct Stack *ptr = Top;
if(Top == NULL)
printf("\n STACK IS EMPTY");
else
{
while(ptr != NULL)
{
printf("\n %d", ptr->data);
ptr = ptr -> next;
}
}
return Top;
}

// to displau to data
int peek(struct Stack *top)
{
if(top==NULL)
return -1;
else
return Top->data;
}


int main() {
int val, option;
do
{
printf("\n *****MAIN MENU*****");
printf("\n 1. PUSH");
printf("\n 2. POP");
printf("\n 3. PEEK");
printf("\n 4. DISPLAY");
printf("\n 5. EXIT");
printf("\n Enter your option: ");
scanf("%d", &option);
switch(option)
{
case 1:
printf("\n Enter the number to be pushed on stack: ");
scanf("%d", &val);
Top = push(Top, val);
break;
case 2:
Top = pop(Top);
break;
case 3:
val = peek(Top);
if (val != -1)
printf("\n The value at the top of stack is: %d", val);
else
printf("\n STACK IS EMPTY");
break;
case 4:
Top = display(Top);
break;
}
}while(option != 5);
return 0;
}


