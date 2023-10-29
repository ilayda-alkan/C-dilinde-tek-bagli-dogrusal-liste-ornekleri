#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Kayit yapisi tanimlanir
struct Record {
    char name[50];
    int age;
    struct Record* next;
};

// Yeni bir kayit olusturan fonksiyon
struct Record* createRecord(const char* name, int age) {
    struct Record* newRecord = (struct Record*)malloc(sizeof(struct Record));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->next = NULL;
    return newRecord;
}

// Kaydi listeye ekleyen fonksiyon
void insertRecord(struct Record** head, const char* name, int age) {
    struct Record* newRecord = createRecord(name, age);
    newRecord->next = *head;
    *head = newRecord;
}

// En uzun ismi ve uzunlugunu bulan fonksiyon
void findLongestNameRecord(struct Record* head, char** longestName, int* longestNameLength) {
    if (head == NULL) {
        printf("Liste bos.\n");
        *longestName = NULL;
        *longestNameLength = 0;
        return;
    }

    struct Record* current = head;
    *longestName = current->name;
    *longestNameLength = strlen(current->name);

    while (current != NULL) {
        int currentNameLength = strlen(current->name);
        if (currentNameLength > *longestNameLength) {
            *longestName = current->name;
            *longestNameLength = currentNameLength;
        }
        current = current->next;
    }
}

int main() {
    struct Record* head = NULL;

    insertRecord(&head, "MehmetAli", 30);
    insertRecord(&head, "Ayse", 25);
    insertRecord(&head, "Abdurrahmangazi", 40);
    insertRecord(&head, "Zehra", 35);
    insertRecord(&head, "Aliosman", 28);

    char* longestName;
    int longestNameLength;

    findLongestNameRecord(head, &longestName, &longestNameLength);

    if (longestName) {
        printf("En uzun isim: %s\n", longestName);
        printf("Uzunluk : %d\n" , longestNameLength);
    } else {
        printf("Liste bos.\n");
    }

    return 0;
}
