#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL, *prev = NULL;
    int n, value, delValue;

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

    printf("Enter value to delete: ");
    scanf("%d", &delValue);

    temp = head;

    // Delete head node
    if(head->data == delValue) {
        head = head->next;
        free(temp);
    } else {
        while(temp != NULL && temp->data != delValue) {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL) {
            printf("Value Not Found!\n");
            return 0;
        }

        prev->next = temp->next;
        free(temp);
    }

    printf("After Deletion: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
