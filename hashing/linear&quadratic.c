#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define TABLE_SIZE 10

int hash(int key){
    return key % TABLE_SIZE;
}

void linearProbingInsert(int hashable[], int key){
    int index = hash(key);
    int i = 1;

    while(hashable[index] != -1){
        index = (index + i) % TABLE_SIZE;
        i++;
    }
    hashable[index] = key;
    printf("\nKey %d placed at index %d using linear probing", key, index);
}

void quadraticProbingInsert(int hashable[], int key){
    int index = hash(key);
    int i = 1;

    while(hashable[index] != -1){
        index = (index + i*i) % TABLE_SIZE;
        i++;
    }
    hashable[index] = key;
    printf("\nKey %d placed at index %d using quadratic probing", key, index);
}

int linearProbingSearch(int hashable[], int key){
    int index = hash(key);
    int i = 1;

    while(hashable[index] != -1){
        if(hashable[index] == key)
            return index;

        index = (index + i) % TABLE_SIZE;
        i++;
    }

    return -1; // Key not found
}

int quadraticProbingSearch(int hashable[], int key){
    int index = hash(key);
    int i = 1;

    while(hashable[index] != -1){
        if(hashable[index] == key)
            return index;

        index = (index + i*i) % TABLE_SIZE;
        i++;
    }

    return -1; // Key not found
}

void linearProbingDelete(int hashable[], int key){
    int index = linearProbingSearch(hashable, key);

    if(index != -1){
        hashable[index] = -1; // Mark as deleted
        printf("\nKey %d deleted from index %d using linear probing", key, index);
    } else {
        printf("\nKey %d not found using linear probing", key);
    }
}

void quadraticProbingDelete(int hashable[], int key){
    int index = quadraticProbingSearch(hashable, key);

    if(index != -1){
        hashable[index] = -1; // Mark as deleted
        printf("\nKey %d deleted from index %d using quadratic probing", key, index);
    } else {
        printf("\nKey %d not found using quadratic probing", key);
    }
}

void displayTables(int hashable[]){
    printf("\nHash Table: ");
    for(int i=0; i<TABLE_SIZE; i++){
        printf("[%d]->%d\n", i, hashable[i]);
    }
}

int main(){
    int linearProbingTable[TABLE_SIZE];
    int quadraticProbingTable[TABLE_SIZE];

    for(int i=0; i<TABLE_SIZE; i++){
        linearProbingTable[i] = -1;
        quadraticProbingTable[i] = -1;
    }
    
    int choice, key;
    do{
        printf("\n1.Linear Probing 2.Quadratic Probing 3.Print Hash Table 4.Search 5.Delete 6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the value to be inserted in Linear Probing Hash table: ");
                scanf("%d", &key);
                linearProbingInsert(linearProbingTable, key);
                break;

            case 2:
                printf("\nEnter the value to be inserted using quadratic probing: ");
                scanf("%d", &key);
                quadraticProbingInsert(quadraticProbingTable, key);
                break;

            case 3:
                displayTables(linearProbingTable);
                displayTables(quadraticProbingTable);
                break;

            case 4:
                printf("\nEnter the value to be searched: ");
                scanf("%d", &key);
                printf("Linear Probing: Key %d found at index %d", key, linearProbingSearch(linearProbingTable, key));
                printf("\nQuadratic Probing: Key %d found at index %d", key, quadraticProbingSearch(quadraticProbingTable, key));
                break;

            case 5:
                printf("\nEnter the value to be deleted: ");
                scanf("%d", &key);
                linearProbingDelete(linearProbingTable, key);
                quadraticProbingDelete(quadraticProbingTable, key);
                break;

            case 6:
                exit(0);
                break;
        }
    } while(1);
    return 0;
}
