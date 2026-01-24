#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, value, searchValue, pos = 1;

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

    printf("Enter value to search: ");
    scanf("%d", &searchValue);

    temp = head;
    while(temp != NULL) {
        if(temp->data == searchValue) {
            printf("Element %d found at Position %d\n", searchValue, pos);
            return 0;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element Not Found!\n");

    return 0;
}
