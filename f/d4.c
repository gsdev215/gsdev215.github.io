#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = item;
}

char pop() {
    if (top < 0) {
        return '\0';
    }
    char item = stack[top];
    top--;
    return item;
}

int precedence(char symbol) {
    if (symbol == '^') {
        return 3;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}

int isOperator(char symbol) {
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^') {
        return 1;
    }
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;
    char item, x;

    printf("Enter Infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        item = infix[i];

        if (isalnum(item)) {
            postfix[j] = item;
            j++;
        } else if (item == '(') {
            push(item);
        } else if (item == ')') {
            x = pop();
            while (x != '(' && x != '\0') {
                postfix[j] = x;
                j++;
                x = pop();
            }
        } else if (isOperator(item) == 1) {
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j] = pop();
                j++;
            }
            push(item);
        }
        i++;
    }

    while (top != -1) {
        postfix[j] = pop();
        j++;
    }
    
    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
