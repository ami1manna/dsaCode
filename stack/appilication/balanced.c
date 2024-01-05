#include<stdio.h>
#include<string.h>
#define Max 100
int stack[Max];
int top  = -1;

void push(char data){
    if(top == Max -1 )
    printf("overflow");
    else
    stack[++top] = data;
}

char pop(){
if(top == -1)
printf("underflow");
else
return stack[top--];

}


int main(){
// for string
int flag =1; 
char exp[Max];
gets(exp);

for(int i = 0 ; i < strlen(exp); i++){

// for ( { [
    if(exp[i]=='(' ||exp[i]=='[' ||exp[i]=='{'){
    push(exp[i]);
    }
    // for } ) ]
   if(exp[i]==')' ||exp[i]=='}' ||exp[i]==']'){
    // top -1 
    if(top ==-1)
    flag = 0;
    else
    {
        char c  =pop();
    // {  (  }
    if(exp[i]=='}' && (c == '('||c =='[') )
    flag = 0;
    if(exp[i]==')' && (c == '{'||c =='[') )
    flag = 0;
    if(exp[i]==']' && (c == '('||c =='{') )
    flag = 0;
    

    } 
  
   }





}
if(top>=0)
flag = 0 ;
if(flag)
printf("valid");
else
printf("invalid");


}


