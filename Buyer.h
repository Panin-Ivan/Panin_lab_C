#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#pragma once
#include "Input.h"
#include "Human.h"
class Buyer : public Human
{
public:
    Buyer() {}
    Buyer(std::string name) {
        SetName(name);
        buyers_cntr++;
    }
    Buyer(std::string name, std::string phone) {
        this->SetName(name);
        this->SetName(phone);
        buyers_cntr++;
    }
    void SetBuyer(Buyer buyer) {
        this->SetName(buyer.GetName());
        this->SetPhone(buyer.GetPhone());
    }
    Buyer GetBuyer() { return *this; }
    void OutBuyer() {
        cout << "Имя:" << this->GetName() << "  Телефон:" << this->GetPhone() << endl;
    }
    void InBuyer();
    static int& GetBuyer_cntr() { return buyers_cntr; }     //возвращение адреса статической переменной
    static void SetBuyer_cntr(int n) { buyers_cntr = n; }
private:
    static int buyers_cntr;
};