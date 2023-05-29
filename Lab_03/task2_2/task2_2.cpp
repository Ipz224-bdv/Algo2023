#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void sort_array(int* array, int size) {
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (array[i] < array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    for (int i = 1; i < 61; i++)
    {
        printf("%d\n", i);
    }
    return 0;
}
