#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#pragma once
#include "Input.h"
#include "Human.h"

template <typename T>
class Payment
{
public:
    Payment() {
        accaunt_id = "";
        int sum = 0;
    }
    Payment(T accaunt_id, int sum) :
        accaunt_id {accaunt_id }, sum{ sum } {}
    void print(){
        cout << "id:" << accaunt_id << "  Сумма:" << sum << endl;
    }
private:
    T accaunt_id;       // id счета
    int sum;            // сумма
};