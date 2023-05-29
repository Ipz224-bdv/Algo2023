#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addNode(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    }
    else {
        struct Node* currNode = *headRef;
        while (currNode->next != NULL) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
        newNode->prev = currNode;
    }
}

void deleteNode(struct Node** headRef, int data) {
    struct Node* currNode = *headRef;
    while (currNode != NULL && currNode->data != data) {
        currNode = currNode->next;
    }
    if (currNode == NULL) {
        printf("Цього елементу немає у списку\n");
        return;
    }
    if (currNode == *headRef) {
        *headRef = currNode->next;
    }
    if (currNode->prev != NULL) {
        currNode->prev->next = currNode->next;
    }
    if (currNode->next != NULL) {
        currNode->next->prev = currNode->prev;
    }
    free(currNode);
}

void displayList(struct Node* head) {
    printf("Список: ");
    struct Node* currNode = head;
    while (currNode != NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n\n");
}

void destroyList(struct Node** headRef) {
    struct Node* currNode = *headRef;
    while (currNode != NULL) {
        struct Node* nextNode = currNode->next;
        free(currNode);
        currNode = nextNode;
    }
    *headRef = NULL;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    struct Node* head = NULL;
    int choice, data;
    do {
        printf("1. Створити список\n");
        printf("2. Додати елемент\n");
        printf("3. Видалити елемент\n");
        printf("4. Вивести список на дисплей\n");
        printf("5. Знищити список\n");
        printf("0. Закрити\n");
        printf("Оберіть дію: ");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            printf("Введіть елемент 1: ");
            scanf_s("%d", &data);
            addNode(&head, data);
            printf("Введіть елемент 2: ");
            scanf_s("%d", &data);
            addNode(&head, data);
            printf("Введіть елемент 3: ");
            scanf_s("%d", &data);
            addNode(&head, data);
            printf("\n");
            break;
        case 2:
            printf("Введіть елемент: ");
            scanf_s("%d", &data);
            addNode(&head, data);
            printf("\n");
            break;
        case 3:
            printf("Введіть елемент: ");
            scanf_s("%d", &data);
            deleteNode(&head, data);
            printf("\n");
            break;
        case 4:
            displayList(head);
            break;
        case 5:
            destroyList(&head);
            printf("\n");
            break;
        case 0:
            break;
        default:
            printf("Немає такої дії\n");
            printf("\n");
        }
    } while (choice != 0);
    return 0;
}