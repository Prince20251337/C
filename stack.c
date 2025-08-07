#include <stdio.h>
#define MAX 10

int push(int[], int);
int pop(int[], int);
void peek(int[], int);
void disp(int[], int);

int main() {
    int stack[MAX], top = -1, ch;

    do {
        printf("\n1 = Push\n2 = Pop\n3 = Peek\n4 = Display\n5 = Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                top = push(stack, top);
                break;
            case 2:
                top = pop(stack, top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                disp(stack, top);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(ch != 5);

    return 0;
}

// Push operation
int push(int stack[], int top) {
    int x;
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
    return top;
}

// Pop operation
int pop(int stack[], int top) {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        int x = stack[top];
        printf("Popped value: %d\n", x);
        top--;
    }
    return top;
}

// Peek operation
void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

// Display operation
void disp(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        while(top>=0) {
            printf("%d\n", stack[top]);
        }
    }
}
