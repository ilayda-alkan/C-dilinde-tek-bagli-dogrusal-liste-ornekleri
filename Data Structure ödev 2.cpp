#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* generateNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertSorted(struct Node** head, int data) {
    struct Node* newNode = generateNode(data);
    struct Node* current;

    if (*head == NULL || (*head)->data < data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;
        while (current->next != NULL && current->next->data > data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int randomNum = rand() % 100; // 0 ile 99 arasýnda rastgele sayýlar
        insertSorted(&head, randomNum);
    }

    printf("Siralanmis Liste : (buyukten kucuge dogru siralanir..):\n");
    printList(head);

    return 0;
}
