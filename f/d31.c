#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void push(int stack[], int *top, int value) {
    if (*top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    (*top)++;
    stack[*top] = value;
    printf("Element pushed.\n");
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element: %d\n", stack[*top]);
    (*top)--;
}

void printTop(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

int main() {
    int stack[MAX];
    int top = -1;
    int choice, value;

    while (1) {
        printf("\n--- Stack (Array) Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Top\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, &top, value);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                printTop(stack, top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
