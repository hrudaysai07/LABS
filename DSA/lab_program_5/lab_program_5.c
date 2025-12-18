#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void deleteSpecific(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == key) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node *curr = head;
    while (curr->next != NULL && curr->next->data != key)
        curr = curr->next;

    if (curr->next == NULL) {
        printf("Element not found.\n");
    } else {
        struct Node *temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }
}

void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Create (Insert)\n2. Delete Last\n3. Delete Specific\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                create(value);
                break;

            case 2:
                deleteLast();
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteSpecific(value);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
