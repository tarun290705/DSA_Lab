/*  3. Design, Develop and Implement a menu driven Program for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX)
    a. Push an Element onto Stack.
    b. Pop an Element from Stack.
    c. Demonstrate how Stack can be used to check Palindrome.
    d. Demonstrate Overflow and Underflow situations on Stack.
    e. Display the status of Stack.
    Exit Support the program with appropriate functions for each of the above operations.
*/

#include<stdio.h>
#define MAX 10

int stack[MAX], top = -1;

void push() {
    int ele;
    
    if(top == MAX-1) {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter the element to be pushed : ");
    scanf("%d", &ele);
    top++;
    stack[top] = ele;
}

void pop() {
    int ele;

    if(top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    ele = stack[top];
    top--;
    printf("Poped element is %d\n", ele);
}

void pallindrome() {
   int flag = 1;
   
    printf("Stack Contents : ");
    for(int i=top; i>=0; i--)
        printf("%d ", stack[i]);
    printf("\n");

    printf("Reverse of Stack Contents : ");
    for(int i=0; i<=top; i++)
        printf("%d ", stack[i]);
    printf("\n");

    for(int i=0; i<=top/2; i++) {
        if(stack[i] != stack[top-i]) {
            flag = 0;
            break;
        }
    }    

    if(flag)
        printf("The number is pallindrome\n");
    else 
        printf("The number is not a pallindrome\n");    
}

void display() {
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Stack Elements : ");
    for(int i=top; i>=0; i--)
        printf("%d ", stack[i]);
    printf("\n");    
}

int main() {
    int choice;

    printf("\nMENU :\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Pallindrome\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    do {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 : push(); break;
            case 2 : pop(); break;
            case 3 : pallindrome(); break;
            case 4 : display(); break;
            case 5 : printf("Thank You!\n"); break;
            default : printf("Invalid Choice\n");
        }
    } while(choice != 5);
    return 0;
}