#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
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

    // Delete last node
    if(head == NULL) {
        printf("List is Empty!\n");
    } 
    else if(head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last Node Deleted!\n");
    } 
    else {
        temp = head;
        while(temp->next->next != NULL)
            temp = temp->next;

        free(temp->next);
        temp->next = NULL;
        printf("Deleted from End!\n");
    }

    printf("Remaining List: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
