#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <time.h>


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct time
	{
		unsigned short hour : 5;
		unsigned short minute : 6;
		unsigned short second : 6;
	};
	struct date
	{
		time time;
		unsigned short wday : 3;
		unsigned short day : 5;
		unsigned short mounth : 4;
		unsigned short year : 7;
	};
	char week[7][12] = {
		"Понеділок", "Вівторок", "Середа", "Четвер", "П'ятниця", "Субота", "Неділя" };
	date now;
	now.time.hour = 9;
	now.time.minute = 30;
	now.time.second = 59;
	now.day = 06;
	now.mounth = 11;
	now.year = 22;
	now.wday = 3;
	tm ttime{};
	ttime.tm_sec = 12;
	ttime.tm_min = 10;



	ttime.tm_hour = 14;
	ttime.tm_mday = 29;
	ttime.tm_mon = 01;
	ttime.tm_year = 22;
	ttime.tm_wday = 6;
	printf("Час: %hu:%hu:%hu\n", now.time.hour, now.time.minute, now.time.second);
	printf("Дата: %s %hu.%hu.%hu\n", week[now.wday], now.day, now.mounth, now.year);
	printf("Розмір структури: %d\n", sizeof(date));
	printf("Час: %d:%d:%d\n", ttime.tm_hour, ttime.tm_min, ttime.tm_sec);
	printf("Дата: %s %d.%d.%d\n", week[ttime.tm_wday], ttime.tm_mday, ttime.tm_mon, ttime.tm_year);
	printf("Розмір структури: %d\n", sizeof(ttime));
}