/* 4. Design, Develop and Implement a Program for converting an Infix Expression to Postfix Expression. Program should support for both parenthesized and free parenthesized expressions with the operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric operands.
*/

#include<stdio.h>
#include<string.h>
#define MAX 20

char infix[MAX], postfix[MAX], stack[MAX];
int top = -1;

int isEmpty() {
    if(top == -1) return 1;
    else return 0;
}

void push(char c) {
    top++;
    stack[top] = c;
}

char pop() {
    char temp = stack[top];
    top--;
    return temp;
}

int precedence(char c) {
    switch(c) {
        case '+' :
        case '-' : return 1;

        case '*' : 
        case '/' : return 2;

        case '^' : return 3;

        default : return 0;
    }
}

void convert(char *infix, char *postfix) {
    int j = 0;
    char c, next;

    for(int i=0; i<strlen(infix); i++) {
        c = infix[i];

        switch(c) {
            case '(' : push(c);
                       break;

            case ')' : while((next=pop()) != '(')
                            postfix[j++] = next;
                       break;

            case '+' :
            case '-' :
            case '*' :
            case '/' :
            case '^' : while(!isEmpty() && (precedence(stack[top]) >= precedence(c)))
                            postfix[j++] = pop();
                       push(c);
                       break;

            default : postfix[j++] = c;
                      break;                                
        }
    }
    while(!isEmpty())
        postfix[j++] = pop();

    postfix[j] = '\0';    
}

int main() {
    printf("Enter an Infix Expression : ");
    scanf("%s", infix);

    convert(infix, postfix);

    printf("\nInfix Expression : %s\n", infix);
    printf("Postfix Expression : %s\n", postfix);

    return 0;
}