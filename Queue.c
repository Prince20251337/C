#include <stdio.h>
#define MAX 10

int enqueue(int[], int, int);
int dequeue(int[], int, int);
void peek(int[], int, int);
void disp(int[], int, int);

int main() {
    int queue[MAX], front = -1, rear = -1, ch;

    do {
        printf("\n1 = Enqueue\n2 = Dequeue\n3 = Peek\n4 = Display\n5 = Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                rear = enqueue(queue, front, rear);
                if(front == -1 && rear != -1) front = 0; // First element added
                break;
            case 2:
                front = dequeue(queue, front, rear);
                if(front > rear) { // Queue becomes empty
                    front = rear = -1;
                }
                break;
            case 3:
                peek(queue, front, rear);
                break;
            case 4:
                disp(queue, front, rear);
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

// Enqueue operation
int enqueue(int queue[], int front, int rear) {
    int x;
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
    } else {
        printf("Enter value to enqueue: ");
        scanf("%d", &x);
        rear++;
        queue[rear] = x;
    }
    return rear;
}

// Dequeue operation
int dequeue(int queue[], int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
    } else {
        int x = queue[front];
        printf("Dequeued value: %d\n", x);
        front++;
    }
    return front;
}

// Peek operation
void peek(int queue[], int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

// Display operation
void disp(int queue[], int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements:\n");
        for(int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}
