#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void displayList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Element deleted from the beginning.\n");
}

void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Element deleted from the end.\n");
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    free(temp->next);
    temp->next = NULL;
    printf("Element deleted from the end.\n");
}

int countElements(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void reverseList(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to reverse.\n");
        return;
    }
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("List reversed successfully.\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, count;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert element at end\n");
        printf("2. Delete element from the beginning\n");
        printf("3. Delete element from the end\n");
        printf("4. Count the number of elements\n");
        printf("5. Reverse the list\n");
        printf("6. Display the list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                deleteFromBeginning(&head);
                break;
            case 3:
                deleteFromEnd(&head);
                break;
            case 4:
                count = countElements(head);
                printf("Number of elements in the list: %d\n", count);
                break;
            case 5:
                reverseList(&head);
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
