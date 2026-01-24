#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *newNode;

    int value;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;

    head = newNode;

    printf("After Insertion: %d -> NULL\n", head->data);

    return 0;
}
