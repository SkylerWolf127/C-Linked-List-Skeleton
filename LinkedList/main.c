#include <stdio.h>
#include <stdlib.h>

//Node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteNode(Node** head, int data) {
    Node* temp = *head;
    if (temp == NULL) return;

    if (temp->data == data && temp == *head) {
        *head = (*head)->next;
        if ((*head) != NULL) {
            (*head)->prev = NULL;
        } else {
            *head = NULL;
        }
    }

    else if (temp->data == data) {
        Node* nextNode = temp->next;
        temp->next = nextNode->next;
        if (nextNode->next != NULL) {
            nextNode->next->prev = temp;
        } else {
            (*head)->prev = temp;
        }
        free(temp);
    }

    else if (temp->data == data && temp->next == NULL) {
        Node* prevNode = temp->prev;
        prevNode->next = NULL;
        free(temp);
    }
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);

    printf("Doubly Linked List: ");
    printList(head);

    deleteNode(&head, 10);

    printf("Updated Doubly Linked List: ");
    printList(head);

    return 0;
}
