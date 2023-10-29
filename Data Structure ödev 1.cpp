#include <stdio.h>
#include <stdlib.h>

// Tek bagli liste dügümleri için yapi tanimlanir
struct Node {
    int data;
    struct Node* next;
};

// Yeni bir düğüm oluşturan fonksiyon
struct Node* generateNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* generateSeparatedList() {
    struct Node* head = NULL; // Liste başı
    struct Node* oddList = NULL; // Tek sayıların listesi
    struct Node* evenList = NULL; // Çift sayıların listesi
    int input;

    printf("Klavyeden sayilari Giriniz: (-1 girdiginizde cikis yapacaktir):\n");

    while (1) {
        scanf("%d", &input);

        if (input == -1) {
            break;
        }

        struct Node* newNode = generateNode(input);
        
        if (input % 2 == 1) {
            // Tek sayilari basa ekle
            newNode->next = oddList;
            oddList = newNode;
        } else {
            // Çift sayilari sona ekle
            if (evenList == NULL) {
                evenList = newNode;
            } else {
                struct Node* temp = evenList;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }

    // Tek ve çift sayi listelerini birlestir
    struct Node* temp = oddList;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    if (temp != NULL) {
        temp->next = evenList;
    } else {
        oddList = evenList;
    }

    head = oddList;
    
    return head;
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
    struct Node* head = generateSeparatedList();

    printf("Girdiginiz sayilarin listesi : (tekler basta ciftler sonda olucak şekilde siralanir):\n");
    printList(head);

    return 0;
}
