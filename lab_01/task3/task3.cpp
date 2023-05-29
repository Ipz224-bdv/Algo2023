#include <iostream>
#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    signed char a = 5 + 127;
    signed char b = 2 - 3;
    signed char c = -120 - 34;
    unsigned char d = -5;
    signed char e = 56 & 38;
    signed char f = 56 | 38;

    printf("5 + 127 = %d\n", a);
    printf("2 - 3 = %d\n", b);
    printf("-120 - 34 = %d\n", c);
    printf("-5 = %d\n", d);
    printf("56 & 38 = %d\n", e);
    printf("56 | 38 = %d\n", f);
    getchar();

    return 0;

}