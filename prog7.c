/*  7. Design, Develop and Implement a menu driven Program for the following operations on the Singly Linked List (SLL) of Student Data with the fields: USN, Name, Branch, Sem, PhNo .
    a. Create a SLL of N Students Data by using front insertion.
    b. Display the status of SLL and count the number of nodes in it.
    c. Perform Insertion / Deletion at End of SLL.
    d. Perform Insertion / Deletion at Front of SLL (Demonstration of stack).
    e. Exit.
*/

#include<stdio.h>
#include<stdlib.h>

int count = 0;

struct node {
    char name[25], usn[25], branch[5];
    int sem;
    long int mob;
    struct node *next;
} *head = NULL, *newNode;

void create() {
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;

    printf("Enter Name : ");
    scanf("%s", newNode->name);

    printf("Enter USN : ");
    scanf("%s", newNode->usn);

    printf("Enter Branch : ");
    scanf("%s", newNode->branch);

    printf("Enter Sem : ");
    scanf("%d", &newNode->sem);

    printf("Enter Phone Number : ");
    scanf("%ld", &newNode->mob);

    count++;
}

void insertFirst() {
    create();
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insertEnd() {
    create();
    if(head == NULL) {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;    
}

void deleteFirst() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL) {
        printf("Student with USN %s is deleted\n", head->usn);
        count--;
        free(head);
        return;
    }

    struct node *temp = head;
    head = head->next;
    printf("Student with USN %s is deleted\n", temp->usn);
    count--;
    free(temp);
}

void deleteEnd() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL) {
        printf("Student with USN %s is deleted\n", head->usn);
        count--;
        free(head);
        head = NULL;
        return;
    }
    
    struct node *temp1 = head, *temp2;
    while(temp1->next != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    printf("Student with USN %s is deleted\n", temp1->usn);
    count--;
    temp2->next = NULL;
    free(temp1);
}

void display() {
    int num = 1;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    while(temp != NULL) {
        printf("\nDetails of Student %d :\n", num);
        printf("Name : %s\n", temp->name);
        printf("USN : %s\n", temp->usn);
        printf("Branch : %s\n", temp->branch);
        printf("Sem : %d\n", temp->sem);
        printf("Phone No. : %ld\n", temp->mob);
        temp = temp->next;
        num++;
    }
    printf("Number of student nodes in the list : %d\n", count);
}

int main() {
    int choice;

    printf("\nMENU :\n");
    printf("1. Insert node at beginning\n");
    printf("2. Insert node at end\n");
    printf("3. Delete node at beginning\n");
    printf("4. Delete node at end\n");
    printf("5. Display the nodes\n");
    printf("6. Exit\n");

    do {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1 : insertFirst();
                     break;

            case 2 : insertEnd();
                     break;

            case 3 : deleteFirst();
                     break;

            case 4 : deleteEnd();
                     break;

            case 5 : display();
                     break;

            case 6 : printf("Thank You!\n");
                     break;                 

            default : printf("Invalid Choice\n");                                     
        }
    } while(choice != 6);

    return 0;
}