#include <iostream>
#include <Windows.h>

typedef int elemtype;
struct elem {
    elemtype value;
    struct elem* next;
    struct elem* prev;
};
struct myList {
    struct elem* head;
    struct elem* tail;
    int size;
};
typedef struct elem cNode;
typedef struct myList cList;

cList* createList() {
    cList* list = new cList;
    list->size = 0;
    list->head = list->tail = NULL;
    return list;
}

bool isEmptyList(cList* list) {
    return ((list->head == NULL) || (list->tail == NULL));
}

void deleteList(cList* list) {
    cNode* head = list->head;
    cNode* next = NULL;
    while (head) {
        next = head->next;
        delete head;
        head = next;
    }
    delete list;
    list = NULL;
}

int pushFront(cList* list, elemtype* data) {
    cNode* node = new cNode;
    if (!node) {
        return(-1);
    }
    node->value = *data;
    node->next = list->head;
    node->prev = NULL;
    if (!isEmptyList(list)) {
        list->head->prev = node;
    }
    else {
        list->tail = node;
    }
    list->head = node;
    list->size++;
    return(0);
}

int popFront(cList* list, elemtype* data) {
    cNode* node;
    if (isEmptyList(list)) {
        return(-2);
    }
    node = list->head;
    list->head = list->head->next;
    if (!isEmptyList(list)) {
        list->head->prev = NULL;
    }
    else {
        list->tail = NULL;
    }
    *data = node->value;
    list->size--;
    delete node;
    return(0);
}

int pushBack(cList* list, elemtype* data) {
    cNode* node = new cNode;
    if (!node) {
        return(-3);
    }
    node->value = *data;
    node->next = NULL;
    node->prev = list->tail;
    if (!isEmptyList(list)) {
        list->tail->next = node;
    }
    else {
        list->head = node;
    }
    list->tail = node;
    list->size++;
    return(0);
}

int popBack(cList* list, elemtype* data) {
    cNode* node = NULL;
    if (isEmptyList(list)) {
        return(-4);
    }
    node = list->tail;
    list->tail = list->tail->prev;
    if (!isEmptyList(list)) {
        list->tail->next = NULL;
    }
    else {
        list->head = NULL;
    }
    *data = node->value;
    list->size--;
    delete node;
    return(0);
}

cNode* getNode(cList* list, int index) {
    cNode* node = NULL;
    int i;
    if (index >= list->size) {
        return (NULL);
    }
    if (index < list->size / 2) {
        i = 0;
        node = list->head;
        while (node && i < index) {
            node = node->next;
            i++;
        }
    }
    else {
        i = list->size - 1;
        node = list->tail;
        while (node && i > index) {
            node = node->prev;
            i--;
        }
    }
    return node;
}

void printValue(elemtype* data) {
    std::cout << *data << " ";
}

void printList(cList* list, void (*func)(elemtype*)) {
    cNode* node = list->head;
    if (isEmptyList(list)) {
        return;
    }
    while (node) {
        func(&node->value);
        node = node->next;
    }
}

int deleteNode(cList* list, int index, elemtype* data) {
    if (index < 0 || index >= list->size) {
        return (-1);
    }
    cNode* node = getNode(list, index);
    if (node == NULL) {
        return (-2);
    }
    if (node == list->head) {
        return popFront(list, data);
    }
    if (node == list->tail) {
        return popBack(list, data);
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    *data = node->value;
    delete node;
    list->size--;
    return (0);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cList* list = createList();

    int action = -1;
    while (action != 0) {
        std::cout << "1. Додати елемент у початок списку" << std::endl;
        std::cout << "2. Додати елемент у кінець списку" << std::endl;
        std::cout << "3. Видалити елемент з початку списку" << std::endl;
        std::cout << "4. Видалити елемент з кінця списку" << std::endl;
        std::cout << "5. Видалити елемент за індексом" << std::endl;
        std::cout << "6. Вивести список на екран" << std::endl;
        std::cout << "0. Вихід" << std::endl;
        std::cout << "Введіть номер дії: ";
        std::cin >> action;

        switch (action) {
        case 1: {
            elemtype data;
            std::cout << "Введіть значення: ";
            std::cin >> data;
            pushFront(list, &data);
            std::cout << "Елемент успішно додано!" << std::endl;
            break;
        }
        case 2: {
            elemtype data;
            std::cout << "Введіть значення: ";
            std::cin >> data;
            pushBack(list, &data);
            std::cout << "Елемент успішно додано!" << std::endl;
            break;
        }
        case 3: {
            elemtype data;
            int res = popFront(list, &data);
            if (res == 0) {
                std::cout << "Видалено елемент зі значенням " << data << std::endl;
            }
            else {
                std::cout << "Список порожній!" << std::endl;
            }
            break;
        }
        case 4: {
            elemtype data;
            int res = popBack(list, &data);
            if (res == 0) {
                std::cout << "Видалено елемент зі значенням " << data << std::endl;
            }
            else {
                std::cout << "Список порожній!" << std::endl;
            }
            break;
        }
        case 5: {
            elemtype data;
            int index;
            std::cout << "Введіть номер позиції для видалення: ";
            std::cin >> index;
            std::cout << "Введіть значення: ";
            std::cin >> data;
            if (deleteNode(list, index, &data) == 0) {
                std::cout << "Елемент успішно вставлено!" << std::endl;
            }
            else {
                std::cout << "Помилка вставки елемента!" << std::endl;
            }
            break;
        }
        case 6: {
            std::cout << "Список:" << std::endl;
            printList(list, &printValue);
            std::cout << std::endl;
            break;
        }
        case 0: {
            break;
        }
        default: {
            std::cout << "Некоректний ввід! Введіть число від 0 до 5" << std::endl;
            break;
        }
        }
    }
    deleteList(list);
    return 0;
}