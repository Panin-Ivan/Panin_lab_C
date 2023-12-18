#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <stdio.h>
//#include <conio.h>
#include <string>
using namespace std;
#pragma once
//ф-я ввода строки
void stringin(int maxlength, std::string* string, const char* message);
void intin(int* value, int lower_limit, int upper_limit, const char* message);