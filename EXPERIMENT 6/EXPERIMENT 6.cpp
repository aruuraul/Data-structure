#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* prev = NULL;

   
    if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        return;
    }

 
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

 
    if (current == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }


    prev->next = current->next;
    free(current);
}


void traverseList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // 
    int n, data, key;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    traverseList(head);

    printf("Enter the value to delete: ");
    scanf("%d", &key);
    deleteNode(&head, key);

    traverseList(head);

    return 0;
}
