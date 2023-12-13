#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#pragma once
//ф-я ввода строки
void stringin(int maxlength, char* string, const char* message);
void intin(int* value, int lower_limit, int upper_limit, const char* message);