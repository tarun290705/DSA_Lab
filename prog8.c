/*   8. Design, Develop and Implement a menu driven Program for the following operations on Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name, Dept, Designation, Sal, PhNo .
    a. Create a DLL of N Employees Data by using end insertion. 
    b. Display the status of DLL and count the number of nodes in it.
    c. Perform Insertion and Deletion at End of DLL .
    d. Perform Insertion and Deletion at Front of DLL.
    e. Demonstrate how this DLL can be used as Double Ended Queue.
    f. Exit.
*/

#include<stdio.h>
#include<stdlib.h>

int count = 0;

struct node {
    char name[25], ssn[10], des[10], dept[10];
    int sal;
    long int mob;
    struct node *next, *prev;
} *head = NULL, *newNode;

void create() {
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = newNode->prev = NULL;

    printf("Enter Name : ");
    scanf("%s", newNode->name);

    printf("Enter SSN : ");
    scanf("%s", newNode->ssn);

    printf("Enter Department : ");
    scanf("%s", newNode->dept);

    printf("Enter Designation : ");
    scanf("%s", newNode->des);

    printf("Enter Salary : ");
    scanf("%d", &newNode->sal);

    printf("Enter Phone Number : ");
    scanf("%ld", &newNode->mob);
}

void insertFront() {
    create();
    if(head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    count++;
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
    newNode->prev = temp;
    temp->next = newNode;
    count++;    
}

void deleteFront() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node *temp = head;
    printf("Employee with SSN %s is deleted\n", temp->ssn);
    head = head->next;
    head->prev = NULL;
    free(temp);
    count--;
}

void deleteEnd() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    printf("Employee with SSN %s is deleted\n", temp->ssn);
    struct node *curr = temp->prev;
    curr->next = NULL;
    free(temp); 
    count--;   
}

void display() {
    int num = 1;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    while(temp != NULL) {
        printf("\nDetails of Employee %d :\n", num);
        printf("Name : %s\n", temp->name);
        printf("SSN : %s\n", temp->ssn);
        printf("Department : %s\n", temp->dept);
        printf("Designation : %s\n", temp->des);
        printf("Salary : %d\n", temp->sal);
        printf("Phone Number : %d\n", temp->mob);
        temp = temp->next;
        num++;
    }
    printf("\nNumber of Employee nodes in the list : %d\n", count);
}

int main() {
    int choice;

    printf("DLL as Double Ended Queue :\n");
    printf("1. Insertion at Queue Front\n");
    printf("2. Insertion at Queue End\n");
    printf("3. Deletion at Queue Front\n");
    printf("4. Deletion at Queue End\n");
    printf("5. Display Queue\n");
    printf("6. Exit\n");

    do {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 : insertFront(); break;
            case 2 : insertEnd(); break;
            case 3 : deleteFront(); break;
            case 4 : deleteEnd(); break;
            case 5 : display(); break;
            case 6 : printf("Thank You!\n"); break;
            default : printf("Inavlid Choice\n");
        }
    } while(choice != 6);

    return 0;
}