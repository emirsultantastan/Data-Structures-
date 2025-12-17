#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

void insertBaslangic(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*head);
    (*head) = newNode;
}


void insertSon(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (last->next != NULL) last = last->next;
    last->next = newNode;
}


void insertOrta(struct Node* prevNode, int newData) {
    if (prevNode == NULL) return;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}


void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}


void printList(struct Node* node) {
    while (node != NULL) {
        printf(" %d ->", node->data);
        node = node->next;
    }
    printf(" NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 9);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 15);
    insertAfter(head->next, 12); 

    printf("Bağlı Liste:");
    printList(head);

    deleteNode(&head, 9);
    printf("9 Silindikten Sonra:");
    printList(head);

    return 0;
}