#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data ;
    struct Node *right;
    struct Node *left;

}*tree;

//creating a bst
void create_tree(struct Node* );
struct Node *insertElement(struct Node * , int );
struct Node *deleteElement(struct Node * , int );

//travesal 
void preOrderTravesal(struct Node *);
void postOrderTravesal(struct Node *);
void inOrderTravesal(struct Node *);

//more operation
struct Node *findSmallestElement(struct Node *);
struct Node *findLargestElement(struct Node *);
struct Node *mirrorImage(struct Node *);
int totalNodes(struct Node *);
int totalExternalNodes(struct Node *);
int totalInternalNodes(struct Node *);
int Height(struct Node *);
struct Node *deleteTree(struct Node *);


int main(){
    int option, val;
struct Node *ptr;
create_tree(tree);
clrscr();
do
{
    printf("\n ******MAIN MENU******* \n");
printf("\n 1. Insert Element");
printf("\n 2. Preorder Traversal");
printf("\n 3. Inorder Traversal");
printf("\n 4. Postorder Traversal");
printf("\n 5. Find the smallest element");
printf("\n 6. Find the largest element");
printf("\n 7. Delete an element");
printf("\n 8. Count the total number of nodes");
printf("\n 9. Count the total number of external nodes");
printf("\n 10. Count the total number of internal nodes");
printf("\n 11. Determine the height of the tree");
printf("\n 12. Find the mirror image of the tree");
printf("\n 13. Delete the tree");
printf("\n 14. Exit");
printf("\n\n Enter your option : ");
scanf("%d", &option);
switch(option)

{

case 1:
printf("\n Enter the value of the new node : ");
scanf("%d", &val);
tree = insertElement(tree, val);
break;
case 2:
printf("\n The elements of the tree are : \n");
preorderTraversal(tree);
break;
case 3:
printf("\n The elements of the tree are : \n");
inorderTraversal(tree);
break;
case 4:
printf("\n The elements of the tree are : \n");
postorderTraversal(tree);
break;
case 5:
ptr = findSmallestElement(tree);
printf("\n Smallest element is :%d",ptr->data);
break;
case 6:
ptr = findLargestElement(tree);
printf("\n Largest element is : %d", ptr->data);
break;
case 7:
printf("\n Enter the element to be deleted : ");
scanf("%d", &val);

tree = deleteElement(tree, val);
break;
case 8:
printf("\n Total no. of nodes = %d", totalNodes(tree));
break;
case 9:
printf("\n Total no. of external nodes = %d",
totalExternalNodes(tree));
break;
case 10:
printf("\n Total no. of internal nodes = %d",
totalInternalNodes(tree));
break;
case 11:
printf("\n The height of the tree = %d",Height(tree));
break;
case 12:
tree = mirrorImage(tree);
break;
case 13:
tree = deleteTree(tree);
break;

}
}while(option!=14);
getch();
return 0;
}

// main codes

// create function - ?
 void create_tree(struct Node* tree){

tree = NULL;
}
 
 struct Node* insertElement(struct Node* node,int data){
struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
ptr->right = NULL;
ptr->left = NULL;
ptr->data = data;

if(tree == NULL){
 
 }
 else{

 }
