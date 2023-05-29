#include <iostream>
#include <stdio.h>
#include <windows.h>

union Float {
    float x;
    struct bites {
        unsigned int x1 : 1;
        unsigned int x2 : 1;
        unsigned int x3 : 1;
        unsigned int x4 : 1;
        unsigned int x5 : 1;
        unsigned int x6 : 1;
        unsigned int x7 : 1;
        unsigned int x8 : 1;
        unsigned int x9 : 1;
        unsigned int x10 : 1;
        unsigned int x11 : 1;
        unsigned int x12 : 1;
        unsigned int x13 : 1;
        unsigned int x14 : 1;
        unsigned int x15 : 1;
        unsigned int x16 : 1;
        unsigned int x17 : 1;
        unsigned int x18 : 1;
        unsigned int x19 : 1;
        unsigned int x20 : 1;
        unsigned int x21 : 1;
        unsigned int x22 : 1;
        unsigned int x23 : 1;
        unsigned int x24 : 1;
        unsigned int x25 : 1;
        unsigned int x26 : 1;
        unsigned int x27 : 1;
        unsigned int x28 : 1;
        unsigned int x29 : 1;
        unsigned int x30 : 1;
        unsigned int x31 : 1;
        unsigned int x32 : 1;
    }bites;
    struct bytes
    {
        unsigned int byte1 : 8;
        unsigned int byte2 : 8;
        unsigned int byte3 : 8;
        unsigned int byte4 : 8;
    }bytes;
}fl;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Введіть число: ");
    scanf_s("%f", &fl.x);
    printf("Побітовий вивід числа: %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n", fl.bites.x32, fl.bites.x31, fl.bites.x30, fl.bites.x29, fl.bites.x28, fl.bites.x27, fl.bites.x26, fl.bites.x25, fl.bites.x24, fl.bites.x23, fl.bites.x22, fl.bites.x21, fl.bites.x20, fl.bites.x19, fl.bites.x18, fl.bites.x17, fl.bites.x16, fl.bites.x15, fl.bites.x14, fl.bites.x13, fl.bites.x12, fl.bites.x11, fl.bites.x10, fl.bites.x9, fl.bites.x8, fl.bites.x7, fl.bites.x6, fl.bites.x5, fl.bites.x4, fl.bites.x3, fl.bites.x2, fl.bites.x1);
    printf("Побайтовий вивід числа: %x%x%x%x\n", fl.bytes.byte4, fl.bytes.byte3, fl.bytes.byte2, fl.bytes.byte1);
    printf("Мантиса: %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n", fl.bites.x32, fl.bites.x31, fl.bites.x30, fl.bites.x29, fl.bites.x28, fl.bites.x27, fl.bites.x26, fl.bites.x25, fl.bites.x24, fl.bites.x23, fl.bites.x22, fl.bites.x21, fl.bites.x20, fl.bites.x19, fl.bites.x18, fl.bites.x17, fl.bites.x16, fl.bites.x15, fl.bites.x14, fl.bites.x13, fl.bites.x12, fl.bites.x11, fl.bites.x10, fl.bites.x9, fl.bites.x8, fl.bites.x7, fl.bites.x6, fl.bites.x5, fl.bites.x4, fl.bites.x3, fl.bites.x2, fl.bites.x1);
    printf("Характеристика: %d%d%d%d %d%d%d%d\n", fl.bites.x31, fl.bites.x30, fl.bites.x29, fl.bites.x28, fl.bites.x27, fl.bites.x26, fl.bites.x25, fl.bites.x24);
    printf("Знак: %d\n", fl.bites.x32);
    printf("Розмір структури: %d", sizeof(Float));
    return 0;
}