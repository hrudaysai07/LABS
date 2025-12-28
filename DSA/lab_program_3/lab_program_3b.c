#include <stdio.h>
#define n 2

int queue[n], front = -1, rear = -1;

void insert(int value) {
    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        printf("overflow\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else if (rear == n - 1) {
        rear = 0;
    }
    else {
        rear = rear + 1;
    }

    queue[rear] = value;
    printf("%d value inserted\n", value);
}

void delete() {
    int item;

    if (front == -1) {
        printf("underflow\n");
        return;
    }

    item = queue[front];   // store element

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (front == n - 1) {
        front = 0;
    }
    else {
        front = front + 1;
    }

    printf("%d value deleted\n", item);
}

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    if (rear >= front) {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (i = front; i < n; i++)
            printf("%d ", queue[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice = 0, value;

    printf("\nCircular Queue Menu:\n");
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");

    while (1) {
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Enter numbers only.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
