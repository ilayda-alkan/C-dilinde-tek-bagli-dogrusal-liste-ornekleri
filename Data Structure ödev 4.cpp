#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ogrenci yapısı tanımlanır
struct Student {
    char name[50];
    int id;
    struct Student* next;
};

// Yeni bir ogrenci olusturan fonksiyon
struct Student* createStudent(const char* name, int id) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->next = NULL;
    return newStudent;
}
// Ogrenci kaydini liste basina ekleyen fonksiyon
void insertStudent(struct Student** head, const char* name, int id) {
    struct Student* newStudent = createStudent(name, id);
    newStudent->next = *head;
    *head = newStudent;
}

// İstenen ogrenciyi ada göre arayan fonksiyon
struct Student* searchStudentByName(struct Student* head, const char* name) {
    struct Student* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current; // Ýstenen adý bulduk
        }
        current = current->next;
    }
    return NULL; // Ýstenen adý bulamadýk
}

// Ogrenci bilgilerini ekrana yazdiran fonksiyon
void printStudent(struct Student* student) {
    if (student == NULL) {
        printf("Ogrenci kaydi bulunamadi.\n");
    } else {
        printf("Ogrenci Adi: %s\nOgrenci Numarasi: %d\n", student->name, student->id);
    }
}

int main() {
    struct Student* head = NULL;

    insertStudent(&head, "MehmetAli", 101);
    insertStudent(&head, "Aysenur", 102);
    insertStudent(&head, "Abdurrahmangazi", 103);
    insertStudent(&head, "Zehra", 104);
    insertStudent(&head, "Aliosman", 105);

    char searchName[50];
    printf("Aranacak ogrencinin adini girin: ");
    scanf("%s", searchName);

    struct Student* foundStudent = searchStudentByName(head, searchName);
    printStudent(foundStudent);

    return 0;
}
