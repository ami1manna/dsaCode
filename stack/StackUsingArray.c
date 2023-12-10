#include<stdio.h>
#define MAX 100
int stack[MAX];
int top = -1 ;

void push(int x){
    if(top == MAX -1){
        printf("stack id full\n");
        
    }
    else {
        
        stack[++top] = x;
        printf("Element %d inserted at stack", x);
    }
}

void pop(){
    if(top = -1){

        printf("stack empty\n");

    }
    else{

        printf("ELEMENT %d id popped",  stack[top--]);
    }

}

void display(){
    if(top == -1){
 printf("stack empty\n");   
    
    }
    else{
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");

    }

}


int main() {
    int choice, value;

    while (1) {
        printf("Stack Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
