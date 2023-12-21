#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "Input.h"
#include "Human.h"

class Seller : public Human
{
public:
    Seller();
    Seller(std::string name);
    Seller(std::string name, std::string phone);
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
       cout << "���:" << this->GetName() << "  �������:" << this->GetPhone() << "  ��������:" << this->GetSalary() << endl;
    }
    void SetSeller(Seller seller);
    void InSeller();
    Seller* GetSeller() { return this; }    //����������� ��������� �� ������
private:
    int salary;             //��������
    static int sellers_cntr;

};