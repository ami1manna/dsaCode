#include <stdio.h>
#include <conio.h>
// Node structure for a BST element
struct Node {
 int data;
 struct Node* left;
 struct Node* right;
};
// Function to create a new node
struct Node* createNode(int value) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 if (newNode == NULL) {
 printf("Memory allocation failed\n");

 }
 newNode->data = value;
 newNode->left = newNode->right = NULL;
 return newNode;
}
// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
 if (root == NULL) {
 return createNode(value);
 }
 if (value < root->data) {
 root->left = insert(root->left, value);
 } else if (value > root->data) {
 root->right = insert(root->right, value);
 }
 return root;
}
// Function to find the minimum value node in a BST
struct Node* findMin(struct Node* node) {
 while (node->left != NULL) {
 node = node->left;
 }
 return node;
}
// Function to delete a value from the BST
struct Node* deleteNode(struct Node* root, int value) {
 if (root == NULL) {
 return root;
 }
 if (value < root->data) {
 root->left = deleteNode(root->left, value);
 } else if (value > root->data) {
 root->right = deleteNode(root->right, value);
 } else {
 // Node with only one child or no child
 if (root->left == NULL) {
 struct Node* temp = root->right;
 free(root);
 return temp;
 } else if (root->right == NULL) {
 struct Node* temp = root->left;
 free(root);
 return temp;
 }
 // Node with two children: Get the inorder successor (smallest
 // in the right subtree) and replace the current node's data
 root->data = findMin(root->right)->data;
 // Delete the inorder successor
 root->right = deleteNode(root->right, root->data);
 }
 return root;
}
// Function to search for a value in the BST
struct Node* search(struct Node* root, int value) {
 if (root == NULL || root->data == value) {
 return root;
 }
 if (value < root->data) {
 return search(root->left, value);
 } else {
 return search(root->right, value);
 }
}
// Function to display the elements of the BST in inorder
void inorderTraversal(struct Node* root) {
 if (root != NULL) {
 inorderTraversal(root->left);
 printf("%d ", root->data);
 inorderTraversal(root->right);
 }
}
// Function to free the memory allocated for the BST
void freeBST(struct Node* root) {
 if (root != NULL) {
 freeBST(root->left);
 freeBST(root->right);
 free(root);
 }
}
struct Node* result;
int main() {
 struct Node* root = NULL;
 int choice, value;
 do {
 printf("\nBinary Search Tree (BST) Menu:\n");
 printf("1. Insert\n");
 printf("2. Delete\n");
 printf("3. Search\n");
 printf("4. Display (Inorder Traversal)\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter the value to insert: ");
 scanf("%d", &value);
 root = insert(root, value);
break;
 case 2:
 printf("Enter the value to delete: ");
 scanf("%d", &value);
root = deleteNode(root, value);
 break;
 case 3:
 printf("Enter the value to search: ");
 scanf("%d", &value);
 result = search(root, value);
 if (result != NULL) {
 printf("Value %d found in the BST\n", value);
 } else {
 printf("Value %d not found in the BST\n", value);
 }
 break;
 case 4:
 printf("Inorder Traversal: ");
 inorderTraversal(root);
printf("\n");
 break;
 case 5:
 // Free memory and exit
freeBST(root);
 printf("Exiting the program.\n");
 exit(0);
 default:
 printf("Invalid choice! Please enter a number between 1 and 5.\n");
 }
 } while (1);
 return 0;
}
