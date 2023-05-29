#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>

// Константи для конгруентного методу
#define A 1664525
#define C 1013904223
#define M 4294967296
#define N 20000
#define RANGE 150

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i, j, k, freq[RANGE] = { 0 };
    double prob[RANGE], mean, variance, std_dev;
    unsigned int x = 1;

    // Генерація
    for (i = 0; i < N; i++) {
        x = (A * x + C) % M;
        int value = x % RANGE;
        freq[value]++;
    }

    // Розрахунок частоти інтервалів, статистичних ймовірностей, математичного сподівання, дисперсії, та середньоквадратичного відхилення
    mean = 0.0;
    for (j = 0; j < RANGE; j++) {
        prob[j] = (double)freq[j] / N;
        mean += prob[j] * j;
    }
    variance = 0.0;
    for (k = 0; k < RANGE; k++) {
        variance += prob[k] * pow(k - mean, 2);
    }
    std_dev = sqrt(variance);

    // Виведення результату
    printf("Частоти інтервалів\tСтатистичні ймовірності\n");
    for (i = 0; i < RANGE; i++) {
        printf("%d\t\t\t%.6f\n", freq[i], prob[i]);
    }
    printf("\nМатематичне сподівання: %.6f\n", mean);
    printf("Дисперсія: %.6f\n", variance);
    printf("Середньоквадратичне відхилення: %.6f\n", std_dev);

    return 0;
}