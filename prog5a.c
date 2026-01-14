/* 5a. Design, Develop and Implement a Program for the following Stack Applications - Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^.
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAX 20

int stack[MAX], top = -1;

int isEmpty() {
    if(top == -1) return 1;
    else return 0;
}

void push(int c) {
    top++;
    stack[top] = c;
}

int pop() {
    int temp = stack[top];
    top--;
    return temp;
}

int compute(char c, int op1, int op2) {
    switch(c)
    {
        case '+' : return (op1 + op2);
        case '-' : return (op1 - op2);
        case '*' : return (op1 * op2);
        case '/' : return (op1 / op2);
        case '^' : return pow(op1, op2);
        default : return 0;
    }
}

int main() {
    int result, op1, op2;
    char postfix[MAX], c;

    printf("Enter a Postfix Expression : ");
    scanf("%s", postfix);

    for(int i=0; i<strlen(postfix); i++)
    {
        c = postfix[i];

        if(isdigit(c))
            push(c - '0');

        else
        {
            op1 = pop();
            op2 = pop();
            result = compute(c, op1, op2);
            push(result);
        }    
    }

    result = stack[top];
    printf("The value of the given expression is %d\n", result);
    return 0;
}