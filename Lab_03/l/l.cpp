#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS

long long int findLargestNumber(int digits[], int size) {
    int i, j;
    long long int number = 0;

    // Сортування масиву в порядку спадання
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (digits[i] < digits[j]) {
                int temp = digits[i];
                digits[i] = digits[j];
                digits[j] = temp;
            }
        }
    }

    // Обчислення найбільшого можливого числа з даних цифр
    for (i = 0; i < size; i++) {
        number = number * 8 + digits[i];
    }

    return number;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int digits[20];
    int i, size;

    printf("Введіть розмір масиву (не більше 20): ");
    scanf_s("%d", &size);
    if (size > 20 || size <= 0) {
        printf("Розмір масиву повинен бути в межах від 1 до 20!\n");
        return 1;
    }

    // Генерація масиву випадкових цифр вісімкової системи числення
    srand(time(NULL));
    printf("Цифри вісімкової системи числення: ");
    for (i = 0; i < size; i++) {
        digits[i] = rand() % 8; // Генерація випадкової цифри від 0 до 7
        printf("%d ", digits[i]);
    }
    printf("\n");

    // Обчислення найбільшого можливого числа
    long long int largestNumber = findLargestNumber(digits, size);
    printf("Найбільше можливе число: %lld\n", largestNumber);

    return 0;
}
