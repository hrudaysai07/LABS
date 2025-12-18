#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Node* insertLeft(struct Node* head, int target, int value) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target node %d not found!\n", target);
        return head;
    }
    struct Node* newNode = createNode(value);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }
    temp->prev = newNode;
    printf("Inserted %d to the left of %d\n", value, target);
    return head;
}

struct Node* deleteNode(struct Node* head, int target) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node %d not found!\n", target);
        return head;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    printf("Deleted node with value %d\n", target);
    free(temp);
    return head;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice,target,value;
    printf("\n double linked list operations\n");
    printf("1.insertend\n3.insetleft\n2.deletenode\n3.display\n4.exit\n");
    while (1){
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter integer to insert:");
                    scanf("%d",&value);
                    head=insertEnd(head,value);
                    break;
            case 2: printf("enter the number on which we should insert before");
                    scanf("%d",&target);
                    printf("enter the integer to insert:");
                    scanf("%d",&value);
                    head=insertLeft(head,target,value);
                    break;
            case 3: printf("enter the integer to delect:");
                    scanf("%d",&value);
                    head=deleteNode(head,value);
                    break;
            case 4: displayList(head);
                    break;
            case 5: printf ("exiting program \n");
                    return 0;
            default : printf("invalid choice");
        }
    }

    return 0;
}1
