#include <stdio.h>
#include <stdlib.h>

// Doubly Node Structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// ---------------- CREATE NODE ----------------
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// ---------------- 1. CREATE DOUBLY LINKED LIST ----------------
void createList(int n) {
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
            newNode->prev = temp;
            temp = newNode;
        }
    }
    printf("Doubly Linked List Created Successfully!\n");
}

// ---------------- 2. INSERT AT BEGINNING ----------------
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

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
    newNode->prev = temp;

    printf("Inserted at End!\n");
}

// ---------------- 4. INSERT AT POSITION ----------------
void insertAtPosition(int value, int pos) {
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid Position!\n");
        return;
    }

    struct Node* newNode = createNode(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

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

    if (head != NULL)
        head->prev = NULL;

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

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
    printf("Deleted from End!\n");
}

// ---------------- 7. DELETE BY VALUE ----------------
void deleteByValue(int value) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value Not Found!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

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

// ---------------- 10. DISPLAY FORWARD ----------------
void displayForward() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    printf("Forward: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---------------- 11. DISPLAY BACKWARD ----------------
void displayBackward() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// ---------------- 12. SORT LIST ----------------
void sortList() {
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

    printf("List Sorted Successfully!\n");
}

// ---------------- 13. REVERSE LIST ----------------
void reverseList() {
    struct Node* temp = NULL;
    struct Node* curr = head;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    printf("List Reversed Successfully!\n");
}

// ---------------- 14. UPDATE NODE ----------------
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

// ---------------- 15. FIND MAX ----------------
void findMax() {
    if (head == NULL) {
        printf("List Empty!\n");
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

// ---------------- 16. FIND MIN ----------------
void findMin() {
    if (head == NULL) {
        printf("List Empty!\n");
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

// ---------------- DELETE ENTIRE LIST ----------------
void deleteEntireList() {
    struct Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("Entire List Deleted!\n");
}

// ---------------- MAIN MENU ----------------
int main() {
    int choice, value, pos, n, oldValue, newValue;

    while (1) {
        printf("\n====== DOUBLY LINKED LIST MENU ======\n");
        printf("1.  Create Doubly Linked List\n");
        printf("2.  Insert at Beginning\n");
        printf("3.  Insert at End\n");
        printf("4.  Insert at Specific Position\n");
        printf("5.  Delete from Beginning\n");
        printf("6.  Delete from End\n");
        printf("7.  Delete by Value\n");
        printf("8.  Search Element\n");
        printf("9.  Count Nodes\n");
        printf("10. Display Forward\n");
        printf("11. Display Backward\n");
        printf("12. Sort List\n");
        printf("13. Reverse List\n");
        printf("14. Update Node Value\n");
        printf("15. Find Maximum\n");
        printf("16. Find Minimum\n");
        printf("17. Delete Entire List\n");
        printf("18. Exit\n");
        printf("====================================\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
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
                displayForward();
                break;

            case 11:
                displayBackward();
                break;

            case 12:
                sortList();
                break;

            case 13:
                reverseList();
                break;

            case 14:
                printf("Enter old value: ");
                scanf("%d", &oldValue);
                printf("Enter new value: ");
                scanf("%d", &newValue);
                updateNode(oldValue, newValue);
                break;

            case 15:
                findMax();
                break;

            case 16:
                findMin();
                break;

            case 17:
                deleteEntireList();
                break;

            case 18:
                printf("Exiting Program...\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
