#include<stdio.h>
#include<malloc.h>
#define SIZE 10

struct Node{
    int data ;
    struct Node* next;
};

struct Node* hashTable[SIZE];

//Fuction To insitialize the hash table

void insitializeHashTable(){
    for (int i=0; i<SIZE; i++){
        hashTable[i]= NULL;
    }
}

int hashCode(int k){
    return k % SIZE;
}
//Functon to insert a key into hash table 
void insert(int key)
{

    int i = hashCode(key);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key ;
    newNode->next = NULL;

    if(hashTable[i] == NULL){
        hashTable[i] = newNode;
    }
    else{
        //chaining technique
         struct Node* temp = hashTable[i];
         while(temp->next != NULL){
            temp = temp->next;

         }
         temp->next = newNode;
         }

    }

    //function to search for a node

int search(int key){
int i = hashCode(key);
struct Node *temp = hashTable[i];
while(temp!=NULL){
    if(temp->data == key)
    {   // if found 
        return 1;
    }
temp = temp->next;

}      
      // if not found 
       return 0 ;
}

void displayHashTable(){
for(int i = 0; i < SIZE; i++){
printf("Index %d: ", i);
struct Node *temp =  hashTable[i];
while(temp!=NULL)
{
    printf("%d \t", temp->data);
    temp = temp->next;
}
printf("\n");


}

}
void deleteKey(int key) {
    int i = hashCode(key);
    struct Node* current = hashTable[i];
    struct Node* prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Key %d not found in the hash table\n", key);
        return;
    }

    if (prev == NULL) {
        // Deleting the first node
        hashTable[i] = current->next;
    } else {
        // Deleting a node that is not the first one
        prev->next = current->next;
    }

    free(current);
    printf("Key %d deleted from the hash table\n", key);
}

int main() {
  insitializeHashTable();

    int choice, key;

    do {
        printf("\nHashing Techniques Menu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display Hash Table\n");
        printf("4. delete\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(key)) {
                    printf("Key %d found in the hash table.\n", key);
                } else {
                    printf("Key %d not found in the hash table.\n", key);
                }
                break;

            case 3:
                displayHashTable();
                break;
              
                case 4:
                printf("Enter the key to delete: ");
              scanf("%d", &key);
           deleteKey(key);
                break;


            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}