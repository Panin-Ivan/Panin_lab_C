#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "Input.h"
#include "Human.h"

class Seller : public Human
{
public:
    Seller();
    Seller(char* name);
    Seller(char* name, char* phone);
    void SetSalary(int salary) {
        this->salary = salary;
    }
    int GetSalary() {
        return salary;
    }
    static int GetSellers_cntr() {
        return sellers_cntr;
    }
    static void SetSellers_cntr(int n) {
        sellers_cntr = n;
    }
    void OutSeller() {
        printf("%-30s|%-14s|%-6d\n", this->GetName(), this->GetPhone(), this->GetSalary());
    }
    void SetSeller(Seller seller);
    void InSeller();
    Seller GetSeller() { return *this; }
private:
    int salary;             //Зарплата
    static int sellers_cntr;

};