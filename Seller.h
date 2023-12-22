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
    void OutSeller() {
       cout << "���:" << this->GetName() << "  �������:" << this->GetPhone() << "  ��������:" << this->GetSalary() << "  id:" << seller_id << endl;
    }
    void SetSeller(Seller seller);
    void InSeller();
    Seller* GetSeller() { return this; }    //����������� ��������� �� ������
    int GetSellerId();
private:
    int salary;             //��������
    static int sellers_cntr;
    int seller_id;
};