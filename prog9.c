/*  9. Design, Develop and Implement a Program for the following operations on Singly circular Linked List (SCLL) with header nodes
    a. Represent and Evaluate a Polynomial P(x,y,z) = 6x2y2z-4yz5 +3x3 yz+2xy5 z-2xyz3 .
    b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the result in POLYSUM(x,y,z) Support the program with appropriate functions for each of the above operations.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node {
    int coef, x, y, z;
    struct node *next;
};

struct node *create(int coef, int x, int y, int z) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = newNode;
    newNode->coef = coef;
    newNode->x = x;
    newNode->y = y;
    newNode->z = z;
    return newNode;
}

void display(struct node *head) {
    if(head == NULL)
        return;

    struct node *temp = head;
    do {
        printf("%dx^%dy^%dz^%d ", temp->coef, temp->x, temp->y, temp->z);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insertEnd(struct node **head, int coef, int x, int y, int z) {
    struct node *newNode = create(coef, x, y, z);
    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while(temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;    
}

void evaluate(struct node *head, int x, int y, int z) {
    if(head == NULL)
        return;

    float result = 0;
    struct node *temp = head;
    do {
        result = result + (temp->coef * pow(x, temp->x) * pow(y, temp->y) * pow(z, temp->z));
        temp = temp->next;
    } while(temp != head);

    printf("Result : %.2f\n", result);
}

struct node *isSameDegree(struct node *head, int x, int y, int z) {
    if(head == NULL)
        return NULL;

    struct node *temp = head;
    do {
        if(temp->x==x &&temp->y==y && temp->z==z)
            return temp;
        temp = temp->next;    
    } while(temp != head);
    return NULL;
}

struct node *add(struct node *p1, struct node *p2) {
    struct node *pSum = NULL, *temp1 = p1, *temp2 = p2;

    do {
        struct node *term = isSameDegree(pSum, temp1->x, temp1->y, temp1->z);
        if(term)
            term->coef += temp1->coef;
        else
            insertEnd(&pSum, temp1->coef, temp1->x, temp1->y, temp1->z);
        temp1 = temp1->next;        
    } while(temp1 != p1);

    do {
        struct node *term = isSameDegree(pSum, temp2->x, temp2->y, temp2->z);
        if(term)
            term->coef += temp2->coef;
        else
            insertEnd(&pSum, temp2->coef, temp2->x, temp2->y, temp2->z);
        temp2 = temp2->next;        
    } while(temp2 != p2);

    return pSum;
}

int main() {
    struct node *p1 = NULL, *p2 = NULL, *pSum = NULL;

    insertEnd(&p1,6,2,2,1);
    insertEnd(&p1,-4,1,2,5);
    insertEnd(&p1,3,3,1,1);
    insertEnd(&p1,2,1,5,1);
    insertEnd(&p1,-2,1,1,3);

    insertEnd(&p2,1,2,2,1);
    insertEnd(&p2,2,0,1,5);
    insertEnd(&p2,-1,3,1,1);
    insertEnd(&p2,2,1,5,1);
    insertEnd(&p2,-1,1,1,3);

    evaluate(p1, 1, 2, 3);
    printf("Polynomial 1 : ");
    display(p1);
    printf("Polynomial 2 : ");
    display(p2);
    pSum = add(p1, p2);
    printf("Polynomial Sum : ");
    display(pSum);

    return 0;
}