/*  1. Design, Develop and Implement a menu driven Program for the following array operations.
    a. Creating an array of N Integer Elements.
    b. Display array Elements with Suitable Headings.
    c. Inserting an Element (ELEM) at a given valid Position (POS).
    d. Deleting an Element at a given valid Position (POS).
    e. Exit. Support the program with functions for each of the above operations.
*/

#include<stdio.h>
#define MAX 100

int a[MAX], n, ele, pos;

void create() {
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    printf("Enter %d elements in the array : ", n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
}

void display() {
    printf("Elements of the array are : ");
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");    
}

void insert() {
    printf("Enter the element to be inserted : ");
    scanf("%d", &ele);
    printf("Enter the position : ");
    scanf("%d", &pos);

    for(int i=n-1; i>=pos-1; i--)
        a[i+1] = a[i];
    a[pos-1] = ele;
    n++;    
}

void delete() {
    printf("Enter the position from which the element is to be deleted : ");
    scanf("%d", &pos);

    ele = a[pos-1];
    printf("Deleted element is %d\n", ele);
    for(int i=pos-1; i<n; i++)
        a[i] = a[i+1];
    n--;    
}

int main() {
    int choice;

    printf("\nMENU :\n");
    printf("1. Create an array\n");
    printf("2. Display array elements\n");
    printf("3. Insert an element\n");
    printf("4. Delete an element\n");
    printf("5. Exit\n");

    do {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 : create(); break;
            case 2 : display(); break;
            case 3 : insert(); break;
            case 4 : delete(); break;
            case 5 : printf("Thank You!\n"); break;
            default : printf("Invalid Choice\n");
        }
    } while(choice != 5);
    return 0;
}