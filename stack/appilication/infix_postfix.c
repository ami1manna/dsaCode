#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
char infix[MAX],postfix[MAX];
int top = -1 ;
 
int isEmpty(){
    if(top == -1)
    return 1;
    else
    return 0 ;
}
void push(int d){
    if(top == MAX -1){
        printf("Stack is full");
    }
    else{
        stack[++top] = d;
    }

}
int pop(){
    if(isEmpty()){
        printf("Stack is empty");

    }
    else{
        return stack[top--];
        
    }
}
int precedence(char symbol){
    //consider higher value grater precedece
      switch (symbol)
    {
    // Higher value means higher precedence
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void inToPost(){
    int i,j =0 ;
    char symbol,next;
    for(i=0;i<strlen(infix);i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
        push(symbol);
        break;

        case ')':
        while((next==pop())!= '(')
           postfix[j++] = next;

        break;
        
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        while  (!isEmpty()&& precedence(stack[top]) >= precedence(symbol))
                postfix[j++] = pop();
              push(symbol);//{stack + * } (symbol = -) ->{stack push(-) }, pop{* +}
               break;
                

        
        default:
        //for operands
        postfix[j++] = symbol;
            
        }
    }


//when stack is left with [+-*] some operators
while(!isEmpty())
postfix[j++] = pop();

//end of string 
postfix[j] = '\0';

}




//[Stack is emtpy]  postfix[ab+]
int evaluatePostfix(char postfix[]) {
    int i, operand, op1, op2;

    for (i = 0; i < strlen(postfix); i++) {
        if (isdigit(postfix[i])) {
            operand = postfix[i] - '0';
            push(operand);
        } else {
            op2 = pop();
            op1 = pop();

            switch (postfix[i]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                case '^':
                    push(op1 ^ op2);
                    break;
            }
        }
    }

    return pop();
}
int main(){
  
    printf("Enter the infix Expression:");
    scanf("%s",infix);
    
    inToPost();
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result after evaluation: %d\n", result);

    return 0;
}



