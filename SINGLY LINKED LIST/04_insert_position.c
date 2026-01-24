#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create initial list
    for(int i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
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

    printf("Enter value to insert: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &pos);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        temp = head;
        for(int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if(temp == NULL) {
            printf("Invalid Position!\n");
            return 0;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("After Insertion: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
