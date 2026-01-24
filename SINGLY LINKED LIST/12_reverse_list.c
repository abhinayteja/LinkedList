#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    struct Node *prev = NULL, *curr = NULL, *nextNode = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create list
    for(int i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Reverse list
    curr = head;
    while(curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextNode;
    }

    head = prev;

    printf("Reversed Linked List: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
