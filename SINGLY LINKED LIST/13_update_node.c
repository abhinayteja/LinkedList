#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, value, oldValue, newValue;

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

    printf("Enter value to update: ");
    scanf("%d", &oldValue);

    printf("Enter new value: ");
    scanf("%d", &newValue);

    temp = head;
    while(temp != NULL) {
        if(temp->data == oldValue) {
            temp->data = newValue;
            printf("Node Updated Successfully!\n");
            break;
        }
        temp = temp->next;
    }

    printf("Updated Linked List: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
