#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// ---------------- CREATE NODE ----------------
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// ---------------- 1. CREATE LINKED LIST ----------------
void createLinkedList(int n) {
    int value;
    struct Node* temp = NULL;

    for (int i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Linked List Created Successfully!\n");
}

// ---------------- 2. INSERT AT BEGINNING ----------------
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);

    newNode->next = head;
    head = newNode;

    printf("Inserted at Beginning!\n");
}

// ---------------- 3. INSERT AT END ----------------
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        printf("Inserted as First Node!\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("Inserted at End!\n");
}

// ---------------- 4. INSERT AT POSITION ----------------
void insertAtPosition(int value, int pos) {
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid Position!\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted at Position %d!\n", pos);
}

// ---------------- 5. DELETE FROM BEGINNING ----------------
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);

    printf("Deleted from Beginning!\n");
}

// ---------------- 6. DELETE FROM END ----------------
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    struct Node* temp = head;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last Node Deleted!\n");
        return;
    }

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    printf("Deleted from End!\n");
}

// ---------------- 7. DELETE BY VALUE ----------------
void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (head->data == value) {
        head = head->next;
        free(temp);
        printf("Deleted Value %d!\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value Not Found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Deleted Value %d!\n", value);
}

// ---------------- 8. SEARCH ELEMENT ----------------
void searchElement(int value) {
    struct Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d Found at Position %d!\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element Not Found!\n");
}

// ---------------- 9. COUNT NODES ----------------
void countNodes() {
    struct Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total Nodes = %d\n", count);
}

// ---------------- 10. DISPLAY LIST ----------------
void displayList() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("Linked List is Empty!\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---------------- 11. SORT LIST ----------------
void sortList() {
    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    struct Node* i;
    struct Node* j;
    int tempData;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }

    printf("Linked List Sorted Successfully!\n");
}

// ---------------- 12. REVERSE LIST ----------------
void reverseList() {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    head = prev;

    printf("Linked List Reversed Successfully!\n");
}

// ---------------- 13. UPDATE NODE VALUE ----------------
void updateNode(int oldValue, int newValue) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            printf("Node Updated Successfully!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Value Not Found!\n");
}

// ---------------- 14. FIND MAX ----------------
void findMax() {
    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    int max = head->data;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    }

    printf("Maximum Element = %d\n", max);
}

// ---------------- 15. FIND MIN ----------------
void findMin() {
    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    int min = head->data;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data < min)
            min = temp->data;
        temp = temp->next;
    }

    printf("Minimum Element = %d\n", min);
}

// ---------------- 16. DELETE ENTIRE LIST ----------------
void deleteEntireList() {
    struct Node* temp = head;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("Entire Linked List Deleted Successfully!\n");
}

// ---------------- MAIN MENU ----------------
int main() {
    int choice, value, pos, n, oldValue, newValue;

    while (1) {
        printf("\n========== LINKED LIST MENU (16 OPERATIONS) ==========\n");
        printf("1.  Create Linked List\n");
        printf("2.  Insert at Beginning\n");
        printf("3.  Insert at End\n");
        printf("4.  Insert at Specific Position\n");
        printf("5.  Delete from Beginning\n");
        printf("6.  Delete from End\n");
        printf("7.  Delete by Value\n");
        printf("8.  Search Element\n");
        printf("9.  Count Nodes\n");
        printf("10. Display List\n");
        printf("11. Sort List\n");
        printf("12. Reverse List\n");
        printf("13. Update Node Value\n");
        printf("14. Find Maximum Element\n");
        printf("15. Find Minimum Element\n");
        printf("16. Delete Entire List\n");
        printf("17. Exit\n");
        printf("=====================================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createLinkedList(n);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(value, pos);
                break;

            case 5:
                deleteFromBeginning();
                break;

            case 6:
                deleteFromEnd();
                break;

            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;

            case 8:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchElement(value);
                break;

            case 9:
                countNodes();
                break;

            case 10:
                displayList();
                break;

            case 11:
                sortList();
                break;

            case 12:
                reverseList();
                break;

            case 13:
                printf("Enter old value: ");
                scanf("%d", &oldValue);
                printf("Enter new value: ");
                scanf("%d", &newValue);
                updateNode(oldValue, newValue);
                break;

            case 14:
                findMax();
                break;

            case 15:
                findMin();
                break;

            case 16:
                deleteEntireList();
                break;

            case 17:
                printf("Exiting Program...\n");
                exit(0);

            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }

    return 0;
}
