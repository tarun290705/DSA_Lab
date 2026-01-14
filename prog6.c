/*  6. Design, Develop and Implement a menu driven Program for the following operations on Circular QUEUE of Characters (Array Implementation of Queue with maximum size MAX).
    a. Insert an Element onto Circular QUEUE.
    b. Delete an Element from Circular QUEUE.
    c. Demonstrate Overflow and Underflow situations on Circular QUEUE.
    d. Display the status of Circular QUEUE.
    e. Exit Support the program with appropriate functions for each of the above operations. 
*/

#include<stdio.h>
#define MAX 10

char q[MAX], ch;
int front = -1, rear = -1;

void enQ() {
    if(((rear+1)%MAX) == front) {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter a character : ");
    scanf(" %c", &ch);

    if(front==-1 && rear==-1) {
        front = rear = 0;
        q[rear] = ch;
    } else {
        rear = (rear + 1) % MAX;
        q[rear] = ch;
    }
}

void deQ() {
    if(front==-1 && rear==-1) {
        printf("Queue Underflow\n");
        return;
    }

    if(front == rear) {
        ch = q[front];
        front = rear = -1;
    } else {
        ch = q[front];
        front = (front + 1) % MAX;
    }

    printf("%c has been dequeued from the queue\n", ch);
}

void display() {
    if(front==-1 && rear==-1) {
        printf("Queue Underflow\n");
        return;
    }

    int i = front;
    do {
        printf("%c ", q[i]);
        i = (i + 1) % MAX;
    } while(i != (rear + 1) % MAX);     
}

int main() {
    int choice;
    
    printf("\nMENU :\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    do {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1 : enQ(); break;
            case 2 : deQ(); break;
            case 3 : display(); break;
            case 4 : printf("Thank You!\n"); break;
            default : printf("Invalid Choice\n");                  
        }
    } while(choice != 4);

    return 0;
}