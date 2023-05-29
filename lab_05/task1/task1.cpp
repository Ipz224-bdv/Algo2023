#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

struct Node {
    int data;
    struct Node* previous;
    struct Node* next;
};

void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->previous = NULL;
        *head = newNode;
    }
    else {
        struct Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
        newNode->previous = last;
    }
}

struct Node* findMin(struct Node* start) {
    struct Node* smallest = start;
    struct Node* current = start;

    while (current != NULL) {
        if (current->data < smallest->data) {
            smallest = current;
        }
        current = current->next;
    }

    return smallest;
}

void swapNodes(struct Node** a, struct Node** b) {
    int temp = (*a)->data;
    (*a)->data = (*b)->data;
    (*b)->data = temp;
}

void selectionSort(struct Node** head) {
    struct Node* start = *head;

    while (start != NULL) {
        struct Node* smallest = findMin(start);
        swapNodes(&start, &smallest);
        start = start->next;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    struct Node* head = NULL;

    int sizes[] = { 10, 100, 500, 1000, 2000, 5000, 10000 };
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];

        for (int j = 0; j < size; j++) {
            int data = rand() % 1000;
            addNode(&head, data);
        }

        printf("Size: %d\n", size);

        clock_t startTime, endTime;
        double cpuTimeUsed;

        startTime = clock();
        selectionSort(&head);
        endTime = clock();
        cpuTimeUsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

        printf("Time: %f s\n\n", cpuTimeUsed);

        struct Node* current = head;
        while (current != NULL) {
            struct Node* next = current->next;
            free(current);
            current = next;
        }
        head = NULL;
    }

    return 0;
}