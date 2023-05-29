#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <time.h>

int factorial(int a) {
    if (a == 0 || a == 1) {
        return 1;
    }
    else {
        return a * factorial(a - 1);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a;

    printf("Введіть число: ");
    scanf("%d", &a);

    clock_t start = clock();

    if (a < 0 || a > 20) {
        printf("Невірне число\n");
        return 1;
    }

    printf("%d! = %d\n", a, factorial(a));

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Час виконання: %f секунд\n", time_spent);

    return 0;
}
