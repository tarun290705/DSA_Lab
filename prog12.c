/*  12. Given a file of N employee records with a set K of Keys (4-digit) which uniquely determines the records in file F. 
    Assume that file F is maintained in memory by a Hash Table (HT) of m memory locations with L as the set of memory addresses (2-digit) of locations in HT. 
    Let the keys in K and addresses in L are Integers. 
    Design and develop a Program in C that uses Hash function H: K→ L as H(K)=K mod m (remainder method), and implement hashing technique to map a given key K to the address space L. 
    Resolve the collision (if any) using linear probing.
*/

#include<stdio.h>
#include<string.h>
#define MAX 100

struct Employee {
    int key;
    char name[25];
};

struct Employee HT[MAX];
int size;

void initializeHT(int n) {
    size = n;
    for(int i=0; i<n; i++) {
        HT[i].key = -1;
        strcpy(HT[i].name, "");
    }
}

int hashFun(int key) {
    return (key % size);
}

void insert(int key, char name[]) {
    int index = hashFun(key);
    int originalIndex = index;
    int i = 0;
    while(HT[i].key != -1) {
        index = (originalIndex + ++i) % size;
        if(index == originalIndex) {
            printf("Hash Table is Full\n");
            return;
        }
    }
    HT[i].key = key;
    strcpy(HT[i].name, name);
    printf("Inserted key - %d, Name - %s, Index - %d\n", key, name, index);
}

void search(int key) {
    int index = hashFun(key);
    int originalIndex = index;
    int i = 0;
    while(HT[i].key != -1) {
        if(HT[i].key == key) {
            printf("Name - %s, Key - %d, Index - %d\n", HT[i].name, key, index);
            return;
        }
        index = (originalIndex + ++i) % size;
        if(index == originalIndex)
            break;
    }
    printf("Key %d is not found in the Hash Table\n", key);
}

void display() {
    printf("Hash Table :\n");
    for(int i=0; i<size; i++) {
        if(HT[i].key != -1)
            printf("Name - %s, Key - %d, Index - %d\n", HT[i].name, HT[i].key, i);
        else
            printf("Index - %d : Empty\n", i);
    }
}

int main() {
    int n, choice, key;
    char name[25];

    printf("Enter the size of the Hash Table : ");
    scanf("%d", &n);
    initializeHT(n);

    printf("\nMENU :\n");
    printf("1. Insert a record\n");
    printf("2. Search for a key\n");
    printf("3. Display Hash Table\n");
    printf("4. Exit\n");

    do {
        printf("\nEnter youe choice : ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1 : printf("Enter Employee Key (4-digit) : ");
                     scanf("%d", &key);
                     printf("Enter Employee Name : ");
                     scanf("%s", name);
                     insert(key, name);
                     break;

            case 2 : printf("Enter the key to be searched : ");
                     scanf("%d", &key);
                     search(key);
                     break;

            case 3 : display();
                     break;

            case 4 : printf("Thank You!\n");
                     break;

            default : printf("Invalid Choice\n");         
        }
    } while(choice != 4);

    return 0;
}