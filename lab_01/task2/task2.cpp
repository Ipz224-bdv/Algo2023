#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdio.h>

union Short {
    short num;
    struct 
    {
        unsigned short val : 15;
        unsigned short sign : 1;
    } bits;
};


int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    union Short input;
    printf("З використанням структур даних\n");
    printf("Введіть ціле число типу signed short: ");
    scanf_s("%hd", &input.num);
    if (input.num == 0) 
    {
        printf("Число нейтральне, а значення: %hu\n", input.num);
    }
    else if (input.bits.sign) 
    {
        printf("Число від'ємне, а значення: %hu\n", -input.num);
    }
    else 
    {
        printf("Число додатнє, а значення: %hu\n", input.num);
    }

    short num;

    printf("\nЗ використанням логічних операцій\n");
    printf("Введіть ціле число типу signed short: ");
    scanf_s("%hd", &num);
    if (num == 0) 
    {
        printf("Число нейтральне, а значення: %hd\n", num);
    }
    else if (num & (1 << 15)) 
    {
        printf("Число від'ємне, а значення: %hd\n", ~(num - 1));
    }
    else 
    {
        printf("Число додатнєі, а значення: %hd\n", num);
    }

    return 0;
}