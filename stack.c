#include <stdio.h>

int max=5;
int stack[5] = {10,20,30,40};
int top = 3;

void display() {
    if (top < 0 ) {
        printf("\nStack is empty!\n");
    } else {
        printf("\nCurrent Stack :\n");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
    }
}

void push() {
    int value;
    if (top >= max - 1) {
        printf("\nStack is full! \n");
    } else {
        printf("\nEnter the value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }
    display();
}

void pop() {
    if (top < 0) {
        printf("\nStack is empty\n");
    } else {
        printf("\nPopped element: %d", stack[top]);
        top--;
    }
    display();
}


int main() {
    int choice;

    do {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop \n");
        printf("3. Exit\n");
       
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
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