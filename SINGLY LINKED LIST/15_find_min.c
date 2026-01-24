#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, value, min;

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

    // Find min
    temp = head;
    min = temp->data;

    while(temp != NULL) {
        if(temp->data < min)
            min = temp->data;
        temp = temp->next;
    }

    printf("Minimum Element = %d\n", min);

    return 0;
}
