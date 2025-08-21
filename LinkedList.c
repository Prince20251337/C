#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct node {
    int data;             // Data part
    struct node *link;    // Pointer to the next node
};

// Function to add a node at the front
void add_at_front(struct node **head, int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = *head;   // Point new node to old head
    *head = newNode;         // Update head to new node
}

// Function to insert a node in the middle (after given position)
void insert_in_middle(struct node *head, int pos, int value) {
    struct node *temp = head;
    int i = 1;

    // Traverse to the position
    while (i < pos && temp != NULL) {
        temp = temp->link;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    // Create new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;

    // Link adjustments
    newNode->link = temp->link;
    temp->link = newNode;
}

// Function to delete a node from the end
void delete_from_end(struct node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = *head;

    // If only one node
    if (temp->link == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    // Traverse till second last node
    while (temp->link->link != NULL) {
        temp = temp->link;
    }

    free(temp->link);       // Free last node
    temp->link = NULL;      // Make second last node the last
}

// Function to print linked list
void print_list(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    // Step 1: Create head node
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    // Step 2: Add second node
    struct node *second = (struct node *)malloc(sizeof(struct node));
    second->data = 8;
    second->link = NULL;
    head->link = second;

    // Step 3: Add third node
    struct node *third = (struct node *)malloc(sizeof(struct node));
    third->data = 3;
    third->link = NULL;
    second->link = third;

    printf("Initial List:\n");
    print_list(head);

    // Add at front
    add_at_front(&head, 99);
    printf("After adding 99 at front:\n");
    print_list(head);

    // Insert in middle (after 2nd node)
    insert_in_middle(head, 2, 77);
    printf("After inserting 77 after 2nd node:\n");
    print_list(head);

    // Delete from end
    delete_from_end(&head);
    printf("After deleting from end:\n");
    print_list(head);

    return 0;
}
