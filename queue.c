#include <stdio.h>

int max = 5;
int queue[5] = {10, 20, 30, 40};
int front = 0;
int rear = 3;

void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty!\n");
    } else {
        printf("\nCurrent Queue :\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void enqueue() {
    int value;
    if (rear >= max - 1) {
        printf("\nQueue is full! \n");
    } else {
        printf("\nEnter the value to insert: ");
        scanf("%d", &value);
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
    display();
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nDequeued element: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
    display();
}

int main() {
    int choice;

    do {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Exit\n");
       
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while (choice != 3);

    return 0;
}